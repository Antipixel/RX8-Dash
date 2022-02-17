#include <Arduino.h>
#include <WiFi.h>
#include <AsyncUDP.h>

#include "rx8cluster.h"
#include "wificredentials.h"
#include "forza/forzadata.h"

#define SERIAL_BAUD 115200
#define DATA_OUT_PORT 8855
#define MESSAGE_FREQUENCY 15
#define WIFI_CONNECT_TIMEOUT 15000

RX8Cluster cluster(GPIO_NUM_5, GPIO_NUM_4);
CAN_device_t CAN_cfg;
AsyncUDP udp;

/**
 * 
 * @param packet the UDP packet containing the Forza telemetry data
 */
void onDatagramReceived(AsyncUDPPacket packet)
{
    ForzaData *data = (ForzaData*)packet.data();

    // Check the gameplay state. This flag is set while driving,
    // if game is paused, in a menu, etc. this flag will not be set
    // and the data contained in this packet will be empty/invalid 
    if (!data->enabled)
        return;

    // Set RPM and vehicle speeds. The speedometer maxes out at 299 km/h,
    // any attempt to display a speed over in this results in the display
    // reverting back to zero. The tachometer maxes out at about 11.2k RPM,
    // conveniently just as it begins to obscure the speedometer readout
    cluster.setEngineSpeed(data->currentRPM);
    cluster.setVehicleSpeed(data->speed);

    // Set the gear display. Only values possible from Forza are reverse
    // or the numeric gear value. The RX8 cluster is only capable of displaying
    // numeric gear values up to 6, any specified value over this will cap at 6
    cluster.setGearPosition(Transmission::getGearForPosition(data->gear));

    // Though Forza doesn't provide data for the state of ABS, we can make
    // a surprisingly accurate estimate using the speed of the vehicle, the 
    // position of the brake pedal and the speed of each of the wheels
    bool vehicleMoving = data->speed > 1.0;
    bool brakingHard = data->brakePedalPosition > 220;
    bool wheelsLocked = data->wheelRotationSpeed.getTotal() < 1.0;

    // If the vehicle is still in motion with the brake pedal to the floor; yet the wheel
    // speed isn't at or very near to zero, we can take a guess at this meaning the ABS 
    // is active and doing its job of preventing the brakes from locking up completely
    cluster.setAntilockLight(vehicleMoving && brakingHard && !wheelsLocked);
    cluster.setHandbrakeLight(data->handBrake);
}

uint8_t attemptWiFiConnect(const char *ssid, const char *pass)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
        
    return WiFi.waitForConnectResult();
}

void initialiseNetwork()
{
    bool connected = false;
    do
    {
        // Attempt to connect to the network wirelessly using
        // the provided SSID and password
        uint8_t status = attemptWiFiConnect(WIFI_SSID, WIFI_PASS);

        // If the returned status indicates a successful connection,
        // print the devices IP address and set the connected flag
        if (status == WL_CONNECTED)
        {
            String ipAddr = WiFi.localIP().toString();
            Serial.printf("Connected to network - IP: %s\n", ipAddr.c_str());
            connected = true;
        }
        else
        {
            // If any other result was returned, print and error message
            // and reattempt a connection after a timeout delay
            Serial.printf("Unable to connect to network, reattempting in %dms", WIFI_CONNECT_TIMEOUT);
            delay(WIFI_CONNECT_TIMEOUT);
        }
    }
    while (!connected);

    // If we're able to listen on the required port, attach a listener
    // to the UDP object. This will trigger an event each time a packet
    // is received from Forzas data out function
    if (udp.listen(DATA_OUT_PORT)) {
        udp.onPacket(onDatagramReceived);
    }
}

void setup() 
{
    Serial.begin(SERIAL_BAUD);
    initialiseNetwork();

    cluster.begin();
}

void loop() 
{
    cluster.update();
    delay(MESSAGE_FREQUENCY);
}
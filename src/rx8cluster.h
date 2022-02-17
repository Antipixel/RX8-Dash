#ifndef RX8CLUSTER_H_
#define RX8CLUSTER_H_

#include <Arduino.h>
#include <ESP32CAN.H>

#include "messages/message.h"
#include "messages/speed.h"
#include "messages/brakes.h"
#include "messages/steering.h"
#include "messages/transmission.h"
#include "messages/cruisecontrol.h"
#include "messages/enginestatus.h"

#define MESSAGE_COUNT 6

class RX8Cluster
{
private:
    gpio_num_t tx;
    gpio_num_t rx;

    Speed speed;
    Brakes brakes;
    Steering steering;
    Transmission trans;
    CruiseControl cruise;
    EngineStatus engineStatus;

    void initialiseCAN();
    void sendCANMessage(Message &message);
public:
    RX8Cluster(gpio_num_t tx, gpio_num_t rx);
    void begin();
    void update();

    void setEngineSpeed(float rpmRaw);
    void setVehicleSpeed(float speedMps);
    void setDSCEngaged(bool state);
    void setAntilockLight(bool state);
    void setHandbrakeLight(bool state);
    void setTractionLight(bool state, bool flashing);
    void setSteeringLight(bool state);
    void setGearPosition(Gear gear);
    void setTransmissionWarningLight(bool warning);
    void setCruiseLight(bool status);
    void setCruiseMainLight(bool status);
    void setCoolantTemperature(float value);
    void setOilPressure(bool state);
    void setOilLevelLight(bool state);
    void setCheckEngineLight(bool state);
    void setOverheatingLight(bool state);
    void setBatteryLight(bool state);
};

#endif
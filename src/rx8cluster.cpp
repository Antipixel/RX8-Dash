#include "rx8cluster.h"

RX8Cluster::RX8Cluster(gpio_num_t tx, gpio_num_t rx)
{
    this->tx = tx;
    this->rx = rx;
}

void RX8Cluster::initialiseCAN()
{
    CAN_cfg.speed = CAN_SPEED_500KBPS;
    CAN_cfg.tx_pin_id = this->tx;
    CAN_cfg.rx_pin_id = this->rx;
    CAN_cfg.rx_queue = xQueueCreate(10, sizeof(CAN_frame_t));

    ESP32Can.CANInit();
}

void RX8Cluster::sendCANMessage(Message &message)
{
    // Setup a CAN frame using the id and size of
    // the message. Only standard frames are required.
    CAN_frame_t frame;
    frame.MsgID = message.getID();
    frame.FIR.B.DLC = message.getSize();
    frame.FIR.B.FF = CAN_frame_std;

    // Copy the contents of the message to the CAN frame 
    memcpy(frame.data.u8, message.getData(), message.getSize());

    // Write the CAN frame to the bus
    ESP32Can.CANWriteFrame(&frame);
}

void RX8Cluster::begin()
{
    this->initialiseCAN();
}    


void RX8Cluster::update()
{
    this->sendCANMessage(this->speed);
    this->sendCANMessage(this->brakes);
    this->sendCANMessage(this->steering);
    this->sendCANMessage(this->trans);
    this->sendCANMessage(this->cruise);
    this->sendCANMessage(this->engineStatus);
}

void RX8Cluster::setEngineSpeed(float rpmRaw)
{
    this->speed.setEngineSpeed(rpmRaw);
}

void RX8Cluster::setVehicleSpeed(float speedMps)
{
    this->speed.setVehicleSpeed(speedMps);
}

void RX8Cluster::setDSCEngaged(bool state)
{
    this->brakes.setDSCEngaged(state);
}

void RX8Cluster::setAntilockLight(bool state)
{
    this->brakes.setAntilockLight(state);
}

void RX8Cluster::setHandbrakeLight(bool state)
{
    this->brakes.setHandbrakeLight(state);
}

void RX8Cluster::setTractionLight(bool state, bool flashing)
{
    this->brakes.setTractionLight(state, flashing);
}

void RX8Cluster::setSteeringLight(bool state)
{
    this->steering.setSteeringLight(state);
}

void RX8Cluster::setGearPosition(Gear gear)
{
    this->trans.setGear(gear);
}

void RX8Cluster::setTransmissionWarningLight(bool warning)
{
    this->trans.setWarningLight(warning);
}

void RX8Cluster::setCruiseLight(bool status)
{
    this->cruise.setCruiseLight(status);
}

void RX8Cluster::setCruiseMainLight(bool status)
{
    this->cruise.setCruiseMainLight(status);
}

void RX8Cluster::setCoolantTemperature(float value)
{
    this->engineStatus.setCoolantTemperature(value);
}

void RX8Cluster::setOilPressure(bool state)
{
    this->engineStatus.setOilPressure(state);
}

void RX8Cluster::setOilLevelLight(bool state)
{
    this->engineStatus.setOilLevelLight(state);
}

void RX8Cluster::setCheckEngineLight(bool state)
{
    this->engineStatus.setCheckEngineLight(state);
}

void RX8Cluster::setOverheatingLight(bool state)
{
    this->engineStatus.setOverheatingLight(state);
}

void RX8Cluster::setBatteryLight(bool state)
{
    this->engineStatus.setBatteryLight(state);
}

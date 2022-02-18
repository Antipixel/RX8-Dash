#include "enginestatus.h"

EngineStatus::EngineStatus() : Message(ENG_STAT_MSG_ID, ENG_STAT_MSG_SIZE)
{
    this->setCoolantTemperature(DEFAULT_COOLANT_TEMP);
    this->setOilPressure(true);
    this->setOilLevelLight(false);
    this->setCheckEngineLight(false);
    this->setOverheatingLight(false);
    this->setBatteryLight(false);
}

void EngineStatus::setCoolantTemperature(float value)
{
    // Cap the value to 1.0 (100%)
    if (value > 1.0)
        value = 1.0;

    // Convert the value from a percentage to a byte
    this->data[0] = (uint8_t) (255 * value);
}

void EngineStatus::setOilPressure(bool state)
{
    this->setDataBit(4, 0, state);
}

void EngineStatus::setOilLevelLight(bool state)
{
    this->setDataBit(6, 7, state);
}

void EngineStatus::setCheckEngineLight(bool state)
{
    this->setDataBit(5, 6, state);
}

void EngineStatus::setOverheatingLight(bool state)
{
    this->setDataBit(6, 2, state);
}

void EngineStatus::setBatteryLight(bool state)
{
    this->setDataBit(6, 6, state);
}
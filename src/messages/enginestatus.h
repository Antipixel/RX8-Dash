#ifndef STATUS_A_
#define STATUS_A_

#include "message.h"
#include <Arduino.h>

#define ENG_STAT_MSG_ID 0x420
#define ENG_STAT_MSG_SIZE 7

#define DEFAULT_COOLANT_TEMP 150

class EngineStatus: public Message
{
public:
    EngineStatus();
    void setCoolantTemperature(float value);
    void setOilPressure(bool state);
    void setOilLevelLight(bool state);
    void setCheckEngineLight(bool state);
    void setOverheatingLight(bool state);
    void setBatteryLight(bool state);
};

#endif
#ifndef CRUISE_CONTROL_H_
#define CRUISE_CONTROL_H_

#include "message.h"
#include <Arduino.h>

#define CRUISE_MSG_ID 0x650
#define CRUISE_MSG_SIZE 1

class CruiseControl: public Message
{
public:
    CruiseControl();
    void setCruiseLight(bool status);
    void setCruiseMainLight(bool status);
};

#endif
#ifndef STATUS_B_
#define STATUS_B_

#include "message.h"
#include <Arduino.h>

#define BRAKES_MSG_ID 0x212
#define BRAKES_MSG_SIZE 6

class Brakes: public Message
{
public:
    Brakes();
    void setDSCEngaged(bool state);
    void setAntilockLight(bool state);
    void setHandbrakeLight(bool state);
    void setTractionLight(bool state, bool flashing);
};

#endif
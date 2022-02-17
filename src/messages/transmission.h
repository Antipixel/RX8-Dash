#ifndef TRANSMISSION_H_
#define TRANSMISSION_H_

#include "message.h"

#define TRANS_MSG_ID 0x231
#define TRANS_MSG_SIZE 2

#define MANUAL_FLAG 0x0080
#define WARNING_ON 0x0040
#define WARNING_OFF 0x0000

#define GEAR_PARK 0x0100
#define GEAR_REVERSE 0x0200
#define GEAR_NEUTRAL 0x0300
#define GEAR_DRIVE 0x0400

#define GEAR_FIRST 0x1000
#define GEAR_SECOND 0x2000
#define GEAR_THIRD 0x3000
#define GEAR_FOURTH 0x4000
#define GEAR_FIFTH 0x5000
#define GEAR_SIXTH 0x6000

enum Gear: uint16_t
{
    PARK = GEAR_PARK,
    REVERSE = GEAR_REVERSE,
    NEUTRAL = GEAR_NEUTRAL,
    DRIVE = GEAR_DRIVE,
    M_1 = GEAR_FIRST | MANUAL_FLAG,
    M_2 = GEAR_SECOND | MANUAL_FLAG,
    M_3 = GEAR_THIRD | MANUAL_FLAG,
    M_4 = GEAR_FOURTH | MANUAL_FLAG,
    M_5 = GEAR_FIFTH | MANUAL_FLAG,
    M_6 = GEAR_SIXTH | MANUAL_FLAG
};

class Transmission: public Message
{
public:
    Transmission();
    void setGear(Gear gear);
    void setWarningLight(bool warning);
    static Gear getGearForPosition(uint8_t position);
};


#endif
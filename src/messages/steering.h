#ifndef STEERING_H_
#define STEERING_H_

#include "message.h"
#include <Arduino.h>

#define STEER_MSG_ID 0x300
#define STEER_MSG_SIZE 8

class Steering: public Message
{
public:
    Steering();
    void setSteeringLight(bool state);
};

#endif
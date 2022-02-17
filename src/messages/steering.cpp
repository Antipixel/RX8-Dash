#include "steering.h"

Steering::Steering() : Message(STEER_MSG_ID, STEER_MSG_SIZE)
{
    this->setSteeringLight(false);
}

void Steering::setSteeringLight(bool state)
{
    this->setDataBit(0, 7, state);
}
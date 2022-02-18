#include "brakes.h"

Brakes::Brakes(): Message(BRAKES_MSG_ID, BRAKES_MSG_SIZE)
{
    this->setDSCEngaged(true);
    this->setAntilockLight(false);
    this->setHandbrakeLight(false);
    this->setTractionLight(false, false);
}

void Brakes::setDSCEngaged(bool state)
{
    this->setDataBit(3, 2, !state);
}

void Brakes::setAntilockLight(bool state)
{
    this->setDataBit(4, 3, state);
}

void Brakes::setHandbrakeLight(bool state)
{
    this->setDataBit(4, 6, state);
}

// Only works if DSC is disabled
void Brakes::setTractionLight(bool state, bool flashing)
{
    this->setDataBit(5, flashing ? 5 : 4, state);
}
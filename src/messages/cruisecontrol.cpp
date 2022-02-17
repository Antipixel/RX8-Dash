#include "cruisecontrol.h"

CruiseControl::CruiseControl() : Message(CRUISE_MSG_ID, CRUISE_MSG_SIZE)
{
    this->setCruiseLight(false);
    this->setCruiseMainLight(false);
}

void CruiseControl::setCruiseLight(bool status)
{
    this->setDataBit(0, 6, status);
}

void CruiseControl::setCruiseMainLight(bool status)
{
    this->setDataBit(0, 7, status);
}
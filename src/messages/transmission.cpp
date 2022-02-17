#include "transmission.h"

Transmission::Transmission() : Message(TRANS_MSG_ID, TRANS_MSG_SIZE)
{
    this->setGear(Gear::NEUTRAL);
}

void Transmission::setGear(Gear gear)
{
    // Get the current warning light status
    uint8_t warning = this->data[1] & WARNING_ON;

    // Set the new gear value
    this->data[0] = (gear >> 8) & 0xFF;
    this->data[1] = (gear >> 0) & 0xFF;

    // Append the warning flag back
    this->data[1] |= warning;
}

void Transmission::setWarningLight(bool state)
{
    this->setDataBit(1, 7, state);
}

Gear Transmission::getGearForPosition(uint8_t position)
{
    switch (position)
    {
        case 0:
            return Gear::REVERSE;
        case 1:
            return Gear::M_1;
        case 2:
            return Gear::M_2;
        case 3:
            return Gear::M_3;
        case 4:
            return Gear::M_4;
        case 5:
            return Gear::M_5;
        default:
        case 6:
            return Gear::M_6;
    }
}
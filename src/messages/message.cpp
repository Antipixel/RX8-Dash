#include "message.h"

Message::Message(uint16_t id, uint8_t size)
{
    this->id = id;
    this->size = size;
}

void Message::setDataBit(uint8_t byte, uint8_t bit, bool state)
{
    uint8_t *target = &this->data[byte];
    uint8_t mask = 1 << bit;

    *target = state ? (*target | mask) : (*target & ~mask);
}

uint16_t Message::getID()
{
    return this->id;
}

uint8_t Message::getSize()
{
    return this->size;
}

uint8_t *Message::getData()
{
    return this->data;
}
#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <Arduino.h>

#define MAX_MSG_SIZE 8

class Message
{
private:
    uint16_t id;
    uint8_t size;
protected:
    uint8_t data[MAX_MSG_SIZE];
    void setDataBit(uint8_t byte, uint8_t bit, bool state);
public:
    Message(uint16_t id, uint8_t size);
    uint16_t getID();
    uint8_t getSize();
    uint8_t *getData();
};

#endif
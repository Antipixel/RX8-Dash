#ifndef SPEED_H_
#define SPEED_H_

#include "message.h"
#include <Arduino.h>

#define SPEED_MSG_ID 0x201
#define SPEED_MSG_SIZE 8

#define RPM_SCALE 3.85
#define KMH_MPS_RATIO 3.6
#define VEHICLE_SPEED_OFFSET 100.0
#define VEHICLE_SPEED_SCALE 100.0

#define MAXIMUM_RPM 11000
#define MAXIMUM_KMH 299

class Speed: public Message
{
public:
    Speed();
    void setEngineSpeed(float rpmRaw);
    void setVehicleSpeed(float speedMps);
};

#endif
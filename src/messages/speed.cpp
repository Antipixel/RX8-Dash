#include "speed.h"

Speed::Speed() : Message(SPEED_MSG_ID, SPEED_MSG_SIZE)
{
    this->setEngineSpeed(0);
    this->setVehicleSpeed(0);
}

void Speed::setEngineSpeed(float rpmRaw)
{
    if (rpmRaw > MAXIMUM_RPM)
        rpmRaw = MAXIMUM_RPM;

    uint16_t value = rpmRaw * RPM_SCALE;

    this->data[0] = (value >> 8) & 0xFF;
    this->data[1] = (value >> 0) & 0xFF;
}

void Speed::setVehicleSpeed(float speedMps)
{
    int speedKmh = speedMps * KMH_MPS_RATIO;

    // Cap the speed at 299 km/h, as this is the maximum
    // speed the digital speedometer on the cluster can display
    if (speedKmh > MAXIMUM_KMH)
        speedKmh = MAXIMUM_KMH;

    uint16_t value = VEHICLE_SPEED_BASE;
    value += speedKmh * VEHICLE_SPEED_SCALE;

    this->data[4] = (value >> 8) & 0xFF;
    this->data[5] = (value >> 0) & 0xFF;
}
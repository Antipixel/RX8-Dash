#ifndef DATA_OUT_H_
#define DATA_OUT_H_

#include <Arduino.h>
#include "xyz.h"
#include "wheels.h"
#include "cardetails.h"

struct ForzaData 
{
    int32_t enabled; // = 1 when race is on. = 0 when in menus/race stopped …
    uint32_t timestamp; // Can overflow to 0 eventually

    float maxRPM;
    float idleRPM;
    float currentRPM;

    XYZ acceleration; //In the car's local space; X = right, Y = up, Z = forward
    XYZ velocity; //In the car's local space; X = right, Y = up, Z = forward
    XYZ angularVelocity; //In the car's local space; X = pitch, Y = yaw, Z = roll

    float yaw;
    float pitch;
    float roll;

    Wheels<float> normalisedSuspensionTravel; // Suspension travel normalized: 0.0f = max stretch; 1.0 = max compression
    Wheels<float> tireSlipRatio; // Tire normalized slip ratio, = 0 means 100% grip and |ratio| > 1.0 means loss of grip.
    Wheels<float> wheelRotationSpeed; // Wheel rotation speed radians/sec.
    Wheels<uint32_t> wheelOnRumbleStrip; // = 1 when wheel is on rumble strip, = 0 when off.
    Wheels<float> wheelInPuddleDepth; // = from 0 to 1, where 1 is the deepest puddle
    Wheels<float> surfaceRumble; // Non-dimensional surface rumble values passed to controller force feedback
    Wheels<float> tireSlipAngle; // Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means loss of grip.
    Wheels<float> tireCombinedSlip; // Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means loss of grip.
    Wheels<float> suspensionTravelMeters; // Actual suspension travel in meters

    CarDetails vehicle;

    uint8_t unknownCollisionData[8];

    XYZ position; // Position (meters)

    float speed; // meters per second
    float power; // watts
    float torque; // newton meter

    Wheels<float> tireTemperature;

    float Boost; // in PSI, included vacuum
    float Fuel; // 0.0 (empty) to 1.0 (full)
    float DistanceTraveled;
    float BestLap;
    float LastLap;
    float CurrentLap;
    float CurrentRaceTime;

    uint16_t LapNumber;
    uint8_t RacePosition;

    uint8_t acceleratorPosition;
    uint8_t brakePedalPosition;
    uint8_t clutchPedalPosition;
    uint8_t handBrake;
    uint8_t gear;
    int8_t steer;

    int8_t NormalizedDrivingLine;
    int8_t NormalizedAIBrakeDifference;
};

#endif
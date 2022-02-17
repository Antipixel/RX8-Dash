#ifndef CAR_DETAILS_H_
#define CAR_DETAILS_H_

#include <Arduino.h>

enum Classification: uint32_t
{
    D = 0,
    C = 1,
    B = 2,
    A = 3,
    S1 = 4,
    S2 = 5,
    X = 7
};

enum Category: uint32_t
{
    MODERN_SUPERCARS = 11,
    RETRO_SUPERCARS = 12,
    HYPER_CARS = 13,
    RETRO_SALOONS = 14,
    // Unknown 15
    VANS_UTLITIES = 16,
    RETRO_SPORTS_CARS = 17,
    MODERN_SPORTS_CARS = 18,
    SUPER_SALOONS = 19,
    CLASSIC_RACERS = 20,
    CULT_CARS = 21,
    RARE_CLASSICS = 22,
    HOT_HATCH = 23,
    RETRO_HOT_HATCH = 24,
    SUPER_HOT_HATCH = 25,
    EXTREME_TRACK_TOYS = 26,
    // Unknown 27
    CLASSIC_MUSCLE = 28,
    RODS_AND_CUSTOMS = 29,
    RETRO_MUSCLE = 30,
    MODERN_MUSCLE = 31,
    RETRO_RALLY = 32,
    CLASSIC_RALLY = 33,
    MODERN_RALLY = 35,
    GT_CARS = 36,
    SUPER_GT = 37,
    EXTREME_OFFROAD = 38,
    SPORTS_UTILITY_HEROES = 39,
    OFFROAD = 40,
    OFFROAD_BUGGIES = 41,
    CLASSIC_SPORTS_CARS = 42,
    TRACK_TOYS = 43,
    VINTAGE_RACERS = 44,
    TRUCKS = 45
};

enum Drivetrain: uint32_t
{
    FWD = 0,
    RWD = 1,
    AWD = 2
};

struct CarDetails
{
    int32_t id; // Unique identifier for the vehicle model
    Classification classification; // The vehicle performance classification
    int32_t performanceIndex; //Between 100 (slowest car) and 999 (fastest car) inclusive
    Drivetrain drivetrain;
    int32_t cylinders;
    Category category;
};

#endif
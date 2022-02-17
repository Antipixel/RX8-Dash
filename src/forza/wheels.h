#ifndef WHEELS_H_
#define WHEELS_H_

#include <Arduino.h>
#include "cardetails.h"

#define WHEELS_TOTAL 4.0

template <class T>
class Wheels
{
public:
    T fl;
    T fr;
    T rl;
    T rr;
    T getTotal();
    T getAverage();
    T getTotalDriven(Drivetrain drivetrain);
    T getAverageDriven(Drivetrain drivetrain);
};

template <class T>
T Wheels<T>::getTotal()
{
    return this->getTotalDriven(Drivetrain::AWD);
}

template <class T>
T Wheels<T>::getAverage()
{
    return this->getAverageDriven(AWD);
}

template <class T>
T Wheels<T>::getTotalDriven(Drivetrain drivetrain)
{
    T frontTotal = this->fl + this->fr;
    T rearTotal = this->rl + this->rr;
    
    switch (drivetrain)
    {
        case FWD:
            return frontTotal;
        case RWD:
            return rearTotal;
        case AWD:
        default:
            return frontTotal + rearTotal;
    }
}

template <class T>
T Wheels<T>::getAverageDriven(Drivetrain drivetrain)
{
    float drivenCount = (drivetrain == AWD) ? WHEELS_TOTAL : 2;
    return this->getTotalDriven(drivetrain) / drivenCount;
}

#endif
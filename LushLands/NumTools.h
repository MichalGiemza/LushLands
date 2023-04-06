#pragma once
#include "DataTypes.h"
#include "Logger.h"
#include <cmath>


class NumTools {
    /** 
    * Tools for angles
    */
public:
    static radian directionToRadian(bool north, bool south, bool east, bool west);
    static radian pointToRadian(int x, int y);
    static ll customFloor(ll value, ll comaVal);
};


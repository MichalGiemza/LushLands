#pragma once
#include "DataTypes.h"
#include <cmath>


class NumTools {
    /** 
    * Tools for angles
    */
public:
    static radian directionToRadian(bool north, bool south, bool east, bool west);
    static ll customFloor(ll value, ll comaVal);
};


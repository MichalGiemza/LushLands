#pragma once
#include "DataTypes.h"
#include <cmath>


class AngleTools {
    /** 
    * Tools for angles
    */
public:
    static radian directionToRadian(bool north, bool south, bool east, bool west);
};


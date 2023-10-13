#include "stdafx.h"
#include "NumTools.h"

radian NumTools::directionToRadian(bool north, bool south, bool east, bool west) {
    int x = (int)west - (int)east;
    int y = (int)south - (int)north;
    if (x == 0 and y == 0)
        return NAN;
    float angle = atan2f(x, y);
    return fmodf(angle + 2 * PI, 2 * PI);
}

radian NumTools::pointToRadian(int x, int y) {
    radian angle = atan2(-x, y);
    angle = fmodf(angle + 2 * PI, 2 * PI);
    return angle;
}

ll NumTools::customFloor(ll value, ll comaVal) {
    int roundHelper = (value < 0) * (1 - comaVal);
    return (value + roundHelper) / comaVal * comaVal;
}


#pragma once
#include "DataTypes.h"

typedef const int cstint;

namespace time_constants {
    const cstint MONTHS_IN_YEAR = 12;
    const cstint DAYS_IN_MONTH = 30;
    const cstint DAYS_IN_YEAR = MONTHS_IN_YEAR * DAYS_IN_MONTH;
    const cstint HOURS_IN_DAY = 24;

    // 10 real seconds = 1 game minute
    const miliseconds MINUTE_AS_RAWMS = 10 * 1000;
    const miliseconds HOUR_AS_RAWMS = 60 * MINUTE_AS_RAWMS;
    const miliseconds DAY_AS_RAWMS = HOUR_AS_RAWMS * HOURS_IN_DAY;
    const miliseconds MONTH_AS_RAWMS = DAY_AS_RAWMS * DAYS_IN_MONTH;
    const miliseconds YEAR_AS_RAWMS = DAY_AS_RAWMS * DAYS_IN_YEAR;

    const cstint STARTING_YEAR = 1491;
    const cstint MAX_YEAR = LLONG_MAX / YEAR_AS_RAWMS + STARTING_YEAR - 1;

    const season SPRING = "spring";
    const season SUMMER = "summer";
    const season AUTUMN = "autumn";
    const season WINTER = "winter";
}
namespace t = time_constants;

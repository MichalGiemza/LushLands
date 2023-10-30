#include "WorldTime.h"

WorldTime::WorldTime(int h, int min, int d, int m, int y) {
    setYear(y);
    setMonth(m);
    setDay(d);
    setHour(h);
    setMinute(min);
}

WorldTime::WorldTime(int d, int m, int y) : WorldTime(0, 0, d, m, y) {}

WorldTime::WorldTime() : value(0) {}

miliseconds WorldTime::getAsMiliseconds() {
    return value;
}

void WorldTime::setAsMiliseconds(miliseconds ms) {
    value = ms;
}

int WorldTime::getYear() {
    return value / t::YEAR_AS_RAWMS + t::STARTING_YEAR;
}

int WorldTime::getMonth() {
    return (value % t::MONTH_AS_RAWMS) / t::MONTH_AS_RAWMS + 1;
}

int WorldTime::getDay() {
    return (value % t::DAY_AS_RAWMS) / t::DAY_AS_RAWMS + 1;
}

int WorldTime::getHour() {
    return (value % t::HOUR_AS_RAWMS) / t::HOUR_AS_RAWMS;
}

int WorldTime::getMinute() {
    return (value % t::MINUTE_AS_RAWMS) / t::MINUTE_AS_RAWMS;
}

void WorldTime::setYear(int y) {
    value += (y - getYear()) * t::YEAR_AS_RAWMS;
}

void WorldTime::setMonth(int m) {
    value += (m - 1 - getMonth()) * t::MONTH_AS_RAWMS;
}

void WorldTime::setDay(int d) {
    value += (d - 1 - getDay()) * t::DAY_AS_RAWMS;
}

void WorldTime::setHour(int h) {
    value += (h - getHour()) * t::HOUR_AS_RAWMS;
}

void WorldTime::setMinute(int min) {
    value += (min - getMinute()) * t::MINUTE_AS_RAWMS;
}

std::string WorldTime::asString() {
    std::ostringstream os;
    os << getHour() << ":" << getMinute() << " " << getDay() << "." << getMonth() << "." << getYear();
    return os.str();
}


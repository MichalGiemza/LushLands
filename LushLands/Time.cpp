#include "Time.h"

Time::Time(int h, int min, int d, int m, int y) {
    setYear(y);
    setMonth(m);
    setDay(d);
    setHour(h);
    setMinute(min);
}

Time::Time(int d, int m, int y) : Time(0, 0, d, m, y) {}

Time::Time() : value(0) {}

miliseconds Time::getAsMiliseconds() {
    return value;
}

void Time::setAsMiliseconds(miliseconds ms) {
    value = ms;
}

int Time::getYear() {
    return value / t::YEAR_AS_RAWMS + t::STARTING_YEAR;
}

int Time::getMonth() {
    return (value % t::MONTH_AS_RAWMS) / t::MONTH_AS_RAWMS + 1;
}

int Time::getDay() {
    return (value % t::DAY_AS_RAWMS) / t::DAY_AS_RAWMS + 1;
}

int Time::getHour() {
    return (value % t::HOUR_AS_RAWMS) / t::HOUR_AS_RAWMS;
}

int Time::getMinute() {
    return (value % t::MINUTE_AS_RAWMS) / t::MINUTE_AS_RAWMS;
}

void Time::setYear(int y) {
    value += (y - getYear()) * t::YEAR_AS_RAWMS;
}

void Time::setMonth(int m) {
    value += (m - 1 - getMonth()) * t::MONTH_AS_RAWMS;
}

void Time::setDay(int d) {
    value += (d - 1 - getDay()) * t::DAY_AS_RAWMS;
}

void Time::setHour(int h) {
    value += (h - getHour()) * t::HOUR_AS_RAWMS;
}

void Time::setMinute(int min) {
    value += (min - getMinute()) * t::MINUTE_AS_RAWMS;
}

std::string Time::asString() {
    std::ostringstream os;
    os << getHour() << ":" << getMinute() << " " << getDay() << "." << getMonth() << "." << getYear();
    return os.str();
}


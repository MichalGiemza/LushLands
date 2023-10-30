#pragma once
#include "DataTypes.h"
#include "Constants.h"
#include "TimeConstants.h"
#include <climits>
#include <string>


class WorldTime {
    /**
    * Represents in-game world time.
    */
    miliseconds value;

public:
    WorldTime(int h, int min, int d, int m, int y);
    WorldTime(int d, int m, int y);
    WorldTime();
    miliseconds getAsMiliseconds();
    void setAsMiliseconds(miliseconds ms);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int min);
    std::string asString();
    // TODO: dni tygodnia, nazwy miesiecys
    friend bool operator== (const WorldTime &t1, const WorldTime &t2);
    friend bool operator!= (const WorldTime &t1, const WorldTime &t2);
    friend bool operator< (const  WorldTime &t1, const WorldTime &t2);
    friend bool operator> (const  WorldTime &t1, const WorldTime &t2);
    friend bool operator<= (const WorldTime &t1, const WorldTime &t2);
    friend bool operator>= (const WorldTime &t1, const WorldTime &t2);
    friend bool operator== (const miliseconds t1, const WorldTime &t2);
    friend bool operator!= (const miliseconds t1, const WorldTime &t2);
    friend bool operator< (const  miliseconds t1, const WorldTime &t2);
    friend bool operator> (const  miliseconds t1, const WorldTime &t2);
    friend bool operator<= (const miliseconds t1, const WorldTime &t2);
    friend bool operator>= (const miliseconds t1, const WorldTime &t2);
    friend bool operator== (const WorldTime &t1, const miliseconds t2);
    friend bool operator!= (const WorldTime &t1, const miliseconds t2);
    friend bool operator< (const  WorldTime &t1, const miliseconds t2);
    friend bool operator> (const  WorldTime &t1, const miliseconds t2);
    friend bool operator<= (const WorldTime &t1, const miliseconds t2);
    friend bool operator>= (const WorldTime &t1, const miliseconds t2);
    friend WorldTime operator+= (WorldTime &t1, const miliseconds t2);
};

inline bool operator== (const WorldTime &t1, const WorldTime &t2) {return t1.value == t2.value;}
inline bool operator!= (const WorldTime &t1, const WorldTime &t2) {return t1.value != t2.value;}
inline bool operator< (const  WorldTime &t1, const WorldTime &t2) {return t1.value < t2.value;}
inline bool operator> (const  WorldTime &t1, const WorldTime &t2) {return t1.value > t2.value;}
inline bool operator<= (const WorldTime &t1, const WorldTime &t2) {return t1.value <= t2.value;}
inline bool operator>= (const WorldTime &t1, const WorldTime &t2) {return t1.value >= t2.value;}
inline bool operator== (const miliseconds t1, const WorldTime &t2) {return t1 == t2.value;}
inline bool operator!= (const miliseconds t1, const WorldTime &t2) {return t1 != t2.value;}
inline bool operator< (const  miliseconds t1, const WorldTime &t2) {return t1 <  t2.value;}
inline bool operator> (const  miliseconds t1, const WorldTime &t2) {return t1 >  t2.value;}
inline bool operator<= (const miliseconds t1, const WorldTime &t2) {return t1 <= t2.value;}
inline bool operator>= (const miliseconds t1, const WorldTime &t2) {return t1 >= t2.value;}
inline bool operator== (const WorldTime &t1, const miliseconds t2) {return t1.value == t2;}
inline bool operator!= (const WorldTime &t1, const miliseconds t2) {return t1.value != t2;}
inline bool operator< (const  WorldTime &t1, const miliseconds t2) {return t1.value <  t2;}
inline bool operator> (const  WorldTime &t1, const miliseconds t2) {return t1.value >  t2;}
inline bool operator<= (const WorldTime &t1, const miliseconds t2) {return t1.value <= t2;}
inline bool operator>= (const WorldTime &t1, const miliseconds t2) {return t1.value >= t2;}
inline WorldTime operator+= (WorldTime &t1, const miliseconds t2) { t1.value += t2; return t1; }

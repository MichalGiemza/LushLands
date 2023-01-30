#pragma once
#include <time.h>
#include <type_traits>
#include <random>
#include <map>
#include "ConstantSets.h"


class Random_ {
    /** 
    * Static class for wrapping C++ randomness;
    */
public:
    template<typename T>
    static T random(T min, T max);
};

template<typename T>
T Random_::random(T from_, T to_) {
    if constexpr (std::is_arithmetic_v<T>) {
        T val = double(rand()) / double(RAND_MAX) + double(rand());
        return  from_ + std::fmod(val, to_ - from_);
    } else {
        throw std::logic_error(could_not_create_random_from_type);
    }
}


#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

typedef uint64_t uuid;

class GeneratorUUID {
    static std::random_device rd;
    static std::mt19937_64 gen;
    static std::uniform_int_distribution<uint64_t> dis;
public:
    static uuid generateUUID();
};


#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

typedef std::string uuid;

class GeneratorUUID {
public:
    static std::string generateUUID();
};


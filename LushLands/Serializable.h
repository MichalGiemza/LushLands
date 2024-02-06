#pragma once
#include "JsonHandler.h"


class Serializable {
public:
    virtual json serialize() = 0;
    virtual void deserialize(json data) = 0;
};
#pragma once
#include "InputEvents.h"
#include "ActionMap.h"
#include "Logger.h"

class Keyboard {
    InputEvents *inputEvents;
public:
    Keyboard(InputEvents *inputEvents);
};


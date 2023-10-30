#pragma once
#include "InputEvents.h"
#include "ActionMap.h"

class Keyboard {
    InputEvents *inputEvents;
public:
    Keyboard(InputEvents *inputEvents);
};


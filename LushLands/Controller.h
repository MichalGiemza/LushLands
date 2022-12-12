#pragma once
#include "InputEvents.h"
#include "ActionMap.h"
#include "Logger.h"

class InputController {
    InputEvents *inputEvents;
public:
    InputController(InputEvents *inputEvents);
};


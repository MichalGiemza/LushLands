#pragma once
#include "InputEvents.h"
#include "ActionMap.h"
#include "stdafx.h"

class Keyboard {
    InputEvents *inputEvents;
public:
    Keyboard(InputEvents *inputEvents);
};


#pragma once
#include "Actions.h"
#include "InputEvents.h"
#include "ActionMap.h"

class Controller {
    InputEvents *inputEvents;
public:
    Controller(InputEvents *inputEvents);
private:
    void hookKeysToActions();
};


#pragma once
#include "InputEvents.h"
#include "Keyboard.h"
#include "EventHandler.h"
#include "Focus.h"

class Controller {
    /**
    * Handles user interactions.
    */
    InputEvents *inputEvents;
    Keyboard *inputController;
    EventHandler *eventHandler;
    Focus *focus;
    ActionMap *actionMap;
public:
    Controller();
    InputEvents *getInputEvents();
    Keyboard *getInputController();
    EventHandler *getEventHandler();
    Focus *getFocus();
    ActionMap *getActionMap();
};


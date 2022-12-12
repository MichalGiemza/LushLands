#pragma once
#include "InputEvents.h"
#include "Controller.h"
#include "EventHandler.h"
#include "Focus.h"

class Controller_ {
    /**
    * Handles user interactions.
    */
    InputEvents *inputEvents;
    InputController *inputController;
    EventHandler *eventHandler;
    Focus *focus;
    ActionMap *actionMap;
public:
    Controller_();
    InputEvents *getInputEvents();
    InputController *getInputController();
    EventHandler *getEventHandler();
    Focus *getFocus();
    ActionMap *getActionMap();
};


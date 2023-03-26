#pragma once
#include "InputEvents.h"
#include "Keyboard.h"
#include "EventHandler.h"
#include "Focus.h"
#include "Mouse.h"

class Controller {
    /**
    * Handles user interactions.
    */
    InputEvents *inputEvents;
    Keyboard *keyboard;
    Mouse *mouse;
    EventHandler *eventHandler;
    Focus *focus;
    ActionMap *actionMap;
public:
    Controller();
    void postInit(ALLEGRO_BITMAP *cursorBitmap);
    InputEvents *getInputEvents();
    EventHandler *getEventHandler();
    Focus *getFocus();
    ActionMap *getActionMap();
    Mouse *getMouse();
};


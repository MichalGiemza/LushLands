#pragma once
#include "InputEvents.h"
#include "Keyboard.h"
#include "Focus.h"
#include "Mouse.h"

class Controller {
    /**
    * Handles user interactions.
    */
    InputEvents *inputEvents;
    Keyboard *keyboard;
    Mouse *mouse;
    Focus *focus;
    ActionMap *actionMap;
public:
    Controller(Core *core);
    void postInit(ALLEGRO_BITMAP *cursorBitmap);
    InputEvents *getInputEvents();
    Focus *getFocus();
    ActionMap *getActionMap();
    Mouse *getMouse();
};


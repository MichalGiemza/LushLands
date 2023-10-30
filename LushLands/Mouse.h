#pragma once
#include "InputEvents.h"
#include "ActionMap.h"
#include "Display.h"

class Mouse {
    /** 
    * Mouse input device handling
    */
    InputEvents *inputEvents;
    ALLEGRO_MOUSE_CURSOR *cursor = 0;
public:
    Mouse(InputEvents *inputEvents);
    ALLEGRO_MOUSE_CURSOR *getCursor();
};


#pragma once
#include "stdafx.h"
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
    void addCursor(ALLEGRO_BITMAP *cursorBmp);
    ALLEGRO_MOUSE_CURSOR *getCursor();
};


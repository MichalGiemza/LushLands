#pragma once
#include <allegro5/allegro.h>
#include "StaticUIElement.h"
#include "ConstantSets.h"

class UICursor : public StaticUIElement {
    /**
    * Static UI element representing arrow cursor.
    */
    ALLEGRO_MOUSE_CURSOR *cursor;
public:
    UICursor(ALLEGRO_MOUSE_CURSOR *cursor);
};


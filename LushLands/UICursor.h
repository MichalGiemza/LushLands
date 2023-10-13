#pragma once
#include "stdafx.h"
#include "StaticUIElement.h"

class UICursor : public StaticUIElement {
    /**
    * Static UI element representing arrow cursor.
    */
    ALLEGRO_MOUSE_CURSOR *cursor;
public:
    UICursor(ALLEGRO_MOUSE_CURSOR *cursor);
};


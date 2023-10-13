#include "stdafx.h"
#include "UICursor.h"

UICursor::UICursor(ALLEGRO_MOUSE_CURSOR *cursor) :
    StaticUIElement(ft::WORLD_CURSOR, fp::DEFAULT), cursor(cursor) {}

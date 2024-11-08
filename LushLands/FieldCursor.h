#pragma once
#include "WorldUIElement.h"
#include "Camera.h"
#include "ConstantSets.h"
#include "Agui/Base/Colors.h"


class FieldCursor : public WorldUIElement {
    /** 
    * World UI element represented as selected square on the map.
    */
    Position cursorInWorld;
    Position precisePos;
    Camera *camera;
public:
    FieldCursor(Camera *camera, InputEvents *inputEvents);
    void draw();
    Position *getPrecisePosition();
    Position *getTilePosition();
    friend void updatePosition(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void updatePosition(ALLEGRO_EVENT *allegroEvent, void *caller);

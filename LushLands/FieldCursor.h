#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "WorldUIElement.h"
#include "DataTypes.h"
#include "Position.h"
#include "Camera.h"
#include "Colors.h"
#include "NumTools.h"


class FieldCursor : public WorldUIElement {
    /** 
    * World UI element represented as selected square on the map.
    */
    //TilePosition tp {0, 0, 0};
    Position cursorInWorld;
    Camera *camera;
public:
    FieldCursor(Camera *camera, InputEvents *inputEvents);
    void draw();
    friend void updatePosition(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void updatePosition(ALLEGRO_EVENT *allegroEvent, void *caller);

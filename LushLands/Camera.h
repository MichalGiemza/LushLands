#pragma once
#include "Constants.h"
#include "Position.h"
#include "Size.h"
#include "GameElement.h"
#include "Focus.h"
#include "ConstantSets.h"
#include "InputEvents.h"

class Camera : GameElement {
    // Zoom at 100 means 1px at screen is 1px in texture
    // Zoom at 400 means 4px at screen is 1px in texture
    const int minZoom = 50;
    const int maxZoom = 400;
    int zoom = 100;
    int scrollSpeed = 10;
    Position *followedPosition = 0;
    Position *independentPosition = 0;

    int left();
    int right();
    int top();
    int bottom();
    int level();
public:
    Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents);
    void update(); // TODO: Czy potrzebujê tego?
    int getZoom();
    void setZoom(int zoom);
    Position *getPosition();
    void setFollowedPosition(Position *position);
    bool isAreaVisible(Position *position, Size *size);
    friend void handleMovement(ALLEGRO_EVENT *ae, void *obj);
};

void handleMovement(ALLEGRO_EVENT *ae, void *obj);

#pragma once
#include "Rectangle_.h"
#include "Constants.h"
#include "GameElement.h"
#include "Focus.h"
#include "ConstantSets.h"
#include "InputEvents.h"
#include "Logger.h"
#include "Events.h"


class Camera : GameElement {
    // Zoom at 100 means 1px at screen is 1px in texture
    // Zoom at 400 means 4px at screen is 1px in texture
    const int minZoom = 50;
    const int maxZoom = 400;
    int zoom = 100;
    int scrollSpeed = 30;
    Rectangle_ *followedFrame = 0;
    Rectangle_ *independentFrame = 0;
private:
    int level();
public:
    Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents);
    int getZoom();
    void setZoom(int zoom);
    Rectangle_ *getFrame();
    Position *getPosition();
    void setFollowedPosition(Position *position);
    bool isAreaVisible(Rectangle_ *area);
    friend void handleMovement(ALLEGRO_EVENT *ae, void *obj);
    pxint shiftToScreenPosX(int accurateWorldX);
    pxint shiftToScreenPosZ(int accurateWorldZ);
    Position mouseToWorldPosition(int x, int y);
};

void handleMovement(ALLEGRO_EVENT *ae, void *obj);

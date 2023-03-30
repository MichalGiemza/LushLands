#pragma once
#include "WorldRectangle.h"
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
    int scrollSpeed = meter / 10;
    WorldRectangle *followedFrame = 0;
    WorldRectangle *independentFrame = 0;
private:
    int level();
public:
    Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents);
    int getZoom();
    void setZoom(int zoom);
    WorldRectangle *getFrame();
    Position *getPosition();
    void setFollowedPosition(Position *position);
    bool isAreaVisible(WorldRectangle *area);
    friend void handleMovement(ALLEGRO_EVENT *ae, void *obj);
    pxint shiftToScreenPosX(int accurateWorldX);
    pxint shiftToScreenPosZ(int accurateWorldZ);
    Position mouseToWorldPosition(int x, int y);
};

void handleMovement(ALLEGRO_EVENT *ae, void *obj);

#pragma once
#include "WorldRectangle.h"
#include "Constants.h"
#include "GameElement.h"
#include "Focus.h"
#include "ConstantSets.h"
#include "InputEvents.h"
#include "Logger.h"
#include "Events.h"
#include "EventFactory.h"
#include "NumTools.h"


class Camera : GameElement {
    // Zoom at 100 means 1px at screen is 1px in texture
    // Zoom at 400 means 4px at screen is 1px in texture
    const int minZoom = 50;
    const int maxZoom = 400;
    int zoom = 100;
    int scrollSpeed = meter / 10;
    Size *followedObjectSize = 0;
    WorldRectangle *followedFrame = 0;
    WorldRectangle *independentFrame = 0;

    bool pN = false, pS = false, pE = false, pW = false;
private:
    int level();
    pxint sizeShX();
    pxint sizeShZ();
public:
    Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents);
    int getZoom();
    void setZoom(int zoom);
    WorldRectangle *getFrame();
    Position *getPosition();
    void setFollowedPosition(Position *position, Size *objectSize);
    bool isAreaVisible(WorldRectangle *area);
    friend void handleMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
    friend void handleMovement(ALLEGRO_EVENT *ae, void *obj);
    pxint shiftToScreenPosX(int accurateWorldX);
    pxint shiftToScreenPosZ(int accurateWorldZ);
    Position mouseToWorldPosition(int x, int y);
};

void handleMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
void handleMovement(ALLEGRO_EVENT *ae, void *obj);


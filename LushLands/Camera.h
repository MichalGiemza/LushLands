#pragma once
#include "Constants.h"
#include "Position.h"
#include "Size.h"

class Camera {
    // Zoom at 100 means 1px at screen is 1px in texture
    // Zoom at 400 means 4px at screen is 1px in texture
    const int minZoom = 50;
    const int maxZoom = 400;
    int zoom = 100;
    int scrollSpeed = 100;
    Position *followedPosition = 0;

    int left();
    int right();
    int top();
    int bottom();
public:
    Camera(Position *followedPosition);
    void update(); // TODO: Czy potrzebujê tego?
    int getZoom();
    void setZoom(int zoom);
    Position *getFollowedPosition();
    void setFollowedPosition(Position *position);
    bool isAreaVisible(Position *position, Size *size);
};


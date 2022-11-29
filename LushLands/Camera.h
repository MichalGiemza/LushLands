#pragma once
#include "Constants.h"
#include "Position.h"

class Camera {
    const int minZoom = 100;
    const int maxZoom = 400;
    int zoom = 200;
    int scrollSpeed = 100;
    Position *followedPosition = 0;
public:
    static void init();
    static void update();
    static int getZoom();
    static void setZoom(int zoom);
    static Position getFollowedPosition();
    static void setFollowedPosition(Position *position);
};


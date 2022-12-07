#pragma once
#include "Position.h"
#include "Size.h"
#include "Logger.h"

class Body {
    /** 
    * Represents body (still not collideable) of world entities. 
    */
    Position position;
    Size size;
public:
    Body(Position position, Size size);
    Position getCenter();
    Position getTopLeft();
    Position getBottomRight();
    Size getSize();
    void setPosition(Position position);
    Position getPosition();
};


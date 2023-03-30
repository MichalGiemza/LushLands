#pragma once
#include "Position.h"
#include "Size.h"
#include "Logger.h"
#include "WorldRectangle.h"
#include <math.h>

class Body {
    /** 
    * Entity module representing body of entity. 
    * Main properties are:
    *  - Position
    *  - Size
    */
protected:
    Position position;
    Size size;
    Position center;
    WorldRectangle rectangle;
    void refreshCenter();
public:
    Body(Position &position, const Size &size);
    Position *getCenter();
    Position *getTopLeft();
    WorldRectangle *getRectangle();
    Size *getSize();
    Position *getPosition();
    void setPosition(Position &position);
    void setCenter(Position &center);
    int accurateDistanceTo2D(Body &other) const;
    bool operator==(const Body &other) const;
};


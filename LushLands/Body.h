#pragma once
#include "Position.h"
#include "Size.h"
#include "Logger.h"
#include "Rectangle_.h"
#include <math.h>

class Body {
    /** 
    * Entity module representing body of entity. 
    */
protected:
    Position position;
    Size size;
    Position *center = 0;
    Rectangle_ *rectangle;
    void refreshCenter();
public:
    Body(Position position, Size size);
    Position *getCenter();
    Position *getTopLeft();
    Rectangle_ *getRectangle();
    Size getSize();
    void setPosition(Position position);
    Position *getPosition();
    int accurateDistanceTo2D(Body &other) const;
    bool operator==(const Body &other) const;
};


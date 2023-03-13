#pragma once
#include "Position.h"
#include "Size.h"
#include "Logger.h"
#include "Rectangle_.h"
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
    Rectangle_ rectangle;
    void refreshCenter();
public:
    Body(Position &position, const Size &size);
    Position *getCenter();
    Position *getTopLeft();
    Rectangle_ *getRectangle();
    Size *getSize();
    Position *getPosition();
    void setPosition(Position &position);
    int accurateDistanceTo2D(Body &other) const;
    bool operator==(const Body &other) const;
};


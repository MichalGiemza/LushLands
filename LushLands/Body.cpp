#include "stdafx.h"
#include "Body.h"

void Body::refreshCenter() {
    center.setPX(position.getPX() + size.getPW() / 2);
    center.setPY(position.getPY());
    center.setPZ(position.getPZ() + size.getPL() / 2);
}

Body::Body(Position &position, const Size &size) : 
    position(), size(size), rectangle(0, 0, 0, 0) { 
    // Position
    setPosition(position);
    // Rectangle
    rectangle.setPosition(&this->position);
    rectangle.setSize(&this->size);
}

Position *Body::getCenter() {
    return &center;
}

Position *Body::getTopLeft() {
    return &position;
}

WorldRectangle *Body::getRectangle() {
    return &rectangle;
}

Size *Body::getSize() {
    return &size;
}

Position *Body::getPosition() {
    return &position;
}

void Body::setPosition(Position &pos) {
    position.setPX(pos.getPX());
    position.setPY(pos.getPY());
    position.setPZ(pos.getPZ());
    refreshCenter();
}

int Body::accurateDistanceTo2D(Body &other) const {
    return rectangle.accurateDistanceTo2D(&other.rectangle);
}

bool Body::operator==(const Body &other) const {
    return position == other.position && size == other.size;
}

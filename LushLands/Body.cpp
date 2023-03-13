#include "Body.h"

void Body::refreshCenter() {
    center.setAccurateX(position.getAccurateX() + size.getAccurateWidth() / 2);
    center.setAccurateY(position.getAccurateY() + size.getAccurateHeight() / 2);
    center.setAccurateZ(position.getAccurateZ() + size.getAccurateLength() / 2);
}

Body::Body(Position &position, const Size &size) : 
    position(position), size(size), rectangle(0, 0, 0, 0) { 
    // Center
    center = Position();
    refreshCenter();
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

Rectangle_ *Body::getRectangle() {
    return &rectangle;
}

Size *Body::getSize() {
    return &size;
}

Position *Body::getPosition() {
    return &position;
}

void Body::setPosition(Position &position) {
    this->position = Position(position);
    refreshCenter();
}

int Body::accurateDistanceTo2D(Body &other) const {
    return rectangle.accurateDistanceTo2D(&other.rectangle);
}

bool Body::operator==(const Body &other) const {
    return position == other.position && size == other.size;
}

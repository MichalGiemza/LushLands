#include "Body.h"

void Body::refreshCenter() {
    center.setPX(position.getPX() + size.getPW() / 2);
    center.setPY(position.getPY() + size.getPH() / 2);
    center.setPZ(position.getPZ() + size.getPL() / 2);
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
    refreshCenter();
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

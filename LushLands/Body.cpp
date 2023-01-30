#include "Body.h"

void Body::refreshCenter() {
    center->setAccurateX(position.getAccurateX() + size.getAccurateWidth() / 2);
    center->setAccurateY(position.getAccurateY() + size.getAccurateHeight() / 2);
    center->setAccurateZ(position.getAccurateZ() + size.getAccurateLength() / 2);
}

Body::Body(Position position, Size size) : position(position), size(size) {
    center = new Position();
    refreshCenter();
    rectangle = new Rectangle_(0, 0, 0, 0);
    rectangle->setPosition(&position);
    rectangle->setSize(&size);
}

Position *Body::getCenter() {
    return center;
}

Position *Body::getTopLeft() {
    return &position;
}

Rectangle_ *Body::getRectangle() {
    return rectangle;
}

Size Body::getSize() {
    return Size(size);
}

void Body::setPosition(Position position) {
    this->position = position;
    refreshCenter();
}

Position *Body::getPosition() {
    return &position;
}

int Body::accurateDistanceTo2D(Body &other) const {
    return rectangle->accurateDistanceTo2D(other.rectangle);
}

bool Body::operator==(const Body &other) const {
    return position == other.position && size == other.size;
}

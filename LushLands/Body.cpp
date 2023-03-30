#include "Body.h"

void Body::refreshCenter() {
    center.setPX(position.getPX() + size.getPW() / 2);
    center.setPY(position.getPY());
    center.setPZ(position.getPZ() + size.getPL() / 2);
}

Body::Body(Position &position, const Size &size) : 
    position(), size(size), rectangle(0, 0, 0, 0) { 
    // Center
    center = Position();
    setCenter(position);
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

void Body::setCenter(Position &ctr) {
    center.setPX(ctr.getPX());
    center.setPY(ctr.getPY());
    center.setPZ(ctr.getPZ());

    position.setPX(ctr.getPX() - size.getPW() / 2);
    position.setPY(ctr.getPY());
    position.setPZ(ctr.getPZ() - size.getPL() / 2);
}
int Body::accurateDistanceTo2D(Body &other) const {
    return rectangle.accurateDistanceTo2D(&other.rectangle);
}

bool Body::operator==(const Body &other) const {
    return position == other.position && size == other.size;
}

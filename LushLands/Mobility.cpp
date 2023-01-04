#include "Mobility.h"

void applyMovement(Position &newPosition, void *obj) {
    Mobility *m = (Mobility *)obj;
    m->setPosition(newPosition);
}

Mobility::Mobility(int movementSpeed_, Position &position, Size &size) : Body(position, size) {
    movementSpeed = movementSpeed_;
}

int Mobility::getMovementSpeed() {
    return movementSpeed;
}

int Mobility::getDirection() {
    return direction;
}

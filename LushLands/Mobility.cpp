#include "Mobility.h"

Mobility::Mobility(Body *body, int movementSpeed) : 
    body(body), movementSpeed(movementSpeed), direction(0.0f)
{ }

int Mobility::getMovementSpeed() {
    return movementSpeed;
}

radian Mobility::getDirection() {
    return direction;
}

void Mobility::setDirection(radian direction) {
    this->direction = direction;
}

Body *Mobility::getBody() {
    return body;
}

void applyMovement(Position &newPosition, void *obj) {
    Mobility *m = (Mobility *)obj;
    m->getBody()->setPosition(newPosition);
}

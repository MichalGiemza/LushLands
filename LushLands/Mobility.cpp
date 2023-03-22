#include "Mobility.h"

Mobility::Mobility(DynamicCollider *dynamicCollider, EntityUpdater *entityUpdater, int movementSpeed) :
    dynamicCollider(dynamicCollider), entityUpdater(entityUpdater), movementSpeed(movementSpeed), direction(0.0f) {
}

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
    return dynamicCollider->getCollider()->getBody();
}

DynamicCollider *Mobility::getDynamicCollider() {
    return dynamicCollider;
}

void Mobility::attemptMovement() {
    // Create desired position
    Position *newPos = new Position(*getBody()->getPosition());
    newPos->setPX(newPos->getPX() - std::sin(direction) * movementSpeed);
    newPos->setPZ(newPos->getPZ() + std::cos(direction) * movementSpeed);
    // Send event
    ALLEGRO_EVENT *ae = (ALLEGRO_EVENT *)new ALLEGRO_EVENT {};
    ae->user.type = mobility_attempt_go;
    ae->user.data1 = (intptr_t)dynamicCollider;
    ae->user.data2 = (intptr_t)newPos;
    al_emit_user_event(entityUpdater->getEventSource(), ae, NULL);
}

void applyMovement(Position &newPosition, void *obj) {
    Mobility *m = (Mobility *)obj;
    m->getBody()->setPosition(newPosition);
}

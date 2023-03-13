#include "RandomWalk.h"


void RandomWalk::setNewAction(miliseconds currentTime) {
    getMobility()->setDirection(Random_::random(0.0f, 2 * PI));
    currentAction = currentAction == ra::walking ? ra::waiting : ra::walking;
    continueActionUntil = currentTime + (walkInterval * Random_::random(75, 125)) / 100;
}

RandomWalk::RandomWalk(DynamicCollider *dynamicCollider, EntityUpdater *entityUpdater, miliseconds walkInterval) :
    dynamicCollider(dynamicCollider), entityUpdater(entityUpdater), walkInterval(walkInterval) {
    // Register to update
    EntityUpdateSubscription *es = new EntityUpdateSubscription { 0, 0, updateRandomWalk, this };
    entityUpdater->addToUpdate(es);
}

Mobility *RandomWalk::getMobility() {
    return dynamicCollider->getMobility();
}

Position *RandomWalk::getPosition() {
    return dynamicCollider->getMobility()->getBody()->getPosition();
}

DynamicCollider *RandomWalk::getDynamicCollider() {
    return dynamicCollider;
}

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller) {
    RandomWalk *c = (RandomWalk *)caller;
    if (not c->entityUpdater->getEventSource())
        return;

    if (timeNow >= c->continueActionUntil)
        c->setNewAction(timeNow);

    if (c->currentAction == ra::walking) {
        // Create desired position
        Position *newPos = new Position(*c->dynamicCollider->getCollider()->getBody()->getPosition());
        newPos->setAccurateX(newPos->getAccurateX() - std::sin(c->getMobility()->getDirection()) * c->getMobility()->getMovementSpeed() / representationComaValue);
        newPos->setAccurateZ(newPos->getAccurateZ() + std::cos(c->getMobility()->getDirection()) * c->getMobility()->getMovementSpeed() / representationComaValue); // TODO: - sin + cos -> czy napewno tak jest dobrze?
        // Send event
        ALLEGRO_EVENT *ae = (ALLEGRO_EVENT *)new ALLEGRO_EVENT {}; 
        ae->user.type = mob_attempt_go;
        ae->user.data1 = (intptr_t)c->getDynamicCollider();
        ae->user.data2 = (intptr_t)newPos;
        al_emit_user_event(c->entityUpdater->getEventSource(), ae, NULL);
    }
}


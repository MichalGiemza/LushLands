#include "RandomWalk.h"


void RandomWalk::setNewAction(miliseconds currentTime) {
    direction = Random_::random(0.0f, 2 * PI);
    currentAction = currentAction == ra::walking ? ra::waiting : ra::walking;
    continueActionUntil = currentTime + (walkInterval * Random_::random(75, 125)) / 100;
}

RandomWalk::RandomWalk(Position &position, Size &size, int movementSpeed_, miliseconds walkInterval) :
    DynamicCollider(position, size, movementSpeed_), 
    Collider(position, size),
    Mobility(movementSpeed_, position, size), 
    Body(position, size) {
    this->walkInterval = walkInterval;
    EntityUpdateSubscription *es = new EntityUpdateSubscription { 0, 0, updateRandomWalk, this };
    addToUpdate(es);
}

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller) {
    auto c = (RandomWalk *)caller;
    if (not c->parentEventSource)
        return;

    if (timeNow >= c->continueActionUntil)
        c->setNewAction(timeNow);

    if (c->currentAction == ra::walking) {
        Position *newPos = new Position(c->position);
        newPos->setAccurateX(newPos->getAccurateX() - std::sin(c->direction) * c->movementSpeed / representationComaValue);
        newPos->setAccurateZ(newPos->getAccurateZ() + std::cos(c->direction) * c->movementSpeed / representationComaValue);
        // TODO: - sin + cos -> czy napewno tak jest dobrze?
        ALLEGRO_EVENT *ae = (ALLEGRO_EVENT *)new ALLEGRO_EVENT {};
        ae->user.type = mob_attempt_go;
        ae->user.data1 = (intptr_t)c;
        ae->user.data2 = (intptr_t)newPos;
        al_emit_user_event(c->parentEventSource, ae, NULL);
    }
}


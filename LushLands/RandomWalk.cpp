#include "RandomWalk.h"


void RandomWalk::setNewAction(miliseconds currentTime) {
    direction = Random_::random(0.0f, 2 * PI);
    currentAction = currentAction == ra::walking ? ra::waiting : ra::walking;
    continueActionUntil = currentTime + (walkInterval * Random_::random(75, 125)) / 100;
}

RandomWalk::RandomWalk(Position &position, Size &size, int movementSpeed_, miliseconds walkInterval, Time *worldTime) :
    DynamicCollider(position, size, movementSpeed_), 
    Collider(position, size),
    Mobility(movementSpeed_, position, size), Body(position, size)
{
    this->walkInterval = walkInterval;
    this->worldTime = worldTime;
}

void updateRandomWalk(ALLEGRO_EVENT *allegroEvent, void *caller) {
    auto c = (RandomWalk *)caller;
    miliseconds dt = allegroEvent->timer.count;

    if (*(c->worldTime) >= c->continueActionUntil)
        c->setNewAction(c->worldTime->getAsMiliseconds());

    if (c->currentAction == ra::walking) {
        Position newPos = Position(c->position);
        newPos.setAccurateX(newPos.getAccurateX() - std::sin(c->direction) * c->movementSpeed / representationComaValue);
        newPos.setAccurateZ(newPos.getAccurateZ() + std::cos(c->direction) * c->movementSpeed / representationComaValue);
        // TODO: - sin + cos -> czy napewno tak jest dobrze?

    }
}

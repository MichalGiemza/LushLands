#include "RandomWalk.h"


void RandomWalk::setNewAction(miliseconds currentTime) {
    if (currentAction == ra::walking) {
        // Finished walking
        currentAction = ra::waiting;
        getMobility()->setDirection(std::nanf(""));
    } else {
        // Finished waiting
        Collider *c = getCollider();
        radian newDir = getRandomDirection(c->isInCollisionTop(), c->isInCollisionBottom(), c->isInCollisionLeft(), c->isInCollisionRight());
        getMobility()->setDirection(newDir);
        currentAction = std::isnan(newDir) ? ra::waiting : ra::walking;
    }
    continueActionUntil = currentTime + (walkInterval * Random_::random(75, 125)) / 100;
}

RandomWalk::RandomWalk(Mobility *mobility, EntityUpdater *entityUpdater, miliseconds walkInterval) :
    mobility(mobility), entityUpdater(entityUpdater), walkInterval(walkInterval) {
    // Register to update
    EntityUpdateSubscription *es = new EntityUpdateSubscription { 0, 0, updateRandomWalk, this };
    entityUpdater->addToUpdate(es);
}

Mobility *RandomWalk::getMobility() {
    return mobility;
}

Position *RandomWalk::getPosition() {
    return mobility->getBody()->getPosition();
}

DynamicCollider *RandomWalk::getDynamicCollider() {
    return mobility->getDynamicCollider();
}

Collider *RandomWalk::getCollider() {
    return mobility->getDynamicCollider()->getCollider();
}

radian RandomWalk::getRandomDirection(bool forbidTop, bool forbidBottom, bool forbidLeft, bool forbidRight) {
    // If all directions are forbidden, return 0.0f
    if (forbidTop and forbidBottom and forbidLeft and forbidRight)
        return std::nanf("");

    // Generate a random angle in radians
    float angle = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f * PI;

    // Check if the angle is forbidden and adjust it if necessary
    angle += (forbidTop && angle > PI * 0.5f) * (PI - angle);
    angle += (forbidBottom && angle < PI * 0.5f) * (PI - angle);
    angle += (forbidLeft && angle > PI && angle < PI * 1.5f) * (2.0f * PI - angle);
    angle += (forbidRight && (angle < PI || angle > PI * 1.5f)) * (PI - angle);

    return angle;
}

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller) {
    RandomWalk *rw = (RandomWalk *)caller;

    if (not rw->entityUpdater->getEventSource())
        return;

    // Change action on collision
    if (rw->getCollider()->isInCollision() and rw->currentAction == ra::walking)
        rw->setNewAction(timeNow);

    // Action timed out, select new one
    if (timeNow >= rw->continueActionUntil)
        rw->setNewAction(timeNow);

    // Make step
    if (rw->currentAction == ra::walking)
        rw->getMobility()->attemptMovement();
}


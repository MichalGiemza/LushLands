#include "RandomWalk.h"


void RandomWalk::setNewAction(miliseconds currentTime) {
    if (currentAction == ra::walking) {
        // Finished walking
        currentAction = ra::waiting;
        getMobility()->setDirection(std::nanf(""));
        return;
    } else {
        // Finished waiting
        Collider *c = getCollider();
        radian newDir = getRandomDirection(c->isInCollisionTop(), c->isInCollisionBottom(), c->isInCollisionLeft(), c->isInCollisionRight());
        getMobility()->setDirection(newDir);
        currentAction = std::isnan(newDir) ? ra::waiting : ra::walking;
    }
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

Collider *RandomWalk::getCollider() {
    return dynamicCollider->getCollider();
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
    Collider *col = rw->dynamicCollider->getCollider();

    if (not rw->entityUpdater->getEventSource())
        return;

    // Change action on collision
    if (col->isInCollision() and rw->currentAction == ra::walking)
        rw->setNewAction(timeNow);

    // Action timed out, select new one
    if (timeNow >= rw->continueActionUntil)
        rw->setNewAction(timeNow);

    // Make step
    if (rw->currentAction == ra::walking) {
        // Create desired position
        Position *newPos = new Position(*rw->dynamicCollider->getCollider()->getBody()->getPosition());
        newPos->setPX(newPos->getPX() - std::sin(rw->getMobility()->getDirection()) * rw->getMobility()->getMovementSpeed());
        newPos->setPZ(newPos->getPZ() + std::cos(rw->getMobility()->getDirection()) * rw->getMobility()->getMovementSpeed()); // TODO: - sin + cos -> czy napewno tak jest dobrze?
        // Send event
        ALLEGRO_EVENT *ae = (ALLEGRO_EVENT *)new ALLEGRO_EVENT {}; 
        ae->user.type = mob_attempt_go;
        ae->user.data1 = (intptr_t)rw->getDynamicCollider();
        ae->user.data2 = (intptr_t)newPos;
        al_emit_user_event(rw->entityUpdater->getEventSource(), ae, NULL);
    }
}


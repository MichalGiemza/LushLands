#include "ChunkEventHandler.h"


ChunkEventHandler::ChunkEventHandler(CollisionManager *collisionManager_) {
    collisionManager = collisionManager_;
}

void ChunkEventHandler::handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent) {
    auto dynCollider = (DynamicCollider *)currentEvent->user.data1;
    auto collider = dynCollider->getCollider();
    auto newPos = (Position *)currentEvent->user.data2;
    auto collidersONP = collisionManager->getCollidersObstructuringNewPosition(dynCollider, newPos);

    // Collision status
    bool fromTop = false, fromBottom = false, fromLeft = false, fromRight = false;
    for (auto c = collidersONP->begin(); c != collidersONP->end(); ++c) {
        fromTop    |= collider->isCollidingTop(*c);
        fromBottom |= collider->isCollidingBottom(*c);
        fromLeft   |= collider->isCollidingLeft(*c);
        fromRight  |= collider->isCollidingRight(*c);
    }
    collider->updateCollisionStatus(fromTop, fromBottom, fromLeft, fromRight);
    // Handle collision
    if (not collidersONP->empty()) {
        /*dynCollider->updateNewPositionWithColliders(*newPos, *collidersONP);*/
        printf("");
    }
    // Handle free movement
    else {
        dynCollider->setPosition(*newPos);
    }
    delete newPos;
}


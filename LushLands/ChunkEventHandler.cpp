#include "ChunkEventHandler.h"


ChunkEventHandler::ChunkEventHandler(CollisionManager *collisionManager_, ChunkElements *ce) :
    ce(ce), collisionManager(collisionManager_) { }

void ChunkEventHandler::handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent) {
    DynamicCollider *dynCollider;
    Position *newPos;
    EventFactory::unpackMobilityAttemptGo(currentEvent, (void **)&dynCollider, (void **)&newPos);

    auto collider = dynCollider->getCollider();
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
    }
    // Handle free movement
    else {
        dynCollider->setPosition(*newPos);
    }
    delete newPos;
}

void ChunkEventHandler::handleItemCollection() {
    // FIXME: M*N complexity, can it be done better?
    std::vector<std::pair<Item *, Entity *>> collection;
    for (auto &i : ce->items) {
        for (auto &h : ce->humanoids) {
            Position *pI = i->getPosition();
            Position *pH = (Position *)((Humanoid *)h)->getPosition();
            if (pI->getY() != pH->getY())
                continue;
            if (pI->distance2D(*pH) <= itemMagnetRadius * meter)
                collection.push_back(std::make_pair(i, h));
        }
    }
    // Assign collected items to humanoids
    std::vector<Item *> leftoverItems;
    for (auto &p : collection) {
        Inventory *inv = (Inventory *)((Humanoid *)p.second)->getInventory();
        Item *leftover = inv->putItemAuto(p.first);
        if (leftover)
            leftoverItems.push_back(leftover);
    }
    // Remove collected items from map
    for (auto &p : collection)
        ce->items.erase(p.first);
    // Put back leftover items
    for (auto &l : leftoverItems)
        ce->items.insert(l);
}

void ChunkEventHandler::handleItemDrop(ALLEGRO_EVENT *currentEvent) {
    Item *item = 0;
    radian direction = 0;
    EventFactory::unpackItemDrop(currentEvent, (void **)&item, &direction);
    item->getPosition()->push2D(direction, itemMagnetRadius * meter * 15 / 10);
    ce->items.insert(item);
}


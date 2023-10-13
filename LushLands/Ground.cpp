#include "stdafx.h"
#include "Ground.h"

Ground::Ground(GroundCtorParams &p) :
    Entity(p.entityType, *p.description, p.updateType, p.inputEvents),
    entityUpdater(),
    appearance(*p.color, p.textureLocalization),
    body(*p.position, *p.size),
    destroyability(this, p.inputEvents, p.maxHealth, p.requiredTool, *p.drops),
    gameElement(ft::GROUND, fp::GROUND, fg::SIMULATION) {

    //Logger::log(ll::DEBUG_ENTITY, "Created Ground entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Ground::clone() {
    return new Ground(*this);
}

void *Ground::getEntityUpdater() {
    return &entityUpdater;
}

void *Ground::getGameElement() {
    return &gameElement;
}

void *Ground::getColor() {
    return (void *)appearance.getColor();
}

void *Ground::getAppearance() {
    return &appearance;
}

void *Ground::getMobility() {
    return nullptr;
}

void *Ground::getCollider() {
    return nullptr;
}

void *Ground::getDynamicCollider() {
    return nullptr;
}

void *Ground::getRandomWalk() {
    return nullptr;
}

void *Ground::getBody() {
    return &body;
}

void *Ground::getSize() {
    return body.getSize();
}

void *Ground::getPosition() {
    return body.getPosition();
}

void *Ground::getTilePosition() {
    return new TilePosition(body.getCenter()->getTilePosition());
}

void *Ground::getDestroyability() {
    return &destroyability;
}

void *Ground::getFirstName() {
    return nullptr;
}

void *Ground::getLastName() {
    return nullptr;
}

void *Ground::getInventory() {
    return nullptr;
}

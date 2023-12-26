#include "Humanoid.h"

Humanoid::Humanoid(HumanoidCtorParams &p) :
    Entity(p.entityType, *p.description, constant_update, p.inputEvents),
    entityUpdater(),
    appearance(*p.color),
    body(*p.position, *p.size),
    collider(&body),
    dynamicCollider(&collider),
    mobility(&dynamicCollider, &entityUpdater, p.movementSpeed),
    firstName(firstName),
    lastName(lastName),
    gender(gender),
    inventory(p.invSize, body.getPosition()),
    destroyability(this, p.inputEvents, p.maxHealth, p.requiredTool, *p.drops),
    gameElement(ft::HUMANOID, fp::HUMANOID, fg::SIMULATION) {
}

Entity *Humanoid::clone() {
    return new Humanoid(*this);
}

void *Humanoid::getEntityUpdater() {
    return &entityUpdater;
}

void *Humanoid::getGameElement() {
    return &gameElement;
}

void *Humanoid::getColor() {
    return (void *)appearance.getColor();
}

void *Humanoid::getAppearance() {
    return &appearance;
}

void *Humanoid::getMobility() {
    return &mobility;
}

void *Humanoid::getCollider() {
    return &collider;
}

void *Humanoid::getDynamicCollider() {
    return &dynamicCollider;
}

void *Humanoid::getRandomWalk() {
    return nullptr;
}

void *Humanoid::getBody() {
    return &body;
}

void *Humanoid::getSize() {
    return body.getSize();
}

void *Humanoid::getPosition() {
    return body.getPosition();
}

void *Humanoid::getTilePosition() {
    return new TilePosition(body.getCenter()->getTilePosition());
}

void *Humanoid::getDestroyability() {
    return &destroyability;
}

void *Humanoid::getFirstName() {
    return (void *)firstName;
}

void *Humanoid::getLastName() {
    return (void *)lastName;
}

void *Humanoid::getInventory() {
    return &inventory;
}


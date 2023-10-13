#include "stdafx.h"
#include "Animal.h"

Animal::Animal(AnimalCtorParams &p) :
    Entity(p.entityType, *p.description, constant_update, p.inputEvents),
    entityUpdater(),
    appearance(*p.color, p.textureLocalization),
    body(*p.position, *p.size),
    collider(&body),
    dynamicCollider(&collider),
    mobility(&dynamicCollider, &entityUpdater, p.movementSpeed),
    randomWalk(&mobility, &entityUpdater, p.walkInterval),
    gameElement(ft::ANIMAL, fp::ANIMAL, fg::SIMULATION),
    destroyability(this, p.inputEvents, p.maxHealth, p.requiredTool, *p.drops){

    //Logger::log(ll::DEBUG_ENTITY, "Created Animal entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Animal::clone() {
    return new Animal(*this);
}

void *Animal::getEntityUpdater() {
    return &entityUpdater;
}

void *Animal::getGameElement() {
    return &gameElement;
}

void *Animal::getColor() {
    return (void *)appearance.getColor();
}

void *Animal::getAppearance() {
    return &appearance;
}

void *Animal::getMobility() {
    return &mobility;
}

void *Animal::getCollider() {
    return &collider;
}

void *Animal::getDynamicCollider() {
    return &dynamicCollider;
}

void *Animal::getRandomWalk() {
    return &randomWalk;
}

void *Animal::getBody() {
    return &body;
}

void *Animal::getSize() {
    return body.getSize();
}

void *Animal::getPosition() {
    return body.getPosition();
}

void *Animal::getTilePosition() {
    return new TilePosition(body.getCenter()->getTilePosition());
}

void *Animal::getDestroyability() {
    return &destroyability;
}

void *Animal::getFirstName() {
    return nullptr;
}

void *Animal::getLastName() {
    return nullptr;
}

void *Animal::getInventory() {
    return nullptr;
}

#include "Structure.h"

Structure::Structure(StructureCtorParams &p) :
    Entity(p.entityType, *p.description, p.updateType, p.inputEvents),
    entityUpdater(),
    appearance(*p.color, p.textureLocalization),
    body(*p.position, *p.size),
    collider(&body),
    gameElement(ft::STRUCTURE, fp::STRUCTURE, fg::SIMULATION),
    destroyability(this, p.inputEvents, p.maxHealth, p.requiredTool, *p.drops) {

    //Logger::log(ll::DEBUG_ENTITY, "Created Structure entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Structure::clone() {
    return new Structure(*this);
}

void *Structure::getEntityUpdater() {
    return &entityUpdater;
}

void *Structure::getGameElement() {
    return &gameElement;
}

void *Structure::getColor() {
    return (void *)appearance.getColor();
}

void *Structure::getAppearance() {
    return &appearance;
}

void *Structure::getMobility() {
    return nullptr;
}

void *Structure::getCollider() {
    return &collider;
}

void *Structure::getDynamicCollider() {
    return nullptr;
}

void *Structure::getRandomWalk() {
    return nullptr;
}

void *Structure::getBody() {
    return &body;
}

void *Structure::getSize() {
    return body.getSize();
}

void *Structure::getPosition() {
    return body.getPosition();
}

void *Structure::getTilePosition() {
    return new TilePosition(body.getCenter()->getTilePosition());
}

void *Structure::getDestroyability() {
    return &destroyability;
}

void *Structure::getFirstName() {
    return nullptr;
}

void *Structure::getLastName() {
    return nullptr;
}

void *Structure::getInventory() {
    return nullptr;
}

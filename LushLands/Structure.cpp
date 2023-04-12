#include "Structure.h"

Structure::Structure(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, int maxHealth, const tooltype requiredTool, const ItemDropChance *drops, const updatetype updateType) :
    Entity(entityType, description, updateType),
    entityUpdater(),
    appearance(color),
    body(position, size),
    collider(&body),
    gameElement(ft::STRUCTURE, fp::STRUCTURE, fg::SIMULATION),
    destroyability(maxHealth, requiredTool, drops) {

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

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

Position *Structure::getPosition() {
    return body.getPosition();
}

Size *Structure::getSize() {
    return body.getSize();
}

const Color *Structure::getColor() {
    return appearance.getColor();
}

Collider *Structure::getCollider() {
    return &collider;
}

Body *Structure::getBody() {
    return &body;
}

GameElement *Structure::getGameElement() {
    return &gameElement;
}

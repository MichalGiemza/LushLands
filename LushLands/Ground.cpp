#include "Ground.h"

Ground::Ground(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const updatetype updateType) :
    Entity(entityType, description, updateType),
    entityUpdater(),
    appearance(color),
    body(position, size), 
    gameElement(ft::GROUND, fp::GROUND, fg::SIMULATION) {

    //Logger::log(ll::DEBUG_ENTITY, "Created Ground entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Ground::clone() {
    return new Ground(*this);
}

GameElement *Ground::getGameElement() {
    return &gameElement;
}

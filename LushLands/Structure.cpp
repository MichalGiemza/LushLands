#include "Structure.h"

Structure::Structure(entitytype entityType, std::string description, Position position, Size size, const Color *color) :
    Entity(entityType, description),
    Collider(position, size),
    Appearance(color), 
    Body(position, size) {

    updateType = random_tick;
    Logger::log(ll::DEBUG_ENTITY, "Created Structure entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Structure::clone() {
    return new Structure(*this);
}

#include "Structure.h"

Structure::Structure(entitytype entityType, std::string description, Position position, Size size, const Color *color) :
    Entity(entityType, description),
    Collider(position, size),
    Appearance(color), 
    Body(position, size) {

    Logger::log(ll::DEBUG_ENTITY, "Created Ground entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Structure::clone() {
    return new Structure(*this);
}

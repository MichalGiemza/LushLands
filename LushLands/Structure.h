#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"

class Structure : public Entity, public Body, public Appearance {
    /**
    * Structure
    */
public:
    Structure(entitytype entityType, std::string description, Position position, Size size, const Color *color);
    Entity *clone() override;
};


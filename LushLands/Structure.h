#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "Collider.h"

class Structure : public Entity, public Collider, public Appearance {
    /**
    * Structure
    */
public:
    Structure(entitytype entityType, std::string description, Position position, Size size, const Color *color);
    Entity *clone() override;
};


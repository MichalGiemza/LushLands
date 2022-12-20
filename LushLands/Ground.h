#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"

class Ground : public Entity, public Body, public Appearance {
    /**
    * Ground
    */
public:
    Ground(entitytype entityType, std::string description, Position position, Size size, const Color *color);
    Entity *clone() override;
};


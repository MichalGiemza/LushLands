#pragma once
#include "Entity.h"
#include "Representation.h"
#include "Body.h"

class Ground : public Entity, public Body, public Representation {
    /**
    * Ground
    */
public:
    Ground(entitytype entityType, std::string description, Position position, Size size, texturename textureName, Color color);
    Entity *clone() override;
};


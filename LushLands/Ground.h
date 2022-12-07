#pragma once
#include "Entity.h"
#include "Body.h"

class Ground : public Entity, public Body {
    /**
    * Ground
    */
public:
    Ground(entitytype entityType, std::string description, Position position, Size size, texturename textureName, Color color);
    Entity *clone() override;
};


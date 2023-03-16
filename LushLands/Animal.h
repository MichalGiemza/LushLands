#pragma once
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"

class Animal : public Entity {
    /**
    * Representation of animal.
    *
    */
    EntityUpdater entityUpdater;
    Appearance appearance;
    Body body;
    Collider collider;
    Mobility mobility;
    DynamicCollider dynamicCollider;
    RandomWalk randomWalk;
public:
    // Constructors and main methods
    Animal(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, const miliseconds walkInterval);
    Entity *clone() override;
    
    // Getters, Setters
    EntityUpdater *getEntityUpdater();
    Position *getPosition();
    void setPosition(Position &position);
    Size *getSize();
    const Color *getColor();
    Collider *getCollider();
    Body *getBody();
};


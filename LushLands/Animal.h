#pragma once
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"

class Animal : 
    public Entity, 
    public RandomWalk, 
    public Appearance,
    public virtual EntityUpdater {
    /**
    * Representation of animal.
    *
    */
    
public:
    Animal(entitytype entityType, std::string description, Position position, Size size, const Color *color, int movementSpeed_, miliseconds walkInterval);
    Entity *clone() override;
};


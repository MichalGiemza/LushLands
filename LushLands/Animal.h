#pragma once
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"

class Animal : 
    public Entity, 
    public RandomWalk, 
    public Appearance {
    /**
    * Representation of animal.
    *
    */
    
public:
    Animal(entitytype entityType, std::string description, Position position, Size size, const Color *color, int movementSpeed_, miliseconds walkInterval, Time *worldTime);
    Entity *clone() override;
};


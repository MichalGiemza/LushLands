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
    Animal(Time *worldTime, Position &position, const Color *color, std::string description, entitytype entityType, Size &size, int movementSpeed_, miliseconds walkInterval);

};


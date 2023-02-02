#include "Animal.h"

Animal::Animal(Time *worldTime, Position &position, const Color *color, std::string description, entitytype entityType, Size &size, int movementSpeed_, miliseconds walkInterval) : 
    Entity(entityType, description),
    RandomWalk(position, size, movementSpeed_, walkInterval, worldTime),
    Appearance(color)
{}


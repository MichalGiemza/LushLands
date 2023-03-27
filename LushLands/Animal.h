#pragma once
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"
#include "GameElement.h"
#include "Destroyability.h"

class Animal : public Entity {
    /**
    * Representation of animal.
    *
    */
    GameElement gameElement;
    EntityUpdater entityUpdater;
    Appearance appearance;
    Body body;
    Collider collider;
    Mobility mobility;
    DynamicCollider dynamicCollider;
    RandomWalk randomWalk;
    Destroyability destroyability;
public:
    // Constructors and main methods
    Animal(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, const miliseconds walkInterval, int maxHealth, const tooltype requiredTool, const ItemDropChance *drops);
    Entity *clone() override;
    
    // Getters, Setters
    EntityUpdater *getEntityUpdater();
    Position *getPosition();
    void setPosition(Position &position);
    Size *getSize();
    const Color *getColor();
    Collider *getCollider();
    Mobility *getMobility();
    Body *getBody();
    GameElement *getGameElement();
};


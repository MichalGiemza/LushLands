#pragma once
#include "DynamicCollider.h"
#include "DataTypes.h"
#include "Entity.h"
#include "Color.h"
#include "Appearance.h"
#include "GameElement.h"
#include "Mobility.h"
#include "Inventory.h"


class Humanoid : public Entity {
    /** 
    * Represents humanoid creature.
    */
    GameElement gameElement;
    EntityUpdater entityUpdater;
    Appearance appearance;
    Body body;
    Collider collider;
    Mobility mobility;
    DynamicCollider dynamicCollider;
    Inventory inventory;

    name firstName;
    name lastName;
    gendertype gender;
public:
    // Constructors and main methods
    Humanoid(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, name firstName, name lastName, gendertype gender, const int invSize);
    Entity *clone() override;

    // Getters, Setters
    DynamicCollider *getDynamicCollider();
    EntityUpdater *getEntityUpdater();
    Position *getPosition();
    void setPosition(Position &position);
    Size *getSize();
    const Color *getColor();
    Collider *getCollider();
    Mobility *getMobility();
    Body *getBody();
    name getFirstName();
    name getLastName();
    void setFirstName(name newName);
    void setLastName(name newName);
    GameElement *getGameElement();
    Inventory *getInventory();
};


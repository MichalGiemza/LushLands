#pragma once
#include "Humanoid.h"
#include "Entity.h"
#include "Color.h"
#include "Appearance.h"
#include "Size.h"


class Player {
    /** 
    * Representation of user-controlled character.
    */

    Humanoid *humanoid;
public:
    // Constructors and main methods
    Player(Humanoid *humanoid);

    // Getters, Setters
    name getFirstName();
    name getLastName();
    Entity *getEntity();
    Inventory *getInventory();
};


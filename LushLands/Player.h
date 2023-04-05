#pragma once
#include "Humanoid.h"
#include "Entity.h"
#include "Color.h"
#include "Appearance.h"
#include "Size.h"
#include "NumTools.h"
#include "InputEvents.h"


class Player {
    /** 
    * Representation of user-controlled character.
    */

    Humanoid *humanoid;
    radian lookingDirection = 0;
public:
    // Constructors and main methods
    Player(Humanoid *humanoid, InputEvents *inputEvents);

    // Getters, Setters
    name getFirstName();
    name getLastName();
    Entity *getEntity();
    Inventory *getInventory();
    radian getLookingDirection();
    friend void handleLooking(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void handleLooking(ALLEGRO_EVENT *allegroEvent, void *caller);

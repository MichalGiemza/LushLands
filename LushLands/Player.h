#pragma once
#include "stdafx.h"
#include "Humanoid.h"
#include "Entity.h"
#include "Appearance.h"
#include "InputEvents.h"


class Player {
    /** 
    * Representation of user-controlled character.
    */

    Humanoid *humanoid;
    radian lookingDirection = 0;
    Item *equipped = 0;
public:
    // Constructors and main methods
    Player(Humanoid *humanoid, InputEvents *inputEvents);

    // Getters, Setters
    name getFirstName();
    name getLastName();
    Entity *getEntity();
    Inventory *getInventory();
    radian getLookingDirection();
    Item *getEquippedItem();
    void setEquippedItem(Item *item);
    friend void handleLooking(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void handleLooking(ALLEGRO_EVENT *allegroEvent, void *caller);

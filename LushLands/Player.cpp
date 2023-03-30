#include "Player.h"

Player::Player(Humanoid *humanoid) : 
    humanoid(humanoid) { 

    Logger::log(lg::DEBUG_SIMULATION, "Created Player");
}


name Player::getFirstName() {
    return humanoid->getFirstName();
}

name Player::getLastName() {
    return humanoid->getLastName();
}

Entity *Player::getEntity() {
    return humanoid;
}

Inventory *Player::getInventory() {
    return humanoid->getInventory();
}

#include "stdafx.h"
#include "Player.h"

Player::Player(Humanoid *humanoid, InputEvents *inputEvents) : 
    humanoid(humanoid) { 
    inputEvents->subscribeMouseAxis(handleLooking, this);

    Logger::log(lg::DEBUG_SIMULATION, "Created Player");
}


name Player::getFirstName() {
    return (name)humanoid->getFirstName();
}

name Player::getLastName() {
    return (name)humanoid->getLastName();
}

Entity *Player::getEntity() {
    return humanoid;
}

Inventory *Player::getInventory() {
    return (Inventory *)humanoid->getInventory();
}

radian Player::getLookingDirection() {
    return lookingDirection;
}

Item *Player::getEquippedItem() {
    return equipped;
}

void Player::setEquippedItem(Item *item) {
    equipped = item;
}

void handleLooking(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Player *p = (Player *)caller;
    int x = allegroEvent->mouse.x - displayWidth / 2;
    int y = allegroEvent->mouse.y - displayHeight / 2;
    p->lookingDirection = NumTools::pointToRadian(x, y);
}

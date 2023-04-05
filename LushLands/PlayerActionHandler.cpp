#include "PlayerActionHandler.h"

PlayerActionHandler::PlayerActionHandler(InputEvents *inputEvents, World *world, Player *player, FieldCursor *fieldCursor, InventoryDisplay *invDispl, Hotbar *hotbar) :
    inputEvents(inputEvents), world(world), player(player), fieldCursor(fieldCursor), invDispl(invDispl), hotbar(hotbar) {
    // Subscriptions
    inputEvents->subscribeTimerFPS(0, handlePlayerMovement, this);
    inputEvents->subscribeSystemEvent(player_wills_go, handlePlayerMovementAttempt, this);
}

void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj) {
    PlayerActionHandler *pah = (PlayerActionHandler *)obj;
    keycode key = 0;
    EventFactory::unpackKeyboardLetter(ae, &key);

    switch (key) {
     case ALLEGRO_KEY_W:
     case ALLEGRO_KEY_UP:
         pah->pN = true;
         break;
     case ALLEGRO_KEY_S:
     case ALLEGRO_KEY_DOWN:
         pah->pS = true;
         break;
     case ALLEGRO_KEY_A:
     case ALLEGRO_KEY_LEFT:
         pah->pW = true;
         break;
     case ALLEGRO_KEY_D:
     case ALLEGRO_KEY_RIGHT:
         pah->pE = true;
         break;
    default:
        break;
    }
}

void handlePlayerMovement(ALLEGRO_EVENT *ae, void *obj) {
    PlayerActionHandler *pah = (PlayerActionHandler *)obj;
    Mobility *playerMobility = ((Humanoid *)pah->player->getEntity())->getMobility();

    radian direction = NumTools::directionToRadian(pah->pN, pah->pS, pah->pE, pah->pW);
    playerMobility->setDirection(direction);
    if (not isnan(direction))
        playerMobility->attemptMovement();

    pah->pN = false;
    pah->pS = false;
    pah->pE = false;
    pah->pW = false;
}

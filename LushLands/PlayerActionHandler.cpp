#include "PlayerActionHandler.h"

PlayerActionHandler::PlayerActionHandler(InputEvents *inputEvents, World *world, Player *player, FieldCursor *fieldCursor, InventoryDisplay *invDispl, Hotbar *hotbar) :
    inputEvents(inputEvents), world(world), player(player), fieldCursor(fieldCursor), invDispl(invDispl), hotbar(hotbar) {
    // Subscriptions
    inputEvents->subscribeTimerFPS(0, handlePlayerMovement, this);
    inputEvents->subscribeSystemEvent(player_wills_go, handlePlayerMovementAttempt, this);
    inputEvents->subscribeSystemEvent(player_throws_item, handlePlayerThrowItem, this);
    inputEvents->subscribeSystemEvent(player_wills_use, handlePlayerContextUse, this);
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
    Mobility *playerMobility = (Mobility *)((Humanoid *)pah->player->getEntity())->getMobility();

    radian direction = NumTools::directionToRadian(pah->pN, pah->pS, pah->pE, pah->pW);
    playerMobility->setDirection(direction);
    if (not isnan(direction))
        playerMobility->attemptMovement();

    pah->pN = false;
    pah->pS = false;
    pah->pE = false;
    pah->pW = false;
}

void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj) {
    PlayerActionHandler *pah = (PlayerActionHandler *)obj;
    Item *item = pah->player->getInventory()->takeItem(pah->hotbar->getSelectedIdx());
    if (not item)
        return;
    radian direction = pah->player->getLookingDirection();
    auto *nae = EventFactory::packItemDrop(item, direction);
    // Throw item to chunk
    ChunkPosition cp = ((Position *)((Humanoid *)pah->player->getEntity())->getPosition())->getChunkPosition();
    ALLEGRO_EVENT_SOURCE *es = pah->world->getChunkLoadManager()->getChunk(cp)->getChunkEvents()->getEventSource();
    al_emit_user_event(es, nae, NULL); // FIXME - przyda³oby siê skróciæ drogê tej mêczarni...
}

void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj) {
    PlayerActionHandler *pah = (PlayerActionHandler *)obj;
    // Get tool
    Item *ei = pah->player->getEquippedItem();
    tooltype tt = 0;
    if (ei)
        tt = ei->getToolType();
    if (tt == 0)
        return;
    // Get targeted entity
    Position *fcp = pah->fieldCursor->getPrecisePosition();
    auto clickList = pah->world->getByPosition(fcp);
    Entity *suitableEn = 0;
    for (auto *en : clickList) {
        Destroyability *dstr = (Destroyability *)en->getDestroyability();
        if (dstr->getToolAffecting() == tt) {
            suitableEn = en;
            break;
        }
    }
    if (suitableEn == 0)
        return;
    // Affect entity
    int damage = 50; // TODO: add tool damage
    ((Destroyability *)suitableEn->getDestroyability())->takeDamage(damage, tt);
}

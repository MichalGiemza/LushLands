#include "EventHandler.h"

std::vector<Chunk *> EventHandler::getChunks() {
    return world->getChunkLoadManager()->getActiveChunks();
}

Chunk *EventHandler::getChunk(ChunkPosition &cp) {
    return world->getChunkLoadManager()->getChunk(cp);
}

Chunk *EventHandler::getChunk(Position &position) {
    ChunkPosition cp = position.getChunkPosition();
    return getChunk(cp);
}

EventHandler::EventHandler(Controller *c, Simulation *s, GraphicsManager *g) :
    c(c), s(s), g(g), inputEvents(c->getInputEvents()), world(s->getWorld()), player(s->getPlayer()), fieldCursor(g->getCurrentGameplayScene()->getFieldCursor()),
    invDispl(g->getCurrentGameplayScene()->getInventoryDisplay()), hotbar(g->getCurrentGameplayScene()->getHotbar()), focus(c->getFocus()), actionMap(c->getActionMap()),
    aes(inputEvents->getEventSource()), itemFactory(s->getItemFactory()), craftDispl(g->getCurrentGameplayScene()->getCraftingDisplay()) {
    // Input to Action translation
    inputEvents->subscribeKeyBeingPressed(handleKeyboardKey, this);
    inputEvents->subscribeKeyTyped(handleKeyboardLetter, this);
    inputEvents->subscribeMouseClick(handleMouseClick, this);
    inputEvents->subscribeTimerFPS(0, handlePlayerMovementInput, this);
    // Action handling
    inputEvents->subscribeTimerTPS(0, handleItemCollection, this);
    inputEvents->subscribeSystemEvent(item_drop, handleItemDrop, this);
    inputEvents->subscribeSystemEvent(item_generate, handleItemGenerate, this);
    inputEvents->subscribeSystemEvent(mobility_attempt_go, handleMobMovementAttempt, this);
    inputEvents->subscribeSystemEvent(entity_destroy, handleEntityDestroy, this);
    // Player actions
    inputEvents->subscribeSystemEvent(player_wills_go, handlePlayerMovementAttempt, this);
    inputEvents->subscribeSystemEvent(player_throws_item, handlePlayerThrowItem, this);
    inputEvents->subscribeSystemEvent(player_wills_use, handlePlayerContextUse, this);
}

// Input to Action translation

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();

    simulationevent sep = eh->actionMap->mapKeyboardToWorldPressAction(ae->keyboard.keycode);
    if (sep > 0 and agel->getObjGroup() == fg::SIMULATION) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sep, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }
}

void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();

    systemevent sye = eh->actionMap->mapKeyboardToSystemAction(ae->keyboard.keycode);
    if (sye > 0 && agel->getObjType() != ft::CONSOLE) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sye, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }

    systemevent sel = letter_typed;
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sel, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }
}

void handleMouseClick(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();
    if (agel->getObjGroup() == fg::SIMULATION) {
        ALLEGRO_EVENT *newEvent = EventFactory::packMouseAction(
            eh->actionMap->mapMouseToWorldAction(ae->mouse.button),
            ae->mouse.x, ae->mouse.y);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
    }
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT *newEvent = EventFactory::packMouseAction(
            eh->actionMap->mapMouseToSystemAction(ae->mouse.button),
            ae->mouse.x, ae->mouse.y);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
    }
}

void handlePlayerMovementInput(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    Mobility *playerMobility = (Mobility *)((Humanoid *)eh->player->getEntity())->getMobility();

    radian direction = NumTools::directionToRadian(eh->pN, eh->pS, eh->pE, eh->pW);
    playerMobility->setDirection(direction);
    if (not isnan(direction))
        playerMobility->attemptMovement();

    eh->pN = false;
    eh->pS = false;
    eh->pE = false;
    eh->pW = false;
}

// Action handling

void handleMobMovementAttempt(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;

    DynamicCollider *dynCollider;
    Position *newPos;
    EventFactory::unpackMobilityAttemptGo(ae, (void **)&dynCollider, (void **)&newPos);

    auto collider = dynCollider->getCollider();
    auto chunk = eh->getChunk(*newPos);
    if (chunk == 0)
        return;
    auto contactingColliders = chunk->getCollisionManager()->getCollidersObstructuringNewPosition(dynCollider, newPos);

    // Collision status
    bool fromTop = false, fromBottom = false, fromLeft = false, fromRight = false;
    for (auto c = contactingColliders->begin(); c != contactingColliders->end(); ++c) {
        fromTop |= collider->isCollidingTop(*c);
        fromBottom |= collider->isCollidingBottom(*c);
        fromLeft |= collider->isCollidingLeft(*c);
        fromRight |= collider->isCollidingRight(*c);
    }
    collider->updateCollisionStatus(fromTop, fromBottom, fromLeft, fromRight);
    // Handle collision
    if (not contactingColliders->empty()) {
        /*dynCollider->updateNewPositionWithColliders(*newPos, *collidersONP);*/ // FIXME
    } 
    // Handle free movement
    else {
        dynCollider->setPosition(*newPos);
    }
    // TODO: Transfer miêdzy chunkami
    delete newPos;
}

void handleItemCollection(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    for (auto *c : eh->getChunks())
        c->handleItemCollection();
}

void handleItemDrop(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    Item *item = 0;
    radian direction = 0;
    EventFactory::unpackItemDrop(ae, (void **)&item, &direction);
    
    item->getPosition()->push2D(direction, itemMagnetRadius * meter * 15 / 10);
    eh->world->placeItem(item);
}

void handleItemGenerate(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    ItemDropChance *itemDC = 0;
    radian direction = 0;
    Entity *entity = 0;
    EventFactory::unpackItemGenerate(ae, (void **)&itemDC, &direction, (void **)&entity);
    
    Item *item = eh->itemFactory->buildItem(*itemDC, (Position *)entity->getPosition());
    item->getPosition()->push2D(direction, itemMagnetRadius * meter * 15 / 10);
    eh->world->placeItem(item);
}

void handleEntityDestroy(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    Entity *entity = 0;
    EventFactory::unpackEntityDestroy(ae, (void **)&entity);

    Chunk *c = eh->getChunk(*(Position *)entity->getPosition());
    c->removeEntity(entity);
}

// Player Actions

void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    keycode key = 0;
    EventFactory::unpackKeyboardLetter(ae, &key);

    switch (key) {
    case ALLEGRO_KEY_W:
    case ALLEGRO_KEY_UP:
        eh->pN = true;
        break;
    case ALLEGRO_KEY_S:
    case ALLEGRO_KEY_DOWN:
        eh->pS = true;
        break;
    case ALLEGRO_KEY_A:
    case ALLEGRO_KEY_LEFT:
        eh->pW = true;
        break;
    case ALLEGRO_KEY_D:
    case ALLEGRO_KEY_RIGHT:
        eh->pE = true;
        break;
    default:
        break;
    }
}

void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    Item *item = eh->player->getInventory()->takeItem(eh->hotbar->getSelectedIdx());
    if (not item)
        return;
    // Throw item to chunk
    radian direction = eh->player->getLookingDirection();
    auto *itemDropEvent = EventFactory::packItemDrop(item, direction);
    al_emit_user_event(eh->aes, itemDropEvent, NULL);
}

void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    // Get tool
    Item *ei = eh->player->getEquippedItem();
    tag tt = 0;
    if (ei)
        tt = ei->getToolType();
    if (tt == 0)
        return;
    // Get targeted entity
    Position *fcp = eh->fieldCursor->getPrecisePosition();
    auto clickList = eh->world->getByPosition(fcp);
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
    ((Destroyability *)suitableEn->getDestroyability())->takeDamage(damage);
}


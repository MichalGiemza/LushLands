#include "Scene.h"

Scene::Scene(scenename sceneName, World *world, Display *display, Position *followedPosition, InputEvents *inputEvents, TextureManager *textureManager, Focus *focus, Console *console, Player *player)
    : camera(followedPosition, focus, inputEvents), chunkRepresentationManager(world, display, &camera, textureManager), player(player) {
    this->textureManager = textureManager;
    this->world = world;
    this->display = display;
    this->inputEvents = inputEvents;
    this->console = console;
    name = sceneName;

    this->fieldCursor = new FieldCursor(&camera, inputEvents);
    // Player related windows
    windowManager = new WindowManager(inputEvents);
    invDispl = new InventoryDisplay(display, textureManager, player->getInventory(), 50, 50); //TODO magic numbers
    windowManager->addWindow(invDispl);
    hotbar = new Hotbar(display, textureManager, player->getInventory(), player, inputEvents);
    windowManager->addWindow(hotbar);
    // Event subscriptions
    inputEvents->subscribeTimerFPS(1, draw, this);
    inputEvents->subscribeSystemEvent(user_open_inventory, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_map, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_chat, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_command_chat, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_status, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_quests, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_build_menu, handleAction, this);

}

void Scene::drawChunkGround(ChunkRepresentation &chunkRepresentation, int level) {
    Position pos = Position(*chunkRepresentation.getChunkPosition());
    al_draw_bitmap(chunkRepresentation.getBitmap(level), pos.getX(), pos.getZ(), 0);
}

void draw(ALLEGRO_EVENT *ae, void *scene) {
    // Prepare
    Scene *s = (Scene *)scene;
    miliseconds t = s->world->getWorldTime()->getAsMiliseconds();
    al_clear_to_color(BLACK_COLOR.getAllegroColor());
    // Draw world
    s->chunkRepresentationManager.draw(t);
    // Draw world UI
    s->fieldCursor->draw();
    // Draw Static UI
    s->windowManager->drawWindows();
    s->console->draw();
    // Apply drawing
    al_flip_display();
}

void handleAction(ALLEGRO_EVENT *ae, void *scene) {
    systemevent se = ae->user.type;
    Scene *s = (Scene *)scene;
    switch (se) {
    case user_open_inventory:
    {
        s->invOpen ^= true;
        s->invDispl->setHidden(!s->invOpen);
        break;
    }
    case user_open_map:
    {
        s->mapOpen ^= true;
        // TODO
        break;
    }
    case user_open_chat:
    {
        s->chtOpen = true;
        // TODO
        break;
    }
    case user_open_command_chat:
    {
        s->chtOpen = true;
        // TODO: Type "/" to chat
        break;
    }
    case user_open_status:
    {
        s->stsOpen ^= true;
        // TODO
        break;
    }
    case user_open_quests:
    {
        s->qstOpen ^= true;
        // TODO
        break;
    }
    case user_open_build_menu:
    {
        s->bldOpen ^= true;
        // TODO
        break;
    }
    default:
        break;
    }
}

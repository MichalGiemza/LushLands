#include "Scene.h"

Scene::Scene(scenename sceneName, Core *core, Controller *controller, Simulation *simulation, Display *display, Console *console)
    : camera(simulation->getWorldLoadingPosition(), controller->getFocus(), 
        controller->getInputEvents()), chunkRepresentationManager(simulation->getWorld(), display, &camera), 
    player(simulation->getPlayer()), world(simulation->getWorld()), display(display), 
    inputEvents(controller->getInputEvents()), console(console), name(sceneName), core(core) {
    // Pure UI
    this->fieldCursor = new FieldCursor(&camera, inputEvents);
    windowManager = new agui::WindowManager(core->getGUI());
    // Player related elements
    invDispl = new agui::InventoryDisplay(player->getInventory());
    windowManager->addWindow(invDispl);
    craftingDisplay = new CraftingDisplay(core, simulation->getCraftingManager(), player->getInventory(), inputEvents);
    windowManager->addWindow(craftingDisplay);
    hotbar = new agui::Hotbar(core, player->getInventory(), player, inputEvents);
    windowManager->addWindow(hotbar);
    pauseMenu = new PauseMenu(core, inputEvents);
    windowManager->addWindow(pauseMenu);
    // Player tracking
    camera.setFollowedPosition((Position *)((Humanoid *)player->getEntity())->getPosition(), (Size *)((Humanoid *)player->getEntity())->getSize());
    // Event subscriptions
    inputEvents->subscribeTimerFPS(1, draw, this);
    inputEvents->subscribeSystemEvent(user_open_inventory, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_map, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_chat, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_command_chat, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_status, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_quests, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_build_menu, handleAction, this);
    inputEvents->subscribeSystemEvent(user_debug_view, handleAction, this);
    inputEvents->subscribeSystemEvent(user_open_pause_menu, handleAction, this);
}

FieldCursor *Scene::getFieldCursor() {
    return fieldCursor;
}

agui::Hotbar *Scene::getHotbar() {
    return hotbar;
}

agui::InventoryDisplay *Scene::getInventoryDisplay() {
    return invDispl;
}

CraftingDisplay *Scene::getCraftingDisplay() {
    return craftingDisplay;
}

void Scene::drawChunkGround(ChunkRepresentation &chunkRepresentation, int level) {
    Position pos = Position(*chunkRepresentation.getChunkPosition());
    al_draw_bitmap(chunkRepresentation.getBitmap(level), pos.getX(), pos.getZ(), 0);
}

void draw(ALLEGRO_EVENT *ae, void *scene) {
    // Prepare
    Scene *s = (Scene *)scene;
    miliseconds t = s->world->getWorldTime()->getAsMiliseconds();
    al_clear_to_color(agui::BLACK_COLOR.getAllegroColor());
    // Draw world
    s->chunkRepresentationManager.draw(t, s->dbgOpen);
    // Draw world UI
    s->fieldCursor->draw();
    // Draw Static UI
    s->core->getGUI()->render();
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
        // Inventory
        s->invDispl->setVisibility(s->invOpen);
        // Crafting
        s->craftingDisplay->setVisibility(s->invOpen);
        // Equipment
        // TODO
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
    case user_debug_view:
    {
        s->dbgOpen ^= true;
        // TODO
        break;
    }
    case user_open_pause_menu:
        s->pmnOpen ^= true;
        // Pause Menu
        s->pauseMenu->setVisibility(s->pmnOpen);
    default:
        break;
    }
}

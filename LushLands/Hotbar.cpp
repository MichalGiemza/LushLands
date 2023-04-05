#include "Hotbar.h"

int Hotbar::keycodeToIdx(keycode kc) {
    if (kc >= ALLEGRO_KEY_1 and kc <= ALLEGRO_KEY_9)
        return kc - ALLEGRO_KEY_1;
    if (kc == ALLEGRO_KEY_0)
        return 9;
    if (kc == ALLEGRO_KEY_MINUS)
        return 10;
    if (kc == ALLEGRO_KEY_EQUALS)
        return 11;
}

Hotbar::Hotbar(Display *display, TextureManager *textureManager, Inventory *inv, Player *player, InputEvents *inputEvents) :
    InventoryDisplay(display, textureManager, inv, determineX(), determineY()),
    player(player), inputEvents(inputEvents) {
    setHidden(false);
    inputEvents->subscribeSystemEvent(player_hotbar, handleHotbarKey, this);
    inputEvents->subscribeMouseAxis(handleScroll, this);
    inputEvents->subscribeSystemEvent(player_throws_item, handleThrow, this);
}

pxint Hotbar::determineX() {
    return displayWidth / 2 - determineWidth() / 2;
}

pxint Hotbar::determineY() {
    return displayHeight - determineHeight(inventoryWidth) - 10; // TODO magic number
}

void Hotbar::draw() {
    // Selection frame
    int x_el = x + margin + (tileSizePx + margin) * (selectedIdx % inventory->getSize());
    int y_el = y + margin + (tileSizePx + margin) * (selectedIdx / inventory->getSize());
    // Item bg
    al_draw_filled_rounded_rectangle(x_el, y_el,
        x_el + tileSizePx, y_el + tileSizePx,
        roundingRadiusSmall, roundingRadiusSmall,
        fg->getAllegroColor());
    // Draw the rest
    InventoryDisplay::draw();
}

void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Hotbar *h = (Hotbar *)caller;
    keycode kc = 0;
    EventFactory::unpackKeyboardLetter(allegroEvent, &kc);
    h->selectedIdx = h->keycodeToIdx(kc);
}

void handleScroll(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Hotbar *h = (Hotbar *)caller;
    h->selectedIdx = (((h->selectedIdx - allegroEvent->mouse.dz) % player_hotbar_keycount) + player_hotbar_keycount) % player_hotbar_keycount;
}

void handleThrow(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Hotbar *h = (Hotbar *)caller;
    Item *item = h->inventory->takeItem(h->selectedIdx);
    radian direction = h->player->getLookingDirection();
    auto *ae = EventFactory::packItemDrop(item, direction);
    al_emit_user_event(h->inputEvents->getEventSource(), ae, NULL);
}


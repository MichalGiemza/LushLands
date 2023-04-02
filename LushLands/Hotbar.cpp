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
    player(player) {
    setHidden(false);
    inputEvents->subscribeSystemEvent(player_hotbar, handleHotbarKey, this);
}

pxint Hotbar::determineX() {
    return displayWidth / 2 - determineWidth() / 2;
}

pxint Hotbar::determineY() {
    return displayHeight - determineHeight(inventoryWidth) - 10; // TODO magic number
}

void Hotbar::draw() {
    InventoryDisplay::draw();
    // Selection frame
    int x_el = x + margin + (tileSizePx + margin) * (selectedIdx % inventory->getSize());
    int y_el = y + margin + (tileSizePx + margin) * (selectedIdx / inventory->getSize());
    // Item bg
    al_draw_rectangle(x_el, y_el,
        x_el + tileSizePx, y_el + tileSizePx,
        fg->getAllegroColor(), 4.0f);
}

void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Hotbar *h = (Hotbar *)caller;
    keycode kc = 0;
    EventFactory::unpackKeyboardLetter(allegroEvent, &kc);
    h->selectedIdx = h->keycodeToIdx(kc);
}
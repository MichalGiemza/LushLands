#include "InventoryDisplay.h"

int InventoryDisplay::determineRows(int n) {
    return n / inventoryWidth + (n % inventoryWidth > 0);
}

pxint InventoryDisplay::determineHeight(int n) {
    return determineRows(n) * (tileSizePx + margin) + margin;
}

InventoryDisplay::InventoryDisplay(Display *display, TextureManager *textureManager, Inventory *inv, pxint x, pxint y) :
    StaticBaseWindow(x, y, invWidth, determineHeight(inv->getSize())), dsp(display),
    textureManager(textureManager), invHeight(determineHeight(inv->getSize())),
    inventory(inv) {
    setHidden(true);
}

void InventoryDisplay::interact(pxint x, pxint y) {
    // TODO
}

void InventoryDisplay::openContextMenu(pxint x, pxint y) {
    // TODO
}

void InventoryDisplay::draw() {
    if (hidden)
        return;
    auto backbuffer = al_get_backbuffer(dsp->getDisplay());
    // Window bg
    if (displayBg)
        al_draw_filled_rectangle(x, y, x + invWidth, y + invHeight, bg->getAllegroColor());
    // Inventory elements
    int s = inventory->getSize();
    for (int i = 0; i < inventory->getSize(); i++) {
        int x_el = x + margin + (tileSizePx + margin) * (i % s);
        int y_el = y + margin + (tileSizePx + margin) * (i / s);
        // Item bg
        al_draw_filled_rectangle(x_el, y_el,
            x_el + tileSizePx, y_el + tileSizePx, 
            fg->getAllegroColor());
        // Item
        Item *item = inventory->getItem(i);
        if (not item)
            continue;
        ALLEGRO_BITMAP *itemTex = textureManager->getNamedTexture(item->getType());
        al_draw_bitmap(itemTex, x_el, y_el, 0);
    }
}

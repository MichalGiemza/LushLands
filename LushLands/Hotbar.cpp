#include "Hotbar.h"

Hotbar::Hotbar(Display *display, TextureManager *textureManager, Inventory *inv) : 
    InventoryDisplay(display, textureManager, inv, determineX(), determineY()) {
    setHidden(false);
}

pxint Hotbar::determineX() {
    return displayWidth / 2 - determineWidth() / 2;
}

pxint Hotbar::determineY() {
    return displayHeight - determineHeight(inventoryWidth) - 10; // TODO magic number
}

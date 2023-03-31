#pragma once
#include "InventoryDisplay.h"


class Hotbar : public InventoryDisplay {
    /** 
    * Specialized inventory display - for hotbars
    */

public:
    Hotbar(Display *display, TextureManager *textureManager, Inventory *inv);
    pxint determineX();
    pxint determineY();
};


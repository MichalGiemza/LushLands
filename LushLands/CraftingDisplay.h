#pragma once
#include "CraftingManager.h"
#include "Display.h"
#include "Agui/TextureManager.h"
#include "Agui/Base/BaseWindow.h"


class CraftingDisplay : public agui::BaseWindow {
    /** 
    * Represents crafting interface.
    */
protected:
    const pxint margin = 4;
    const pxint invWidth = tileSizePx * 4 + margin * 6;
    const pxint invHeight = 600;
    name selectedCategory = rc::personal; // DEBUG, set to "0"!
    CraftingManager *cm;
    Display *dsp;
    ALLEGRO_FONT *font;
public:
    CraftingDisplay(Display *display, CraftingManager *craftingManager, pxint x, pxint y);
};


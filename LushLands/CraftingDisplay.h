#pragma once
#include "stdafx.h"
#include "CraftingManager.h"
#include "Display.h"
#include "TextureManager.h"
#include "StaticBaseWindow.h"


class CraftingDisplay : public StaticBaseWindow {
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
    virtual void interact(pxint x, pxint y) override;
    virtual void openContextMenu(pxint x, pxint y) override;
    virtual void draw() override;
};


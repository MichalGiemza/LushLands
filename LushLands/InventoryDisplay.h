#pragma once
#include "stdafx.h"
#include "Inventory.h"
#include "StaticBaseWindow.h"
#include "TextureManager.h"
#include "Display.h"


class InventoryDisplay : public StaticBaseWindow {
    /** 
    * Represents Static UI window with provided inventory.
    */
protected:
    const pxint margin = 4;
    const pxint invWidth;
    const pxint invHeight;
    bool displayBg = true;
    Inventory *inventory;

    Display *dsp;
    TextureManager *textureManager;
    ALLEGRO_FONT *font;
protected:
    int determineRows(int n);
    pxint determineHeight(int elements);
    pxint determineWidth();

public:
    InventoryDisplay(Display *display, TextureManager *textureManager, Inventory *inv, pxint x, pxint y);
    virtual void interact(pxint x, pxint y) override;
    virtual void openContextMenu(pxint x, pxint y) override;
    virtual void draw() override;
};


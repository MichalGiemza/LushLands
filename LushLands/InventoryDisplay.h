#pragma once
#include "Inventory.h"
#include "StaticBaseWindow.h"
#include "TextureManager.h"
#include "ConstantSets.h"
#include "Display.h"


class InventoryDisplay : public StaticBaseWindow {
    /** 
    * Represents Static UI window with provided inventory.
    */
protected:
    const pxint margin = 4;
    const pxint invWidth = inventoryWidth * (tileSizePx + margin) + margin;
    const pxint invHeight;
    bool displayBg = true;
    Inventory *inventory;

    Display *dsp;
    TextureManager *textureManager;
    ALLEGRO_FONT *font;
private:
    int determineRows(int n);
    pxint determineHeight(int elements);

public:
    InventoryDisplay(Display *display, TextureManager *textureManager, Inventory *inv, pxint x, pxint y);
    virtual void interact(pxint x, pxint y) override;
    virtual void openContextMenu(pxint x, pxint y) override;
    virtual void draw() override;
};


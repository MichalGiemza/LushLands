#include "stdafx.h"
#include "InventoryDisplay.h"

int InventoryDisplay::determineRows(int n) {
    return n / inventoryWidth + (n % inventoryWidth > 0);
}

pxint InventoryDisplay::determineHeight(int n) {
    return determineRows(n) * (tileSizePx + margin) + margin;
}

InventoryDisplay::InventoryDisplay(Core *core, Display *display, Inventory *inv, pxint x, pxint y) :
    StaticBaseWindow(x, y, determineWidth(), determineHeight(inv->getSize())), dsp(display),
    inventory(inv), core(core), invHeight(determineHeight(inv->getSize())), invWidth(determineWidth()) {
    // Ctor
    setHidden(true);
    font = al_load_ttf_font(fontNormaleste, 10, 0);
    prepareGUI();
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
        al_draw_filled_rounded_rectangle(x, y, x + invWidth, y + invHeight, 8.0f, 8.0f, bg->getAllegroColor());
    //// Inventory elements
    //int s = inventory->getSize();
    //const int buffSize = 4;
    //char buffer[buffSize];
    //for (int i = 0; i < inventory->getSize(); i++) {
    //    int x_el = x + margin + (tileSizePx + margin) * (i % s);
    //    int y_el = y + margin + (tileSizePx + margin) * (i / s);
    //    // Item bg
    //    al_draw_rounded_rectangle(x_el, y_el,
    //        x_el + tileSizePx, y_el + tileSizePx, 
    //        roundingRadiusSmall, roundingRadiusSmall,
    //        fg->getAllegroColor(), 2.0f);
    //    // Item
    //    Item *item = inventory->getItem(i);
    //    if (not item)
    //        continue;
    //    ALLEGRO_BITMAP *itemTex = textureManager->getTexture(item->getType());
    //    al_draw_bitmap(itemTex, x_el, y_el, 0);
    //    // Amount
    //    if (item->getAmount() > 1) {
    //        sprintf_s(buffer, buffSize, "%3d", item->getAmount());
    //        al_draw_text(font, fg->getAllegroColor(), x_el + tileSizePx - 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
    //    }
    //}
}

pxint InventoryDisplay::determineWidth() {
    return inventoryWidth * (tileSizePx + margin) + margin;
}

void InventoryDisplay::prepareGUI() {
    // Crafting menu // FIXME: Przenieœæ do craftingu, przerobiæ wsio na agui
    core->getGUI()->add(&frame);
    frame.setSize(w * 2, h * 2);
    //frame.setTopMargin(4);
    //frame.setTitleFontMargin(0);
    frame.setLocation(x, y);
    frame.setHorizontalSpacing(0);
    frame.setVerticalSpacing(0);
    frame.setMargins(3,3,3,3);
//    frame.setMovable(false);
    // Grid
    int s = inventory->getSize();
    buttons = new agui::InventorySlot[s];
    for (int i = 0; i < inventory->getSize(); i++) {
        int x_el = margin + (tileSizePx + margin) * (i % s);
        int y_el = margin + (tileSizePx + margin) * (i / s);
        agui::InventorySlot *btn = &buttons[i];

        btn->setLocation(x_el, y_el);
        btn->setText("Item");
        btn->addActionListener(&simpleAL);
        
        frame.add(btn);
    }

    

    
}

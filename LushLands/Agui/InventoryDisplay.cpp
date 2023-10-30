#include "InventoryDisplay.h"


namespace agui {

    int InventoryDisplay::determineRows(int n) {
        return n / inventoryWidth + (n % inventoryWidth > 0);
    }

    int InventoryDisplay::determineHeight(int n) {
        return determineRows(n) * tileSizePx + getMargin(SIDE_TOP) + getMargin(SIDE_BOTTOM);
    }

    int InventoryDisplay::determineWidth() {
        return inventoryWidth * tileSizePx + getMargin(SIDE_LEFT) + getMargin(SIDE_RIGHT);
    }

    void InventoryDisplay::prepareGUI() {
        // Crafting menu // FIXME: Przenieœæ do craftingu, przerobiæ wsio na agui
        this->add(&frame);
        frame.setSize(getWidth(), getHeight());
        frame.setHorizontalSpacing(0);
        frame.setVerticalSpacing(0);
        // Grid
        buttons = new agui::InventorySlot[inv->getSize()];
        for (int i = 0; i < inv->getSize(); i++) {
            int x_el = getMargin(SIDE_LEFT) + (tileSizePx + getMargin(SIDE_RIGHT)) * (i % inv->getSize());
            int y_el = getMargin(SIDE_TOP) + (tileSizePx + getMargin(SIDE_BOTTOM)) * (i / inv->getSize());
            agui::InventorySlot *btn = &buttons[i];
            btn->setLocation(x_el, y_el);
            btn->addActionListener(&simpleAL);
            btn->setItemSlot(inv->getSlot(i));
            frame.add(btn);
        }
    }

    InventoryDisplay::InventoryDisplay(Inventory *inv) : inv(inv) {
        setLocation(invX, invY);
        setSize(determineWidth(), determineHeight(inv->getSize()));
        prepareGUI();
        setVisibility(false);
    }
}

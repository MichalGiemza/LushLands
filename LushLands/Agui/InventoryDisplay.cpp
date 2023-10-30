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
        buttons = new agui::InventorySlot[s];
        for (int i = 0; i < s; i++) {
            int x_el = getMargin(SIDE_LEFT) + (tileSizePx + getMargin(SIDE_RIGHT)) * (i % s);
            int y_el = getMargin(SIDE_TOP) + (tileSizePx + getMargin(SIDE_BOTTOM)) * (i / s);
            agui::InventorySlot *btn = &buttons[i];

            btn->setLocation(x_el, y_el);
            btn->setText("Item");
            btn->addActionListener(&simpleAL);

            frame.add(btn);
        }
    }

    InventoryDisplay::InventoryDisplay(int slotCount) : s(slotCount) {
        setLocation(invX, invY);
        setSize(determineWidth(), determineHeight(s));
        prepareGUI();
        setVisibility(false);
    }
}

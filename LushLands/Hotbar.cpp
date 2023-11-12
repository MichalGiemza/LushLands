#include "Hotbar.h"

namespace agui {
    int Hotbar::keycodeToIdx(keycode kc) {
        if (kc >= ALLEGRO_KEY_1 and kc <= ALLEGRO_KEY_9)
            return kc - ALLEGRO_KEY_1;
        if (kc == ALLEGRO_KEY_0)
            return 9;
        if (kc == ALLEGRO_KEY_MINUS)
            return 10;
        if (kc == ALLEGRO_KEY_EQUALS)
            return 11;
    }

    void Hotbar::setSelectionIdx(int idx) {
        selectedIdx = idx;
        player->setEquippedItem(player->getInventory()->getItem(idx));
    }

    void Hotbar::highlightIdx(int idx) {
        for (int i = 0; i < inventoryWidth; i++) {
            auto &btn = buttons[i];
            if (i == idx)
                btn.setBackColor(UI_HIGHLIGHT_COLOR);
            else
                btn.setBackColor(TRANSPARENT_COLOR);
        }
    }

    //void Hotbar::prepareGUI() {
    //    this->add(&frame);
    //    frame.setSize(getWidth(), getHeight());
    //    frame.setHorizontalSpacing(0);
    //    frame.setVerticalSpacing(0);
    //    // Grid
    //    buttons = new agui::InventorySlot[inv->getSize()];
    //    for (int i = 0; i < inv->getSize(); i++) {
    //        int x_el = getMargin(SIDE_LEFT) + (tileSizePx + getMargin(SIDE_RIGHT)) * (i % inv->getSize());
    //        int y_el = getMargin(SIDE_TOP) + (tileSizePx + getMargin(SIDE_BOTTOM)) * (i / inv->getSize());
    //        agui::InventorySlot *btn = &buttons[i];
    //        btn->setLocation(x_el, y_el);
    //        btn->addActionListener(&simpleAL);
    //        btn->setItemSlot(inv->getSlot(i));
    //        frame.add(btn);
    //    }
    //}

    Hotbar::Hotbar(Core *core, Inventory *inv, Player *player, InputEvents *inputEvents) :
        InventoryDisplay(inv), player(player), inputEvents(inputEvents) {
        inputEvents->subscribeSystemEvent(player_hotbar, handleHotbarKey, this);
        inputEvents->subscribeMouseAxis(handleScroll, this);
        setLocation(hbarX, hbarY);
        setSize(determineWidth(), determineHeight(inv->getSize()));
        prepareGUI();
        setVisibility(true);
    }

    pxint Hotbar::determineX() {
        return displayWidth / 2 - determineWidth() / 2;
    }

    pxint Hotbar::determineY() {
        return displayHeight - determineHeight(inventoryWidth) - 10; // TODO magic number
    }

    int Hotbar::getSelectedIdx() {
        return selectedIdx;
    }

    void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller) {
        Hotbar *h = (Hotbar *)caller;
        keycode kc = 0;
        EventFactory::unpackKeyboardLetter(allegroEvent, &kc);
        int idx = h->keycodeToIdx(kc);
        h->setSelectionIdx(idx);
        h->highlightIdx(idx);
    }

    void handleScroll(ALLEGRO_EVENT *allegroEvent, void *caller) {
        Hotbar *h = (Hotbar *)caller;
        int idx = (((h->selectedIdx - allegroEvent->mouse.dz) % player_hotbar_keycount) + player_hotbar_keycount) % player_hotbar_keycount;
        h->setSelectionIdx(idx);
        h->highlightIdx(idx);
    }
}

#pragma once
#include "Agui/InventoryDisplay.h"
#include "EventFactory.h"
#include "Player.h"

namespace agui {
    class Hotbar : public InventoryDisplay {
        /**
        * Specialized inventory display - for hotbars
        */
        Player *player;
        InputEvents *inputEvents;
        int selectedIdx = 0;
    private:
        int keycodeToIdx(keycode kc);
        void setSelectionIdx(int idx);
    public:
        Hotbar(Core *core, Inventory *inv, Player *player, InputEvents *inputEvents);
        pxint determineX();
        pxint determineY();
        int getSelectedIdx();
        friend void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller);
        friend void handleScroll(ALLEGRO_EVENT *allegroEvent, void *caller);
    };

    void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller);
    void handleScroll(ALLEGRO_EVENT *allegroEvent, void *caller);
}

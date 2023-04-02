#pragma once
#include "InventoryDisplay.h"
#include "Player.h"


class Hotbar : public InventoryDisplay {
    /** 
    * Specialized inventory display - for hotbars
    */
    Player *player;
    int selectedIdx = 0;
    int keycodeToIdx(keycode kc);
public:
    Hotbar(Display *display, TextureManager *textureManager, Inventory *inv, Player *player, InputEvents *inputEvents);
    pxint determineX();
    pxint determineY();
    virtual void draw() override;
    friend void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void handleHotbarKey(ALLEGRO_EVENT *allegroEvent, void *caller);

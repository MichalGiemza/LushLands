#pragma once
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include "Events.h"


class EventFactory {
    /** 
    * Static tool for:
    *  - Packing Allegro event structures
    *  - Unpacking Allegro event structures
    */
public:
    // Action Events
    static ALLEGRO_EVENT *packMobilityAttemptGo(void *dynamicCollider, void *desiredPosition);
    static void unpackMobilityAttemptGo(ALLEGRO_EVENT *aEvent, void **dynamicCollider, void **desiredPosition);
    static ALLEGRO_EVENT *packItemDrop(void *item, radian direction);
    static void unpackItemDrop(ALLEGRO_EVENT *aEvent, void **item, radian *direction);
    // System Events
    static ALLEGRO_EVENT *packMouseAction(const systemevent se, int x, int y);
    static void unpackMouseAction(ALLEGRO_EVENT *aEvent, int *x, int *y);
    static ALLEGRO_EVENT *packKeyboardLetter(const systemevent se, keycode letter);
    static void unpackKeyboardLetter(ALLEGRO_EVENT *aEvent, keycode *letter);
};


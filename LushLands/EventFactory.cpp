#include "EventFactory.h"

ALLEGRO_EVENT *EventFactory::packMobilityAttemptGo(void *dynamicCollider, void *desiredPosition) {
    ALLEGRO_EVENT *ae = new ALLEGRO_EVENT {};
    ae->user.type = mobility_attempt_go;
    ae->user.data1 = (intptr_t)dynamicCollider;
    ae->user.data2 = (intptr_t)desiredPosition;
    return ae;
}

void EventFactory::unpackMobilityAttemptGo(ALLEGRO_EVENT *aEvent, void **dynamicCollider, void **desiredPosition) {
    *dynamicCollider = (void *)aEvent->user.data1;
    *desiredPosition = (void *)aEvent->user.data2;
}

ALLEGRO_EVENT *EventFactory::packMouseAction(const systemevent se, int x, int y) {
    ALLEGRO_EVENT *ae = new ALLEGRO_EVENT {};
    ae->user.type = se;
    ae->user.data1 = (intptr_t)x;
    ae->user.data2 = (intptr_t)y;
    return ae;
}

void EventFactory::unpackMouseAction(ALLEGRO_EVENT *aEvent, int *x, int *y) {
    *x = aEvent->user.data1;
    *y = aEvent->user.data2;
}

ALLEGRO_EVENT *EventFactory::packKeyboardLetter(const systemevent se, keycode letter) {
    ALLEGRO_EVENT *ae = new ALLEGRO_EVENT {};
    ae->user.type = se;
    ae->user.data1 = (intptr_t)letter;
    return ae;
}

void EventFactory::unpackKeyboardLetter(ALLEGRO_EVENT *aEvent, keycode *letter) {
    *letter = aEvent->user.data1;
}

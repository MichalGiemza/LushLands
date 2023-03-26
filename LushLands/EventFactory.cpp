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

#include "Events.h"

ALLEGRO_EVENT_QUEUE *Events::eventQueue;
ALLEGRO_EVENT Events::currentEvent;

void Events::init() {
    eventQueue = al_create_event_queue();
    if (!eventQueue) {
        UI::abortStart("al_create_event_queue failed\n");
    }
}

void Events::mainLoop() {
    while (UI::running) {
        al_wait_for_event(eventQueue, &currentEvent);

        switch (currentEvent.type) {

        case ALLEGRO_EVENT_KEY_DOWN: {
            Input::passKeyDown(currentEvent.keyboard.keycode);
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {
            Input::passKeyUp(currentEvent.keyboard.keycode);
            break;
        }
        case ALLEGRO_EVENT_KEY_CHAR: {
            Input::passChar(currentEvent.keyboard.keycode);
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_CLOSE: {
            UI::stopRunning();
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT: {
            al_clear_keyboard_state(currentEvent.display.source);
            break;
        }
        case ALLEGRO_EVENT_TIMER: {
            // Tick
            Display::updateTrackingFPS();
        }
        default: {
            // We received an event of some type we don't know about. Just ignore it.
            break;
        }
        }
    }
}

void Events::registerEventSource(ALLEGRO_EVENT_SOURCE *event_source) {
    al_register_event_source(eventQueue, event_source);
}

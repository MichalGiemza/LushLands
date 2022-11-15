#include "Events.h"

ALLEGRO_EVENT_QUEUE *Events::eventQueue;
ALLEGRO_EVENT Events::currentEvent;

std::vector<KeySubscribtion> Events::subscribersKeyDown = std::vector<KeySubscribtion>();
std::vector<KeySubscribtion> Events::subscribersKeyUp = std::vector<KeySubscribtion>();
std::vector<KeySubscribtion> Events::subscribersKeyBeingPressed = std::vector<KeySubscribtion>();
std::vector<eventfn> Events::subscribersDisplayClosed = std::vector<eventfn>();
std::vector<eventfn> Events::subscribersDisplaySwitchedOut = std::vector<eventfn>();
std::vector<TimerSubscription> Events::subscribersTimer = std::vector<TimerSubscription>();

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
            //Input::passKeyDown(currentEvent.keyboard.keycode);
            for (auto ev = subscribersKeyDown.begin(); ev != subscribersKeyDown.end(); ++ev)
                if ((*ev).code == currentEvent.keyboard.keycode) // TODO: Przerobic to na hashmape, nie robic for-if
                    (*ev).func();
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {
            //Input::passKeyUp(currentEvent.keyboard.keycode);
            // TODO
            break;
        }
        case ALLEGRO_EVENT_KEY_CHAR: {
            //Input::passChar(currentEvent.keyboard.keycode);
            // TODO
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_CLOSE: {
            // TODO
            UI::stopRunning();
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT: {
            // TODO
            al_clear_keyboard_state(currentEvent.display.source);
            break;
        }
        case ALLEGRO_EVENT_TIMER: {
            // Tick
            // TODO
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

void Events::subscribeKeyDown(keycode kc, eventfn fun) {
    auto p = KeySubscribtion(kc, fun);
    subscribersKeyDown.push_back(p);
}

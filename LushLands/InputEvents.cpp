#include "InputEvents.h"


InputEvents::InputEvents() {
    // Queue
    eventQueue = al_create_event_queue();
    if (!eventQueue)
        throw std::logic_error(could_not_create_event_queue);
    // Vars
    subscribersKeyDown = std::vector<KeySubscribtion>();
    subscribersKeyUp = std::vector<KeySubscribtion>();
    subscribersKeyBeingPressed = std::vector<KeySubscribtion>();
    subscribersDisplayClosed = std::vector<eventfn>();
    subscribersDisplaySwitchedOut = std::vector<eventfn>();
    subscribersTimerTPS = std::vector<TimerSubscription>(); // TODO: Dodaæ dojœcie do event handlera œwiata i chunków (Zostawiæ tu sprawdzania TPS)
    subscribersTimerFPS = std::vector<TimerSubscription>();
    // Timers
    timerTPS = al_create_timer(1.0 / TicksPerSecond);
    timerFPS = al_create_timer(1.0 / FramesPerSecond);
    al_register_event_source(eventQueue, al_get_timer_event_source(timerTPS));
    al_register_event_source(eventQueue, al_get_timer_event_source(timerFPS));
}

void InputEvents::mainLoop(bool *isRunning) { // TODO: Odwróciæ zale¿noœæ i przenieœæ MainLoop -> void mainLoop(inputEvents);
    // Prepare loop
    int64_t ticks;
    al_start_timer(timerTPS);
    al_start_timer(timerFPS);
    // Start loop
    while (*isRunning) {
        al_wait_for_event(eventQueue, &currentEvent);

        switch (currentEvent.type) {

        case ALLEGRO_EVENT_KEY_DOWN: {
            //Input::passKeyDown(currentEvent.keyboard.keycode);
            for (auto ev = subscribersKeyDown.begin(); ev != subscribersKeyDown.end(); ++ev)
                if ((*ev).code == currentEvent.keyboard.keycode) // TODO: Przerobic to na hashmape, nie robic for-if
                    (*ev).func(ev->caller);
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
            *isRunning = false;
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT: {
            // TODO
            al_clear_keyboard_state(currentEvent.display.source);
            break;
        }
        case ALLEGRO_EVENT_TIMER: {
            // Ticks (every TPS)
            ticks = al_get_timer_count(timerTPS);
            for (auto ev = subscribersTimerTPS.begin(); ev != subscribersTimerTPS.end(); ++ev) {
                if (ticks - ev->lastTickExecutedOn >= ev->period) {
                    ev->func(ev->caller);
                    ev->lastTickExecutedOn = ticks;
                }
            }
            // Frames (every FPS)
            ticks = al_get_timer_count(timerFPS);
            for (auto ev = subscribersTimerFPS.begin(); ev != subscribersTimerFPS.end(); ++ev) {
                if (ticks - ev->lastTickExecutedOn >= ev->period) {
                    ev->func(ev->caller);
                    ev->lastTickExecutedOn = ticks;
                }
            }
            break;
        }
        default: {
            // We received an event of some type we don't know about. Just ignore it.
            break;
        }
        }
    }
    // End loop
    al_stop_timer(timerTPS);
}

void InputEvents::registerEventSource(ALLEGRO_EVENT_SOURCE *event_source) {
    al_register_event_source(eventQueue, event_source);
}

void InputEvents::subscribeKeyDown(keycode kc, eventfn fun, void *caller) {
    auto p = KeySubscribtion(kc, fun, caller);
    subscribersKeyDown.push_back(p);
}

void InputEvents::subscribeTimerTPS(tickperiod tp, eventfn fun, void *caller) {
    auto p = TimerSubscription(tp, 0, fun, caller);
    subscribersTimerTPS.push_back(p);
}

void InputEvents::subscribeTimerFPS(tickperiod tp, eventfn fun, void *caller) {
    auto p = TimerSubscription(tp, 0, fun, caller);
    subscribersTimerFPS.push_back(p);
}
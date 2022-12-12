#include "InputEvents.h"


InputEvents::InputEvents() {
    // Queue
    eventQueue = al_create_event_queue();
    if (!eventQueue)
        throw std::logic_error(could_not_create_event_queue);
    // User Events
    userEventSource = new ALLEGRO_EVENT_SOURCE();
    al_init_user_event_source(userEventSource);
    al_register_event_source(eventQueue, userEventSource);
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
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    int64_t ticks;
    al_start_timer(timerTPS);
    al_start_timer(timerFPS);
    // Start loop
    while (*isRunning) {
        al_wait_for_event(eventQueue, currentEvent);

        switch (currentEvent->type) {

        case ALLEGRO_EVENT_KEY_DOWN: {
            //Input::passKeyDown(currentEvent->keyboard.keycode);
            for (auto keySub = subscribersKeyDown.begin(); keySub != subscribersKeyDown.end(); ++keySub)
                keySub->func(currentEvent, keySub->caller);
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {
            //Input::passKeyUp(currentEvent->keyboard.keycode);
            // TODO
            break;
        }
        case ALLEGRO_EVENT_KEY_CHAR: {
            //Input::passChar(currentEvent->keyboard.keycode);
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
            al_clear_keyboard_state(currentEvent->display.source);
            break;
        }
        case ALLEGRO_EVENT_TIMER: {
            // Ticks (every TPS)
            ticks = al_get_timer_count(timerTPS);
            for (auto timerSub = subscribersTimerTPS.begin(); timerSub != subscribersTimerTPS.end(); ++timerSub) {
                if (ticks - timerSub->lastTickExecutedOn >= timerSub->period) {
                    timerSub->func(currentEvent, timerSub->caller);
                    timerSub->lastTickExecutedOn = ticks;
                }
            }
            // Frames (every FPS)
            ticks = al_get_timer_count(timerFPS);
            for (auto timerSub = subscribersTimerFPS.begin(); timerSub != subscribersTimerFPS.end(); ++timerSub) {
                if (ticks - timerSub->lastTickExecutedOn >= timerSub->period) {
                    timerSub->func(currentEvent, timerSub->caller);
                    timerSub->lastTickExecutedOn = ticks;
                }
            }
            break;
        }
        }
        // System event
        if (ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type)) {
            for (auto seSub = subscribersSystemEvents.begin(); seSub != subscribersSystemEvents.end(); ++seSub)
                seSub->func(currentEvent, seSub->caller);
        }
    }
    // End loop
    al_stop_timer(timerTPS);
}

void InputEvents::registerEventSource(ALLEGRO_EVENT_SOURCE *event_source) {
    al_register_event_source(eventQueue, event_source);
}

void InputEvents::subscribeKeyDown(eventfn fun, void *caller) {
    auto p = KeySubscribtion(fun, caller);
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

void InputEvents::subscribeSystemEvent(systemevent se, eventfn fun, void *caller) {
    auto p = SystemEventSubscription { se, fun, caller };
    subscribersSystemEvents.push_back(p);
}

void InputEvents::emitSystemEvent(systemevent eventType, void *data) {
    ALLEGRO_EVENT ae {};
    ae.user.type = eventType;
    ae.user.data1 = (intptr_t)data;
    al_emit_user_event(userEventSource, &ae, NULL);
}

#include "Events.h"

ALLEGRO_EVENT_QUEUE *Events::eventQueue;
ALLEGRO_EVENT Events::currentEvent;
ALLEGRO_TIMER *Events::timerTPS;
ALLEGRO_TIMER *Events::timerFPS;

std::vector<KeySubscribtion> Events::subscribersKeyDown = std::vector<KeySubscribtion>();
std::vector<KeySubscribtion> Events::subscribersKeyUp = std::vector<KeySubscribtion>();
std::vector<KeySubscribtion> Events::subscribersKeyBeingPressed = std::vector<KeySubscribtion>();
std::vector<eventfn> Events::subscribersDisplayClosed = std::vector<eventfn>();
std::vector<eventfn> Events::subscribersDisplaySwitchedOut = std::vector<eventfn>();
std::vector<TimerSubscription> Events::subscribersTimerTPS = std::vector<TimerSubscription>();
std::vector<TimerSubscription> Events::subscribersTimerFPS = std::vector<TimerSubscription>();

void Events::init() {
    eventQueue = al_create_event_queue();
    if (!eventQueue) {
        UI::abortStart("al_create_event_queue failed\n");
    }
    // TPS timer
    timerTPS = al_create_timer(1.0 / TicksPerSecond);
    timerFPS = al_create_timer(1.0 / FramesPerSecond);
    al_register_event_source(eventQueue, al_get_timer_event_source(timerTPS));
    al_register_event_source(eventQueue, al_get_timer_event_source(timerFPS));
}

void Events::mainLoop(bool *isRunning) {
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
                    ev->func();
                    ev->lastTickExecutedOn = ticks;
                }
            }
            // Frames (every FPS)
            ticks = al_get_timer_count(timerFPS);
            for (auto ev = subscribersTimerFPS.begin(); ev != subscribersTimerFPS.end(); ++ev) {
                if (ticks - ev->lastTickExecutedOn >= ev->period) {
                    ev->func();
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

void Events::registerEventSource(ALLEGRO_EVENT_SOURCE *event_source) {
    al_register_event_source(eventQueue, event_source);
}

void Events::subscribeKeyDown(keycode kc, eventfn fun) {
    auto p = KeySubscribtion(kc, fun);
    subscribersKeyDown.push_back(p);
}

void Events::subscribeTimerTPS(tickperiod tp, eventfn fun) {
    auto p = TimerSubscription(tp, 0, fun);
    subscribersTimerTPS.push_back(p);
}

void Events::subscribeTimerFPS(tickperiod tp, eventfn fun) {
    auto p = TimerSubscription(tp, 0, fun);
    subscribersTimerFPS.push_back(p);
}
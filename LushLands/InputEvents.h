#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <vector>
#include "DataTypes.h"
#include "ConstantSets.h"


struct KeySubscribtion {
    keycode code;
    eventfn func;
    void *caller;
};

struct TimerSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    eventfn func;
    void *caller;
};


class InputEvents {
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_EVENT currentEvent;
    ALLEGRO_TIMER *timerTPS;
    ALLEGRO_TIMER *timerFPS;
    // Subscribing to events
    std::vector<KeySubscribtion> subscribersKeyDown;
    std::vector<KeySubscribtion> subscribersKeyUp;
    std::vector<KeySubscribtion> subscribersKeyBeingPressed;
    std::vector<eventfn> subscribersDisplayClosed;
    std::vector<eventfn> subscribersDisplaySwitchedOut;
    std::vector<TimerSubscription> subscribersTimerTPS;
    std::vector<TimerSubscription> subscribersTimerFPS;
public:
    InputEvents();
    void mainLoop(bool *isRunning);
    void registerEventSource(ALLEGRO_EVENT_SOURCE *event_source);

    void subscribeKeyDown(keycode kc, eventfn fun, void *caller);
    void subscribeKeyUp(keycode kc, eventfn fun);
    void subscribeKeyBeingPressed(keycode kc, eventfn fun);
    void subscribeDisplayClosed(eventfn fun);
    void subscribeDisplaySwitchedOut(eventfn fun);
    void subscribeTimerTPS(tickperiod tp, eventfn fun, void *caller);
    void subscribeTimerFPS(tickperiod tp, eventfn fun, void *caller);
};


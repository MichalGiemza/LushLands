#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <vector>
#include "Display.h"
#include "DataTypes.h"


struct KeySubscribtion {
    keycode code;
    eventfn func;
};

struct TimerSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    eventfn func;
};


class Events {
    static ALLEGRO_EVENT_QUEUE *eventQueue;
    static ALLEGRO_EVENT currentEvent;
    static ALLEGRO_TIMER *timerTPS;
    static ALLEGRO_TIMER *timerFPS;
    // Subscribing to events
    static std::vector<KeySubscribtion> subscribersKeyDown;
    static std::vector<KeySubscribtion> subscribersKeyUp;
    static std::vector<KeySubscribtion> subscribersKeyBeingPressed;
    static std::vector<eventfn> subscribersDisplayClosed;
    static std::vector<eventfn> subscribersDisplaySwitchedOut;
    static std::vector<TimerSubscription> subscribersTimerTPS;
    static std::vector<TimerSubscription> subscribersTimerFPS;
public:
    static void init();
    static void mainLoop(bool *isRunning);
    static void registerEventSource(ALLEGRO_EVENT_SOURCE *event_source);

    static void subscribeKeyDown(keycode kc, eventfn fun);
    static void subscribeKeyUp(keycode kc, eventfn fun);
    static void subscribeKeyBeingPressed(keycode kc, eventfn fun);
    static void subscribeDisplayClosed(eventfn fun);
    static void subscribeDisplaySwitchedOut(eventfn fun);
    static void subscribeTimerTPS(tickperiod tp, eventfn fun);
    static void subscribeTimerFPS(tickperiod tp, eventfn fun);
};


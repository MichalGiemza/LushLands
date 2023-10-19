#pragma once
#include "stdafx.h"
#include "Core.h"


class InputEvents {
    ALLEGRO_EVENT_SOURCE *userEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_TIMER *timerTPS;
    ALLEGRO_TIMER *timerFPS;
    Core *core;
    std::unordered_map<keycode, bool> keyStates;
    // Subscribing to events
    std::vector<KeySubscribtion> subscribersKeyDown;
    std::vector<KeySubscribtion> subscribersKeyUp;
    std::vector<KeySubscribtion> subscribersKeyBeingPressed;
    std::vector<KeySubscribtion> subscribersKeyTyped;
    std::vector<eventfn> subscribersDisplayClosed;
    std::vector<eventfn> subscribersDisplaySwitchedOut;
    std::vector<TimerSubscription> subscribersTimerTPS;
    std::vector<TimerSubscription> subscribersTimerFPS;
    std::vector<KeySubscribtion> subscribersMouseDown;
    std::vector<MouseAxisSubscribtion> subscribersMouseAxis;
    std::unordered_map<int, std::vector<SystemEventSubscription>> subscribersSystemEvents;
private:
    void handleBeingPressedEvents();
    void stopAllBeingPressedEvents();
    void beginPressingKey(keycode kc);
    void finishPressingKey(keycode kc);
public:
    InputEvents(Core *core);
    void mainLoop(bool *isRunning);
    void registerEventSource(ALLEGRO_EVENT_SOURCE *event_source);

    void subscribeKeyDown(eventfn fun, void *caller);
    void subscribeKeyUp(eventfn fun, void *caller);
    void subscribeKeyBeingPressed(eventfn fun, void *caller);
    void subscribeKeyTyped(eventfn fun, void *caller);
    void subscribeDisplayClosed(eventfn fun, void *caller);
    void subscribeDisplaySwitchedOut(eventfn fun, void *caller);
    void subscribeMouseClick(eventfn fun, void *caller);
    void subscribeMouseAxis(eventfn fun, void *caller);
    void subscribeTimerTPS(tickperiod tp, eventfn fun, void *caller);
    void subscribeTimerFPS(tickperiod tp, eventfn fun, void *caller);
    void subscribeSystemEvent(systemevent se, eventfn fun, void *caller);

    ALLEGRO_EVENT_SOURCE *getEventSource();
};


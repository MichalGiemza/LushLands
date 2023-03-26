#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <vector>
#include "DataTypes.h"
#include "ConstantSets.h"
#include "EventTypes.h"


class InputEvents {
    ALLEGRO_EVENT_SOURCE *userEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_TIMER *timerTPS;
    ALLEGRO_TIMER *timerFPS;
    // Subscribing to events
    std::vector<KeySubscribtion> subscribersKeyDown;
    std::vector<KeySubscribtion> subscribersKeyUp;
    std::vector<KeySubscribtion> subscribersKeyBeingPressed;
    std::vector<KeySubscribtion> subscribersKeyTyped;
    std::vector<eventfn> subscribersDisplayClosed;
    std::vector<eventfn> subscribersDisplaySwitchedOut;
    std::vector<TimerSubscription> subscribersTimerTPS;
    std::vector<TimerSubscription> subscribersTimerFPS;
    std::vector<SystemEventSubscription> subscribersSystemEvents;
    std::vector<KeySubscribtion> subscribersMouseDown;
    std::vector<MouseAxisSubscribtion> subscribersMouseAxis;
    std::unordered_map<keycode, bool> keyStates;
private:
    void handleBeingPressedEvents();
    void stopAllBeingPressedEvents();
    void beginPressingKey(keycode kc);
    void finishPressingKey(keycode kc);
public:
    InputEvents();
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


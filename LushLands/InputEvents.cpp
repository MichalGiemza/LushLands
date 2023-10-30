#include "InputEvents.h"


void InputEvents::handleBeingPressedEvents() {
    ALLEGRO_EVENT *ev = new ALLEGRO_EVENT;
    for (auto &ks : keyStates) {
        if (ks.second == true) {
            for (auto keySub = subscribersKeyBeingPressed.begin(); keySub != subscribersKeyBeingPressed.end(); ++keySub) {
                ev->keyboard.keycode = ks.first;
                keySub->func(ev, keySub->caller);
            }
        }
    }
}

void InputEvents::stopAllBeingPressedEvents() {
    for (auto ks = keyStates.begin(); ks != keyStates.end(); ++ks)
        ks->second = false;        
}

void InputEvents::beginPressingKey(keycode kc) {
    keyStates[kc] = true;
}

void InputEvents::finishPressingKey(keycode kc) {
    keyStates[kc] = false;
}

InputEvents::InputEvents(Core *core) {  
    // TODO: Czy da³oby siê nie wyci¹gaæ elementów allegro, tylko pozwalaæ zajmowaæ siê tymi rzeczami Core'owi?
    eventQueue = core->getQueue();
    timerTPS = core->getTPSTimer();
    timerFPS = core->getFPSTimer();
    userEventSource = core->getUserEventSource();
    this->core = core;
}

void InputEvents::mainLoop(bool *isRunning) { // TODO: Odwróciæ zale¿noœæ i przenieœæ MainLoop -> void mainLoop(inputEvents);
    // Prepare loop
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    al_start_timer(timerTPS);
    al_start_timer(timerFPS);
    int64_t ticks;
    // Start loop
    while (*isRunning) {
        al_wait_for_event(eventQueue, currentEvent);
        // GUI Event handling
        core->processEvent(*currentEvent);
        core->getGUI()->logic();
        // Event Passing
        switch (currentEvent->type) {
            /*          KEYBOARD          */
        case ALLEGRO_EVENT_KEY_DOWN: {
            //Input::passKeyDown(currentEvent->keyboard.keycode);
            beginPressingKey(currentEvent->keyboard.keycode);
            for (auto keySub = subscribersKeyDown.begin(); keySub != subscribersKeyDown.end(); ++keySub)
                keySub->func(currentEvent, keySub->caller);
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {
            //Input::passKeyUp(currentEvent->keyboard.keycode);
            finishPressingKey(currentEvent->keyboard.keycode);
            for (auto keySub = subscribersKeyUp.begin(); keySub != subscribersKeyUp.end(); ++keySub)
                keySub->func(currentEvent, keySub->caller);
            break;
        }
        case ALLEGRO_EVENT_KEY_CHAR: {
            //Input::passChar(currentEvent->keyboard.keycode);
            for (auto keySub = subscribersKeyTyped.begin(); keySub != subscribersKeyTyped.end(); ++keySub)
                keySub->func(currentEvent, keySub->caller);
            break;
        }
            /*          MOUSE          */
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            for (auto btnSub = subscribersMouseDown.begin(); btnSub != subscribersMouseDown.end(); ++btnSub)
                btnSub->func(currentEvent, btnSub->caller);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES:
        {
            for (auto axSub = subscribersMouseAxis.begin(); axSub != subscribersMouseAxis.end(); ++axSub)
                axSub->func(currentEvent, axSub->caller);
            break;
        }
            /*          DISPLAY          */
        case ALLEGRO_EVENT_DISPLAY_CLOSE: {
            // TODO
            *isRunning = false;
            stopAllBeingPressedEvents();
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT: {
            // TODO
            al_clear_keyboard_state(currentEvent->display.source);
            stopAllBeingPressedEvents();
            break;
        }
            /*          TIMER          */
        case ALLEGRO_EVENT_TIMER: {
            if (currentEvent->timer.source == timerTPS) {
                // Ticks (every TPS)
                ticks = al_get_timer_count(timerTPS);
                for (auto timerSubTPS = subscribersTimerTPS.begin(); timerSubTPS != subscribersTimerTPS.end(); ++timerSubTPS) {
                    if (ticks - timerSubTPS->lastTickExecutedOn >= timerSubTPS->period) {
                        timerSubTPS->func(currentEvent, timerSubTPS->caller);
                        timerSubTPS->lastTickExecutedOn = ticks;
                    }
                }
                break;
            }
            if (currentEvent->timer.source == timerFPS) {
                // Frames (every FPS)
                handleBeingPressedEvents();
                ticks = al_get_timer_count(timerFPS);
                for (auto timerSubFPS = subscribersTimerFPS.begin(); timerSubFPS != subscribersTimerFPS.end(); ++timerSubFPS) {
                    if (ticks - timerSubFPS->lastTickExecutedOn >= timerSubFPS->period) {
                        timerSubFPS->func(currentEvent, timerSubFPS->caller);
                        timerSubFPS->lastTickExecutedOn = ticks;
                    }
                }
                break;
            }
        }
            /*          ACTIONS          */
        }
        // System event
        if (ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type)) {
            for (auto &seSub : subscribersSystemEvents[currentEvent->type])
                seSub.func(currentEvent, seSub.caller);
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

void InputEvents::subscribeKeyBeingPressed(eventfn fun, void *caller) {
    auto p = KeySubscribtion(fun, caller);
    subscribersKeyBeingPressed.push_back(p);
}

void InputEvents::subscribeKeyTyped(eventfn fun, void *caller) {
    auto p = KeySubscribtion(fun, caller);
    subscribersKeyTyped.push_back(p);
}

void InputEvents::subscribeMouseClick(eventfn fun, void *caller) {
    auto p = KeySubscribtion(fun, caller);
    subscribersMouseDown.push_back(p);
}

void InputEvents::subscribeMouseAxis(eventfn fun, void *caller) {
    auto p = MouseAxisSubscribtion(fun, caller);
    subscribersMouseAxis.push_back(p);
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
    if (not ALLEGRO_EVENT_TYPE_IS_USER(se))
        throw std::logic_error(user_event_was_expected);
    std::vector<SystemEventSubscription> *seVec = &subscribersSystemEvents[se];
    auto p = SystemEventSubscription { se, fun, caller };
    seVec->push_back(p);
}

ALLEGRO_EVENT_SOURCE *InputEvents::getEventSource() {
    return userEventSource;
}


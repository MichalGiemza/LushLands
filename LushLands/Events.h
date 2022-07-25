#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include "Display.h"
#include "Input.h"


class Events {
    static ALLEGRO_EVENT_QUEUE *eventQueue;
    static ALLEGRO_EVENT currentEvent;
public:
    static void init();
    static void mainLoop();
    static void registerEventSource(ALLEGRO_EVENT_SOURCE *event_source);
};


#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/display.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include "UserInterface.h"
#include "Events.h"

class Display {
    static ALLEGRO_DISPLAY *display;
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static double old_time;
    static double currentFPS;

public:
    static ALLEGRO_DISPLAY *getDisplay();
    static void init();
    static void clearDisplay();
    static void updateTrackingFPS();
    static double getCurrentFPS();
};

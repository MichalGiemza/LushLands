#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/display.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include "UserInterface.h"
#include "Events.h"
#include "Logger.h"

class Display {
    static ALLEGRO_DISPLAY *display;
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static double oldTimeFPS;
    static double oldTimeTPS;
    static double currentFPS;
    static double currentTPS;

public:
    static ALLEGRO_DISPLAY *getDisplay();
    static void init();
    static void clearDisplay();
    static void updateTrackingFPS();
    static void updateTrackingTPS();
    static double getCurrentFPS();
    static double getCurrentTPS();
};

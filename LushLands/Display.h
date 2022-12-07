#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/display.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include "InputEvents.h"
#include "Logger.h"
#include "ConstantSets.h"


class Display {
    ALLEGRO_DISPLAY *display;
    double oldTimeFPS;
    double oldTimeTPS;
    double currentFPS;
    double currentTPS;
private:
    void registerFPSAndTPSMeters(InputEvents *inputEvents);
    friend void updateTrackingFPS(void *display);
    friend void updateTrackingTPS(void *display);
public:
    ALLEGRO_DISPLAY *getDisplay();
    Display(InputEvents *inputEvents);
    void clearDisplay();
    double getCurrentFPS();
    double getCurrentTPS();
};

void updateTrackingFPS(void *display);
void updateTrackingTPS(void *display);

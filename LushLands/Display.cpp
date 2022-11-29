#include "Display.h"

ALLEGRO_DISPLAY *Display::display;
double Display::oldTimeFPS;
double Display::currentFPS;
double Display::oldTimeTPS;
double Display::currentTPS;

ALLEGRO_DISPLAY *Display::getDisplay() {
    return display;
}

void Display::init() {
    display = al_create_display(Display::WIDTH, Display::HEIGHT);
    if (!display) {
        UserInterface::abortStart("al_create_display failed\n");
    }
    Events::registerEventSource(al_get_display_event_source(Display::getDisplay()));
    oldTimeFPS = al_get_time();
    oldTimeTPS = al_get_time();
    currentFPS = 0.0;
    currentTPS = 0.0;
    Events::subscribeTimerFPS(1, updateTrackingFPS);
    Events::subscribeTimerTPS(1, updateTrackingTPS);
}

void Display::clearDisplay() {
    al_clear_to_color(al_map_rgb(255, 255, 255));
}

void Display::updateTrackingFPS() {
    double newTime = al_get_time();
    currentFPS = 1 / (newTime - oldTimeFPS);
    oldTimeFPS = newTime;
    //Logger::log("FPS: [%f]", currentFPS);
}

void Display::updateTrackingTPS() {
    double newTime = al_get_time();
    currentFPS = 1 / (newTime - oldTimeTPS);
    oldTimeTPS = newTime;
    //Logger::log("TPS: [%f]", currentFPS);
}

double Display::getCurrentFPS() {
    return currentFPS;
}

double Display::getCurrentTPS() {
    return currentTPS;
}

#include "Display.h"

ALLEGRO_DISPLAY *Display::display;
double Display::old_time;
double Display::currentFPS;

ALLEGRO_DISPLAY *Display::getDisplay() {
    return display;
}

void Display::init() {
    display = al_create_display(Display::WIDTH, Display::HEIGHT);
    if (!display) {
        UserInterface::abortStart("al_create_display failed\n");
    }
    Events::registerEventSource(al_get_display_event_source(Display::getDisplay()));
    old_time = al_get_time();
    currentFPS = 0.0;
}

void Display::clearDisplay() {
    al_clear_to_color(al_map_rgb(255, 255, 255));
}

void Display::updateTrackingFPS() {
    double new_time = al_get_time();
    double delta = new_time - old_time;
    currentFPS = 1 / (delta * 1000);
    old_time = new_time;
}

double Display::getCurrentFPS() {
    return currentFPS;
}

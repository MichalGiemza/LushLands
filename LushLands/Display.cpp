#include "Display.h"

ALLEGRO_DISPLAY *Display::getDisplay() {
    return display;
}

Display::Display(InputEvents *inputEvents) {
    display = al_create_display(displayWidth, displayHeight);
    al_clear_to_color(al_map_rgb_f(0, 0, 0)); 
    al_flip_display(); 
    if (!display)
        throw std::logic_error(could_not_create_display);
    if (!al_init_primitives_addon())
        throw std::logic_error(could_not_init_primitives);

    registerFPSAndTPSMeters(inputEvents);
}

void Display::registerFPSAndTPSMeters(InputEvents *inputEvents) {
    inputEvents->registerEventSource(al_get_display_event_source(getDisplay()));
    oldTimeFPS = al_get_time();
    oldTimeTPS = al_get_time();
    currentFPS = 0.0;
    currentTPS = 0.0;
    inputEvents->subscribeTimerFPS(1, updateTrackingFPS, this);
    inputEvents->subscribeTimerTPS(1, updateTrackingTPS, this);
}

void Display::clearDisplay() {
    al_clear_to_color(al_map_rgb(255, 255, 255));
}

void updateTrackingFPS(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Display *d = (Display *)caller;
    double newTime = al_get_time();
    d->currentFPS = 1 / (newTime - d->oldTimeFPS);
    d->oldTimeFPS = newTime;
    //Logger::log("FPS: [%f]", currentFPS);
}

void updateTrackingTPS(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Display *d = (Display *)caller;
    double newTime = al_get_time();
    d->currentFPS = 1 / (newTime - d->oldTimeTPS);
    d->oldTimeTPS = newTime;
    //Logger::log("TPS: [%f]", currentFPS);
}

double Display::getCurrentFPS() {
    return currentFPS;
}

double Display::getCurrentTPS() {
    return currentTPS;
}

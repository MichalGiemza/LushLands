#include "Mouse.h"

Mouse::Mouse(InputEvents *inputEvents) {
    this->inputEvents = inputEvents;

    if (!al_install_mouse())
        throw std::logic_error(could_not_install_mouse);
    inputEvents->registerEventSource(al_get_mouse_event_source());
}

void Mouse::addCursor(ALLEGRO_BITMAP *cursorBmp) {
    cursor = al_create_mouse_cursor(cursorBmp, 3, 5); // x,y for this exact cursor
}

ALLEGRO_MOUSE_CURSOR *Mouse::getCursor() {
    return cursor;
}


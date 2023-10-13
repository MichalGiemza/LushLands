#include "stdafx.h"
#include "Keyboard.h"

Keyboard::Keyboard(InputEvents *inputEvents) {
    this->inputEvents = inputEvents;

    if (!al_install_keyboard())
        throw std::logic_error(could_not_install_keyboard);
    inputEvents->registerEventSource(al_get_keyboard_event_source());
}

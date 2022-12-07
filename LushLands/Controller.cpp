#include "Controller.h"

Controller::Controller(InputEvents *inputEvents) {
    this->inputEvents = inputEvents;
    Controller::hookKeysToActions();

    if (!al_install_keyboard())
        throw std::logic_error(could_not_install_keyboard);
    inputEvents->registerEventSource(al_get_keyboard_event_source());
}

void Controller::hookKeysToActions() {
    auto am = ActionMap::getActionMap();
    for (auto itr = am.begin(); itr != am.end(); ++itr)
        inputEvents->subscribeKeyDown(itr->first, Actions::mapActionCodeToFunction(itr->second), this);
}


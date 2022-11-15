#include "Controller.h"
#include "Events.h"
#include "ActionMap.h"

void Controller::init() {
    Controller::hookKeysToActions();

    if (!al_install_keyboard()) {
        UI::abortStart("al_install_keyboard failed\n");
    }
    Events::registerEventSource(al_get_keyboard_event_source());
}

void Controller::hookKeysToActions() {
    auto am = ActionMap::getActionMap();
    for (auto itr = am.begin(); itr != am.end(); ++itr)
        Events::subscribeKeyDown(
            itr->first, Actions::mapActionCodeToFunction(itr->second));
}


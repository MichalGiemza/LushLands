#include "Input.h"

std::map<int, std::function<void(int)>> Input::bindingsKeyDown;
std::map<int, std::function<void(int)>> Input::bindingsKeyUp;
std::map<int, std::function<void(int)>> Input::bindingsChar;

void Input::init() {
    if (!al_install_keyboard()) {
        UI::abortStart("al_install_keyboard failed\n");
    }
    Events::registerEventSource(al_get_keyboard_event_source());

    bindingsKeyDown = std::map<int, std::function<void(int)>>();
    bindingsKeyUp = std::map<int, std::function<void(int)>>();
    bindingsChar = std::map<int, std::function<void(int)>>();
}

void Input::passKeyDown(int keyCode) {
    if (bindingsKeyDown.contains(keyCode))
        bindingsKeyDown[keyCode](keyCode);
}

void Input::passKeyUp(int keyCode) {
    if (bindingsKeyUp.contains(keyCode))
        bindingsKeyUp[keyCode](keyCode);
}

void Input::passChar(int keyCode) {
    if (bindingsChar.contains(keyCode))
        bindingsChar[keyCode](keyCode);
}

void Input::assignActionToKeyDown(int al_key_code, std::function<void(int)> action) {
    bindingsKeyDown[al_key_code] = action;
}

void Input::assignActionToKeyUp(int al_key_code, std::function<void(int)> action) {
    bindingsKeyUp[al_key_code] = action;
}

void Input::assignActionToChar(int al_key_code, std::function<void(int)> action) {
    bindingsChar[al_key_code] = action;
}

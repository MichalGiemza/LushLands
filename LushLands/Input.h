#pragma once
#include <allegro5/keycodes.h>
#include <allegro5/system.h>
#include <map>
#include <functional>
#include "Display.h"
#include "UserInterface.h"
#include "Events.h"

class Input {
    static std::map<int, std::function<void(int)>> bindingsKeyDown;
    static std::map<int, std::function<void(int)>> bindingsKeyUp;
    static std::map<int, std::function<void(int)>> bindingsChar;

public:
    static void init();
    static void passKeyDown(int keyCode);
    static void passKeyUp(int keyCode);
    static void passChar(int keyCode);
    static void assignActionToKeyDown(int al_key_code, std::function<void(int)> action);
    static void assignActionToKeyUp(int al_key_code, std::function<void(int)> action);
    static void assignActionToChar(int al_key_code, std::function<void(int)> action);
    static int waitForFirstKeyDown();
};

#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <cstdio>
#include "Display.h"
#include "Controller.h"
    
class UserInterface {
public:
    static void init();
    static void abortStart(char const *format, ...);
};

typedef UserInterface UI;

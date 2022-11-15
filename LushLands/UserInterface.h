#pragma once
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <cstdio>
    
class UserInterface {
public:
    static bool initialized;
    static bool running;

    static void abortStart(char const *format, ...);
    static void stopRunning();
};

typedef UserInterface UI;

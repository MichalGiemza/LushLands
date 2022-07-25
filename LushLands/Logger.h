#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdarg.h>

class Logger {
    static ALLEGRO_FONT *font;
    static ALLEGRO_TEXTLOG *textlog;
public:
    static void logKey(char const *how, int keycode, int unichar, int modifiers);
    static void openLogMonospace(void);
    static void logPrintf(char const *format, ...);
    static void closeLog(bool wait_for_user);

    static void init();
    static void destruct();
};


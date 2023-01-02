#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include "DataTypes.h"
#include "ConstantSets.h"

class Logger {
    /**
    * Logger is a static class responsible for logging game activity.
    *  - Uses log levels defined in ConstantsSets.h
    */
    static ALLEGRO_FONT *font;
    static ALLEGRO_TEXTLOG *textlog;
    static std::vector<LoggerSubscription> logSubscribers;
    static loglevel logLevel;
public:
    static void subscribe(loglevel logLevel, std::function<void(void *caller, char *str)> func, void *caller);
    static void logKey(loglevel logLevel, char const *how, int keycode, int unichar=0, int modifiers=0);
    static void logAction(loglevel logLevel, actioncode acode);
    static void openLogMonospace(void);
    static void logPrintf(loglevel logLevel, char const *format, ...);
    static void log(loglevel logLevel, char const *format, ...);
    static void closeLog(bool wait_for_user);
    static void logAbort(char const *format, ...);

    static void init();
    static void destruct();
};


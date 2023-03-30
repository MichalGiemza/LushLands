#pragma once
#include "StaticUIElement.h"
#include "Logger.h"
#include "Display.h"
#include "TextureManager.h"
#include "ConstantSets.h"
#include "Colors.h"
#include <vector>
#include <string>

struct ConsoleLine {
    std::shared_ptr<char[]> text;
    ALLEGRO_COLOR color;
};

class Console : StaticUIElement {
    /**
    * Console represented as static User Interface element.
    * Allows users to chat and server staff members to control gameplay.
    */
    std::vector<ConsoleLine> currentChat;
    loglevel logLevel;
    short chatLength = CHAT_LENGTH;

    ALLEGRO_BITMAP *bitmapCache = 0;
    bool bitmapToRedraw = true;
    Display *display;
    TextureManager *textureManager;
    ALLEGRO_FONT *font;
private:
    int determineChatH();
    int determineChatW();
public:
    Console(Display *display, TextureManager *textureManager);
    friend void handleLogMessage(void *caller, char *str);
    void draw();
};

void handleLogMessage(void *caller, char *str);

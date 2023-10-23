#pragma once
#include "stdafx.h"
#include "StaticUIElement.h"
#include "Display.h"
#include "TextureManager.h"

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
    ALLEGRO_FONT *font;
private:
    int determineChatH();
    int determineChatW();
public:
    Console(Display *display);
    friend void handleLogMessage(void *caller, char *str);
    void draw();
};

void handleLogMessage(void *caller, char *str);

#include "stdafx.h"
#include "Console.h"

int Console::determineChatH() {
    return displayHeight / 2;
}

int Console::determineChatW() {
    return displayWidth / 3;
}

Console::Console(Display *display, TextureManager *textureManager) : StaticUIElement(ft::CONSOLE, fp::CONSOLE) {
    this->textureManager = textureManager;
    this->display = display;
    if (DEBUG)
        logLevel = lg::DEBUG_ALL;
    currentChat = std::vector<ConsoleLine>();
    Logger::subscribe(logLevel, handleLogMessage, this);
    font = al_load_ttf_font(fontLambdaRegular, 16, 0);
    bitmapCache = al_create_bitmap(determineChatW(), determineChatH());
}

void Console::draw() {
    // Fading effect
    for (int i = 0; i < currentChat.size(); i++) {
        currentChat[i].color.a = std::max(currentChat[i].color.a - 0.002f, 0.0f);
        currentChat[i].color.r = currentChat[i].color.a;
        currentChat[i].color.g = currentChat[i].color.a;
        currentChat[i].color.b = currentChat[i].color.a;
        bitmapToRedraw |= currentChat[i].color.a > 0;
    }

    // Actual drawing
    if (bitmapToRedraw) {
        auto backbuffer = al_get_backbuffer(display->getDisplay());
        al_set_target_bitmap(bitmapCache);
        al_clear_to_color(TRANSPARENT_COLOR.getAllegroColor());
        for (int i = 0; i < currentChat.size(); i++) {
            al_draw_text(font, currentChat[i].color, 10, 10 + 12 * i, 0, currentChat[i].text.get());
        }
        al_set_target_bitmap(backbuffer);
        bitmapToRedraw = false;
    }
    al_draw_bitmap(bitmapCache, 0, 0, 0);
}

void handleLogMessage(void *caller, char *str) {
    auto c = (Console *)caller;
    ConsoleLine cl = { std::shared_ptr<char[]>(str), CHAT_GRAY_COLOR.getAllegroColor() };
    
    c->currentChat.insert(c->currentChat.begin(), cl);
    if (c->currentChat.size() > c->chatLength) {
        c->currentChat.pop_back();
    }
    c->bitmapToRedraw = true;
}


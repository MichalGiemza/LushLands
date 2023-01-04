#include "Console.h"

int Console::determineChatH() {
    return displayHeight / 2;
}

int Console::determineChatW() {
    return displayWidth / 3;
}

Console::Console(Display *display, TextureManager *textureManager) : StaticUIElement(f::CONSOLE, fp::CONSOLE) {
    this->textureManager = textureManager;
    this->display = display;
    if (DEBUG)
        logLevel = ll::DEBUG_ALL;
    currentChat = std::vector<consoleline>();
    Logger::subscribe(logLevel, handleLogMessage, this);
    font = al_load_ttf_font(openSansSBFont, 10, 0);
    bitmapCache = al_create_bitmap(determineChatW(), determineChatH());
}

void Console::draw() {
    if (bitmapToRedraw) {
        auto backbuffer = al_get_backbuffer(display->getDisplay());
        al_set_target_bitmap(bitmapCache);
        al_clear_to_color(TRANSPARENT_COLOR.getAllegroColor());
        for (int i = 0; i < currentChat.size(); i++) {
            auto line = currentChat[i].get();
            al_draw_text(font, CHAT_GRAY_COLOR.getAllegroColor(), 10, 10 + 12 * i, 0, line);
        }
        al_set_target_bitmap(backbuffer);
        bitmapToRedraw = false;
    }
    al_draw_bitmap(bitmapCache, 0, 0, 0);
}

void handleLogMessage(void *caller, consoleline str) {
    auto c = (Console *)caller;
    c->currentChat.insert(c->currentChat.begin(), str);
    if (c->currentChat.size() > c->chatLength) {
        c->currentChat.pop_back();
    }
    c->bitmapToRedraw = true;
}


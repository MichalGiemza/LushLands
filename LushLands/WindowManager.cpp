#include "WindowManager.h"

WindowManager::WindowManager(InputEvents *ie) :
    ie(ie) {
    ie->subscribeSystemEvent(user_interact, handleInteract, this);
    ie->subscribeSystemEvent(user_open_context_menu, handleOpenContextMenu, this);
}

void WindowManager::addWindow(StaticBaseWindow *window) {
    staticWindows.insert(window);
}

void WindowManager::rmWindow(StaticBaseWindow *window) {
    staticWindows.erase(window);
}

void WindowManager::drawWindows() {
    for (auto *w : staticWindows)
        w->draw();
}

void handleInteract(ALLEGRO_EVENT *allegroEvent, void *caller) {
    WindowManager *wm = (WindowManager *)caller;
    pxint x, y;
    EventFactory::unpackMouseAction(allegroEvent, &x, &y);
    // Static Windows
    StaticBaseWindow *sw = 0;
    for (auto *w : wm->staticWindows)
        if (w->screenPositionWithinBorders(x, y)) {
            sw = w;
            break;
        }
    if (sw) {
        sw->interact(x, y);
        return;
    }
    // World Windows
    // TODO
}

void handleOpenContextMenu(ALLEGRO_EVENT *allegroEvent, void *caller) {
    WindowManager *wm = (WindowManager *)caller;
    pxint x, y;
    EventFactory::unpackMouseAction(allegroEvent, &x, &y);
    // Static Windows
    StaticBaseWindow *sw = 0;
    for (auto *w : wm->staticWindows)
        if (w->screenPositionWithinBorders(x, y)) {
            sw = w;
            break;
        }
    if (sw) {
        sw->openContextMenu(x, y);
        return;
    }
    // World Windows
    // TODO
}

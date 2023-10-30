#include "WindowManager.h"

namespace agui {

    WindowManager::WindowManager() {}

    void WindowManager::addWindow(Widget *window) {
        staticWindows.insert(window);
    }

    void WindowManager::rmWindow(Widget *window) {
        staticWindows.erase(window);
    }
}

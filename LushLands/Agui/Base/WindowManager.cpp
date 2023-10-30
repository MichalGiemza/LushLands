#include "WindowManager.h"

namespace agui {

    WindowManager::WindowManager(Gui *gui) : gui(gui) {}

    void WindowManager::addWindow(Widget *window) {
        staticWindows.insert(window);
        gui->add(window);
    }

    void WindowManager::rmWindow(Widget *window) {
        staticWindows.erase(window);
        gui->remove(window);
    }
}

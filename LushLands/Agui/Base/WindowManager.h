#pragma once
#include <set>
#include "Agui/Widget.hpp"
#include "Agui/Gui.hpp"

namespace agui {

    class WindowManager {
        /**
        * Class is responsible for managing static and dynamic ui windows.
        */
        std::set<Widget *> staticWindows;
        Gui *gui;
    public:
        WindowManager(Gui *gui);
        void addWindow(Widget *window);
        void rmWindow(Widget *window);
    };
}

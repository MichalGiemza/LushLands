#pragma once
#include <set>
#include <Agui/Widget.hpp>

namespace agui {

    class WindowManager {
        /**
        * Class is responsible for managing static and dynamic ui windows.
        */
        std::set<Widget *> staticWindows;
    public:
        WindowManager();
        void addWindow(Widget *window);
        void rmWindow(Widget *window);
    };
}

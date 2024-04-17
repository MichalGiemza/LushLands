#pragma once
#include "Agui/Base/BaseWindow.h"
#include "Agui/Enumerations.hpp"
#include <Core.h>
#include <InputEvents.h>
#include <Agui/Widgets/Button/Button.hpp>
#include <string>
#include "MenuActionListeners.h"


class PauseMenu : public agui::BaseWindow {
    /**
    * Popup menu called during gameplay with [Esc] key.
    */
    const pxint w = displayWidth / 3;
    const pxint h = displayHeight * 3 / 4;
    const int vm = h / 16;
    const int hm = w / 4;
    const pxint margin = 4;

    static const int nBtns = 5;
    const std::string btnTxt[nBtns] = { "Resume", "Save", "Load", "Settings", "Exit" };
    agui::Button btn[nBtns];
    agui::Font *menuFont = NULL;

    Core *core;
    InputEvents *inputEvents;

public:
    PauseMenu(Core *core, InputEvents *inputEvents);
};


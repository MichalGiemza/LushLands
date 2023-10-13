#pragma once
#include "stdafx.h"
#include "StaticBaseWindow.h"
#include "InputEvents.h"
#include "EventFactory.h"


class WindowManager {
    /** 
    * Class is responsible for managing static and dynamic ui windows.
    */
    std::set<StaticBaseWindow *> staticWindows;
    // TODO: World windows
    InputEvents *ie;
public:
    WindowManager(InputEvents *inputEvents);
    void addWindow(StaticBaseWindow *window);
    void rmWindow(StaticBaseWindow *window);
    void drawWindows();

    friend void handleInteract(ALLEGRO_EVENT *allegroEvent, void *caller);
    friend void handleOpenContextMenu(ALLEGRO_EVENT *allegroEvent, void *caller);
};

void handleInteract(ALLEGRO_EVENT *allegroEvent, void *caller);
void handleOpenContextMenu(ALLEGRO_EVENT *allegroEvent, void *caller);

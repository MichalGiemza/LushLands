#pragma once
#include "Agui/Agui.hpp"
#include "Agui/Backends/Allegro5/Allegro5.hpp"
#include "Agui/TextureManager.h"
#include "ConstantSets.h"
#include "Logger.h"


class Core {
    /**
    * Handler for basic systems
    *  - Allegro5
    *  - AGUI (with Allegro5 backend)
    */
private:
    // Allegro
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timerTPS = NULL;
    ALLEGRO_TIMER *timerFPS = NULL;
    ALLEGRO_EVENT_SOURCE *userEventSource = NULL;
    // Agui
    agui::Gui *gui = NULL;
    agui::Allegro5Input *inputHandler = NULL;
    agui::Allegro5Graphics *graphicsHandler = NULL;
    agui::Font *defaultFont = NULL;
private:
    bool initAllegro();
    void initAgui();
public:
    Core();
    void processEvent(const ALLEGRO_EVENT &ev);
    agui::Gui *getGUI();
    ALLEGRO_EVENT_QUEUE *getQueue();
    ALLEGRO_TIMER *getFPSTimer();
    ALLEGRO_TIMER *getTPSTimer();
    ALLEGRO_EVENT_SOURCE *getUserEventSource();
    ALLEGRO_DISPLAY *getDisplay();
};


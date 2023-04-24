#pragma once
#include <windows.h>
#include <iostream>
#include <exception>
#include <allegro5/system.h>
#include "Controller.h"
#include "Logger.h"
#include "ActionMap.h"
#include "ActionMap.h"
#include "Simulation.h"
#include "GraphicsManager.h"
#include "Controller.h"
#include "EventHandler.h"


extern bool initialized;
extern bool running;

extern Controller *controller;
extern GraphicsManager *graphicsManager;
extern Simulation *simulation;
extern EventHandler *eventHandler;

void init();
void main_loop();

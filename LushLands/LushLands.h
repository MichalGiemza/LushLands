#pragma once
#include <windows.h>
#include <iostream>
#include <exception>
#include <allegro5/system.h>
#include "Controller.h"
#include "Logger.h"
#include "ActionMap.h"
#include "SimulationEventHandler.h"
#include "ActionMap.h"
#include "Simulation.h"
#include "GraphicsManager.h"

extern bool initialized;
extern bool running;
extern InputEvents *inputEvents;
extern Controller *controller;
extern GraphicsManager *graphicsManager;
extern Simulation *simulation;


void init();
void main_loop();

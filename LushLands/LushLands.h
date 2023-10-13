#pragma once
#include "stdafx.h"
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
#include "Core.h"


extern bool initialized;
extern bool running;

extern Core *core;
extern Controller *controller;
extern GraphicsManager *graphicsManager;
extern Simulation *simulation;
extern EventHandler *eventHandler;

void init();
void main_loop();

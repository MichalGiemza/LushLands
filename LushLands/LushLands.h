#pragma once
#include <windows.h>
#include <iostream>
#include <exception>
#include <allegro5/system.h>
#include "UserInterface.h"
#include "Logger.h"
#include "ActionMap.h"
#include "SimulationEventHandler.h"
#include "DataMappers.h"
#include "Simulation.h"
#include "GraphicsManager.h"

extern bool initialized;
extern bool running;

void init();
void main_loop();

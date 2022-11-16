#include "Simulation.h"
#include "ConstantSets.h"

World *Simulation::world = 0;

void Simulation::init() {
    Simulation::world = new World(FLATLAND, 42);
}

#include "Actions.h"
#include "Logger.h"


eventfn Actions::mapActionCodeToFunction(actioncode ac) {
    if (ac == GO_NORTH)
        return Actions::goNorth;
    if (ac == GO_SOUTH)
        return Actions::goSouth;
    if (ac == GO_WEST)
        return Actions::goWest;
    if (ac == GO_EAST)
        return Actions::goEast;
    if (ac == USE)
        return Actions::use;
    return 0;
}

void Actions::goNorth() {
    // TODO - po��czy� z Control Node
    Logger::logAction(GO_NORTH);
}

void Actions::goSouth() {
    // TODO - po��czy� z Control Node
    Logger::logAction(GO_SOUTH);
}

void Actions::goWest() {
    // TODO - po��czy� z Control Node
    Logger::logAction(GO_WEST);
}

void Actions::goEast() {
    // TODO - po��czy� z Control Node
    Logger::logAction(GO_EAST);
}

void Actions::use() {
    // TODO - po��czy� z Control Node
    Logger::logAction(USE);
}

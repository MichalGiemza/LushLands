#pragma once
#include "DataTypes.h"

const actioncode GO_NORTH = "go_north";
const actioncode GO_SOUTH = "go_south";
const actioncode GO_WEST = "go_west";
const actioncode GO_EAST = "go_east";
const actioncode USE = "use";


class Actions {
    /**
    * Methods are being used following way:
    *  - called by keyboardkey->Events->
    */
public:
    // TODO: Wejdzie jeszcze kontekst (controller -> context -> action)
    static eventfn mapActionCodeToFunction(actioncode ac);

    static void goNorth(); 
    static void goSouth(); 
    static void goWest(); 
    static void goEast();
    static void use();

};


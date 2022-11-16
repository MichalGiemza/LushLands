#pragma once
#include "DataTypes.h"
#include "ConstantSets.h"


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


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

    static void goNorth(void *obj);
    static void goSouth(void *obj);
    static void goWest(void *obj);
    static void goEast(void *obj);
    static void use(void *obj);

};


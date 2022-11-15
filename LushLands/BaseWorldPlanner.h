#pragma once
#include "Position.h"

struct FieldPlan {
    string ground;
    string structure;
    string animal;
};

class BaseWorldPlanner {
    /** 
    * Obiekty tej klasy odpowiedzialne s� za planowanie generowania �wiata gry.
    * 
    * Planowanie �wiata musi odbywa� si� w spos�b deterministyczny. 
    */
public:
    virtual FieldPlan getFieldPlan(Position position);
    virtual int getSeaLevel();
};

#pragma once
#include "Position.h"

struct FieldPlan {
    string ground;
    string structure;
    string animal;
};

class BaseWorldPlanner {
    /** 
    * Obiekty tej klasy odpowiedzialne s¹ za planowanie generowania œwiata gry.
    * 
    * Planowanie œwiata musi odbywaæ siê w sposób deterministyczny. 
    */
public:
    virtual FieldPlan getFieldPlan(Position position);
    virtual int getSeaLevel();
};

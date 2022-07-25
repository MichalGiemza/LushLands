#pragma once
#include "IControlNode.h"
#include "Input.h"

class Actions {
public:
    static IControlNode *controlNode;
    static void subscribeGoNorthAction(int keyCode);
    static void subscribeGoSouthAction(int keyCode);
    static void subscribeGoEastAction(int keyCode);
    static void subscribeGoWestAction(int keyCode);
};


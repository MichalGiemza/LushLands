#include "Actions.h"

IControlNode *Actions::controlNode;

void Actions::subscribeGoNorthAction(int keyCode) {
    Input::assignActionToKeyDown(keyCode, [=](int _) {Actions::controlNode->goNorth(_); });
}

void Actions::subscribeGoSouthAction(int keyCode) {
    Input::assignActionToKeyDown(keyCode, [=](int _) {Actions::controlNode->goSouth(_); });
}

void Actions::subscribeGoEastAction(int keyCode) {
    Input::assignActionToKeyDown(keyCode, [=](int _) {Actions::controlNode->goEast(_); });
}

void Actions::subscribeGoWestAction(int keyCode) {
    Input::assignActionToKeyDown(keyCode, [=](int _) {Actions::controlNode->goWest(_); });
}

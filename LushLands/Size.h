#pragma once
#include "Constants.h"

class Size {
    int width;  // X
    int height; // Y
    int length; // Z
public:
    Size(int width, int height, int length);
    int getWidth();
    int getHeight();
    int getLength();
    int getAccurateWidth();
    int getAccurateHeight();
    int getAccurateLength();
    int w();
    int h();
    int l();
    void setWidth(int width);
    void setHeight(int height);
    void setLength(int length);
};


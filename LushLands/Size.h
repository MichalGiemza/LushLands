#pragma once
#include "Constants.h"
#include "DataTypes.h"

class Size {
    int width;  // X
    int height; // Y
    int length; // Z
public:
    Size(int width, int height, int length, bool accurate = false);
    Size(float width, float height, float length, bool accurate = false);
    int getWidth();
    int getHeight();
    int getLength();
    int getAccurateWidth() const;
    int getAccurateHeight() const;
    int getAccurateLength() const;
    void setAccurateWidth(int width);
    void setAccurateHeight(int height);
    void setAccurateLength(int length);
    void setAccurateWidth(float width);
    void setAccurateHeight(float height);
    void setAccurateLength(float length);
    int w() const;
    int h() const;
    int l() const;
    void setWidth(int width);
    void setHeight(int height);
    void setLength(int length);
    void setWidth(float width);
    void setHeight(float height);
    void setLength(float length);
    pxint getCameraW();
    pxint getCameraL();
    bool operator==(const Size &other) const;
};


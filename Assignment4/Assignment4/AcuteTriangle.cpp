#include "AcuteTriangle.h"


AcuteTriangle::AcuteTriangle(int base, char pen, string name)
    : Triangle{ base % 2 == 1 ? base : base + 1, pen, name } {}

AcuteTriangle::~AcuteTriangle() {};


int AcuteTriangle::getHeight() const {
    return (base + 1) / 2;
}

int AcuteTriangle::getWidth() const {
    return base;
}

//returns geometric perimeter
double AcuteTriangle::perimeterGeo() const {
    return base + std::sqrt(base * base + 4 * getHeight() * getHeight());
}

//returns screen area
double AcuteTriangle::areaScr() const {
    return getHeight() * getHeight();
}

//returns screen perimeter
double AcuteTriangle::perimeterScr() const {
    return 4 * (getHeight() - 1);
}


Canvas AcuteTriangle::draw() const {
    Canvas drawGrid{ getHeight(), getWidth() };

    int h = getHeight();
    int b = getWidth();

    // initiallize left blank space and right blank space
    
    int LSpace;
    int RSpace;
    //  LSpace and RSpace - both has col number 1/2 of base
    LSpace = RSpace = b / 2;

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col <= b; ++col) {
            if (col >= LSpace && col <= RSpace) {
                // check if LSpace < col < RSpace
                drawGrid.put(row, col, pen);
            }
        }
        LSpace--; // left space col number will decrement with increasing row count
        RSpace++; // right space col number will increment with increasing row count
    }
    return drawGrid;
}

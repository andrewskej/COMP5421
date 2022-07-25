#include "RightTriangle.h"

RightTriangle::RightTriangle(int base, char pen, string name)
    : Triangle{ base, pen, name } {}

RightTriangle::~RightTriangle() {};

int RightTriangle::getHeight() const {
    return base;
}

int RightTriangle::getWidth() const {
    return base;
}

//returns geometric perimiter
double RightTriangle::perimeterGeo() const {
    return (2 + std::sqrt(2)) * getHeight();
}

//returns screen areea
double RightTriangle::areaScr() const {
    return getHeight() * (getHeight() + 1) / 2;
}

//returns screen perimeter
double RightTriangle::perimeterScr() const {
    return 3 * (getHeight() - 1);
}

//returns Canvas object with textual image of RightTriangle
Canvas RightTriangle::draw() const {
    Canvas drawGrid{ getHeight(), getWidth() };

    int height = getHeight();

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col <= row; ++col) {
            drawGrid.put(row, col, pen);
        };
    }

    return drawGrid;
}

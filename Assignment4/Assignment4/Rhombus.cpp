#include "Rhombus.h"


Rhombus::Rhombus(int d, char p, string n)
    :Shape{ p,n }, diagonal{ d % 2 == 1 ? d : d + 1 }{}

Rhombus::~Rhombus() {};

int Rhombus::getHeight() const {
    return diagonal;
}

int Rhombus::getWidth() const {
    return diagonal;
}

//returns geometric area
double Rhombus::areaGeo() const {
    return diagonal * diagonal / 2;
}

//returns geometric perimeter
double Rhombus::perimeterGeo() const {
    return 2 * std::sqrt(2) * diagonal;
}

//returns screen area
double Rhombus::areaScr() const {
    double n = floor(diagonal / 2);
    return 2 * n * (n + 1) + 1;
}

//returns screen perimeter
double Rhombus::perimeterScr() const {
    return 2 * (diagonal - 1);
}


Canvas Rhombus::draw() const {
    Canvas drawGrid{ getHeight(), getWidth() };

    int height = getHeight();

    // initiallize left blank space and right blank space
    int LSpace;
    int RSpace;
    
    //  LSpace and RSpace - both have col number 1/2 of height
    LSpace = RSpace = height / 2;
    

    for (int row = 0; row < height; row++) {
        // Draw Triangle
        for (int col = 0; col < height; col++) {
            // if LSpace < col < RSpace
            if (col >= LSpace && col <= RSpace) {
                drawGrid.put(row, col, pen);
            }
        }

        // upper upright triangle
        if (row < height / 2) {
            LSpace--; // left space col number will decrement with increasing row count
            RSpace++; // right space col number will increment with increasing row count
        } else { // lower inverted triangle: it works reversed
            LSpace++;
            RSpace--;
        }
    }

    return drawGrid;
}

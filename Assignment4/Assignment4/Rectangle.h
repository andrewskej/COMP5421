#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
protected:
    int height;
    int width;

public:

    Rectangle(int height, int width, char pen = '*', string name = "Rectangle");
    virtual ~Rectangle();

    virtual int getHeight() const override;
    virtual int getWidth() const override;

    virtual double areaGeo() const override;
    virtual double perimeterGeo() const override;
    virtual double areaScr() const override;
    virtual double perimeterScr() const override;

    virtual Canvas draw() const override;
};

#endif

#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle {
public:

    AcuteTriangle(int base, char pen = '*', string name = "Wedge");

    virtual ~AcuteTriangle();

    virtual int getHeight() const override;

    virtual int getWidth() const override;

    virtual double perimeterGeo() const override;

    virtual double areaScr() const override;

    virtual double perimeterScr() const override;

    virtual Canvas draw() const override;
};

#endif

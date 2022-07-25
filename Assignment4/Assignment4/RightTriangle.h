#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
    public:

        RightTriangle(int base, char pen = '*', string name = "Ladder");

        virtual ~RightTriangle();

        virtual int getHeight() const override;

        virtual int getWidth() const override;

        virtual double perimeterGeo() const override;

        virtual double areaScr() const override;

        virtual double perimeterScr() const override;

        virtual Canvas draw() const override;
};

#endif

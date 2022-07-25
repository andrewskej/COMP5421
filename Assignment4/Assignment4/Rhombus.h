#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {
    protected:
        int diagonal;
    public:
        Rhombus(int diagonal, char pen = '*', string name = "Rhombus");
        
        virtual ~Rhombus();

        virtual int getHeight() const override;

        virtual int getWidth() const override;

        virtual double areaGeo() const override;

        virtual double perimeterGeo() const override;

        virtual double areaScr() const override;

        virtual double perimeterScr() const override;

        virtual Canvas draw() const override;
};

#endif

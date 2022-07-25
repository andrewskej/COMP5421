#include "Triangle.h"


Triangle::Triangle(int b, char p, string n)
    : Shape{ p,n }, base{ b } {}


Triangle::~Triangle() {};


//returns geometric area of the Triangle
double Triangle::areaGeo() const {
    return getHeight() * base / 2;
}

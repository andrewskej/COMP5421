#include "Shape.h"
#include<typeinfo>

//Static id initialize
int Shape::id{ 0 };

Shape::Shape(char p, string n):pen{ p }, name{ n } { Shape::id++; }

Shape::~Shape() {};


//returns name
string Shape::getName() const {
    return this->name;
}

//returns object pen character
char Shape::getPen() const {
    return this -> pen;
}

//returns unique id
int Shape::getId() const {
    return this -> id;
}

//set name
void Shape::setName(string name) {
    this -> name = name;
}

//set pen
void Shape::setPen(char pen) {
    this -> pen = pen;
}


//toString to display shape info
string Shape::toString() const {
    ostringstream buffer;

    buffer << "Shape Information\n"
        << "-----------------\n"
        << "id:             " << getId() << "\n"
        << "Shape name:     " << getName() << "\n"
        << "Pen character:  " << getPen() << "\n"
        << "Height:         " << getHeight() << "\n"
        << "Width:          " << getWidth() << "\n"
        << "Textual area:   " << areaScr() << "\n"
        << "Geometric area: " << fixed << setprecision(2) << areaGeo() << "\n"
        << "Scr perimeter:  " << perimeterScr() << "\n"
        << "Geo perimeter:  " << fixed << setprecision(2) << perimeterGeo() << "\n"
        << "Static type:    " << typeid(this).name() << "\n"
        << "Dynamic type:   " << typeid(*this).name() << endl;

    return buffer.str();
};


ostream& operator<<(ostream& cout, const Shape& shape) {
    return cout << shape.toString();
}

#pragma once

#include <iostream>
#include <array>
#include <cassert>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::array;
using std::ostream;
using std::istream;

class Quad{
    private:
        array <double, 4> quad{};

    public:
        static inline const double tolerance{ 1.0E-6 };
        
        //ctor
        Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

        //get & set
        Quad get() const;
        void set(const Quad&);

        //big five
        Quad(const Quad&) = default; // copy constructor
        Quad(Quad&&) = default; // move constructor
        Quad& operator=(const Quad&) = default; // copy op=
        Quad& operator=(Quad&&) = default; // move op=
        ~Quad() = default; // destructor

        //inverse and absolute
        Quad inverse() const;
        double absoluteValue() const;

        // << and >>
        friend ostream& operator<<(ostream& sout, const Quad& q);
        friend istream& operator>>(istream& sin, Quad& q);
        
    
        //Compound assignment operators - member func
        Quad& operator+=(const Quad& rhs);
        Quad& operator+=(double val);

        Quad& operator-=(const Quad& rhs);
        Quad& operator-=(double val);
        
        Quad& operator*=(const Quad& rhs);
        Quad& operator*=(double val);
        
        Quad& operator/=(const Quad& rhs);
        Quad& operator/=(double val);
    

        //Unary operators - member func
        Quad operator+(); //prefix positive
        Quad operator-(); //prefix negative
        Quad operator++(); //prefix
        Quad operator++(int); //postfix
        Quad operator--(); //prefix
        Quad operator--(int); //postfux

        //[], const, non-const version
        double& operator[](int index);
        const double& operator[](int index) const;

        //(), five versions as requested
        double operator()();
        double operator()(size_t i);
        double operator()(size_t i, size_t j);
        double operator()(size_t i, size_t j, size_t k);
        double operator()(size_t i, size_t j, size_t k, size_t l);
};


// Free Non-Member Operator Overloading
Quad operator+(const Quad&, const Quad&);     // Quad + Quad
Quad operator+(const Quad&, const double&);   // Quad + double
Quad operator+(const double&, const Quad&);   // double + Quad

Quad operator-(const Quad&, const Quad&);     // Quad - Quad
Quad operator-(const Quad&, const double&);   // Quad - double
Quad operator-(const double&, const Quad&);   // double - Quad

Quad operator*(const Quad&, const Quad&);     // Quad * Quad
Quad operator*(const Quad&, const double&);   // Quad * double
Quad operator*(const double&, const Quad&);   // double * Quad

Quad operator/(const Quad&, const Quad&);     // Quad / Quad
Quad operator/(const Quad&, const double&);   // Quad / double
Quad operator/(const double&, const Quad&);   // double / Quad

bool operator==(const Quad&, const Quad&);    // Quad == Quad
bool operator!=(const Quad&, const Quad&);    // Quad != Quad
bool operator<(const Quad&, const Quad&);     // Quad <  Quad
bool operator<=(const Quad&, const Quad&);    // Quad <= Quad
bool operator>(const Quad&, const Quad&);     // Quad > Quad
bool operator>=(const Quad&, const Quad&);    // Quad >= Quad

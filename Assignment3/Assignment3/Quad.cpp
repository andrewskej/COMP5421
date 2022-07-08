#include "Quad.h"

using std::cout;
using std::endl;

//constructor
Quad::Quad(double x1, double x2, double x3, double x4): quad{x1, x2, x3, x4}{
}

//accessors
Quad Quad::get() const{
    return *this;
}

//mutators
void Quad::set(const Quad& q){
    this->quad.at(0) = q.quad.at(0);
    this->quad.at(1) = q.quad.at(1);
    this->quad.at(2) = q.quad.at(2);
    this->quad.at(3) = q.quad.at(3);
}


//inverse the Quad
Quad Quad::inverse() const{
    Quad lhs = *this;
    
    double b = (lhs.quad.at(0) * lhs.quad.at(2)) - (lhs.quad.at(1) * lhs.quad.at(3));
    
    Quad inverseQ(lhs.quad.at(2) / b, -1 * lhs.quad.at(1) / b, lhs.quad.at(0) / b, -1 * lhs.quad.at(3) / b );

    return inverseQ;
}


//absolute value of Quad
double Quad::absoluteValue() const{
    return abs(quad.at(0)) + abs(quad.at(1)) + abs(quad.at(2)) + abs(quad.at(3)) ;
}

// << overload
ostream& operator<<(ostream& sout, const Quad& q){
    sout << "[ ";
    for (size_t i{}; i < 4; ++i){
        sout << q.quad[i] << " ";
    }
    sout << "]";

    return sout;
}

//>> overload
istream& operator>>(istream& sin, Quad& q){
    for (size_t i{}; i < 4; ++i){
        sin >> q.quad[i];
    }

    return sin;
}


//Member Operator Overloading functions

Quad& Quad::operator+=(const Quad& rhs){
    this -> quad.at(0) += rhs.quad.at(0);
    this -> quad.at(1) += rhs.quad.at(1);
    this -> quad.at(2) += rhs.quad.at(2);
    this -> quad.at(3) += rhs.quad.at(3);

    return *this;
}

Quad& Quad::operator+=(double val){
    this -> quad.at(0) += val;
    this -> quad.at(1) += val;
    this -> quad.at(2) += val;
    this -> quad.at(3) += val;

    return *this;
}

Quad& Quad:: operator-=(const Quad& rhs){
    this -> quad.at(0) -= rhs.quad.at(0);
    this -> quad.at(1) -= rhs.quad.at(1);
    this -> quad.at(2) -= rhs.quad.at(2);
    this -> quad.at(3) -= rhs.quad.at(3);
    return *this;
}

Quad& Quad::operator-=(double val){
    this -> quad.at(0) -= val;
    this -> quad.at(1) -= val;
    this -> quad.at(2) -= val;
    this -> quad.at(3) -= val;
    return *this;
}

Quad& Quad:: operator*=(const Quad& rhs){
    double x1 = quad.at(0) * rhs.quad[0] + quad.at(1) * rhs.quad.at(3);
    double x2 = quad[0] * rhs.quad.at(1) + quad.at(1) * rhs.quad.at(2);
    double x3 = quad.at(3) * rhs.quad.at(1) + quad.at(2) * rhs.quad.at(2);
    double x4 = quad.at(3) * rhs.quad[0] + quad.at(2) * rhs.quad.at(3);

    this->quad.at(0) = x1;
    this->quad.at(1) = x2;
    this->quad.at(2) = x3;
    this->quad.at(3) = x4;

    return *this;
}

Quad& Quad::operator*=(double val){
    this -> quad.at(0) *= val;
    this -> quad.at(1) *= val;
    this -> quad.at(2) *= val;
    this -> quad.at(3) *= val;
    return *this;
}


Quad& Quad:: operator/=(const Quad& rhs){
    Quad rhsInv = rhs.inverse();
        
    this -> quad.at(0) = (this -> quad.at(0) * rhsInv.quad.at(0)) + (this -> quad.at(1) * rhsInv.quad.at(3));
    this -> quad.at(1) = (this -> quad.at(0) * rhsInv.quad.at(1)) + (this -> quad.at(1) * rhsInv.quad.at(2));
    this -> quad.at(2) = (this -> quad.at(3) * rhsInv.quad.at(1)) + (this -> quad.at(2) * rhsInv.quad.at(2));
    this -> quad.at(3) = (this -> quad.at(3) * rhsInv.quad.at(0)) + (this -> quad.at(2) * rhsInv.quad.at(3));
    return *this;
}


Quad& Quad::operator/=(double val){
    this -> quad.at(0) *= (1/val);
    this -> quad.at(1) *= (1/val);
    this -> quad.at(2) *= (1/val);
    this -> quad.at(3) *= (1/val);
    return *this;
}

//Quad + Quad
Quad operator+(const Quad& lhs, const Quad& rhs){
    Quad addedQ{ lhs };
    addedQ += rhs;
    return addedQ;
}

//Quad + double
Quad operator+(const Quad& lhs, const double& val){
    Quad addedQ{ lhs };
    addedQ += val;
    return addedQ;
}

//double + Quad
Quad operator+(const double& val, const Quad& rhs){
    Quad addedQ{ rhs };
    addedQ += val;
    return addedQ;
}

//Quad - Quad
Quad operator-(const Quad& lhs, const Quad& rhs){
    Quad subtractedQ{ lhs };
    subtractedQ -= rhs;
    return subtractedQ;
}

//Quad - double
Quad operator-(const Quad& lhs, const double& val){
    Quad subtractedQ{ lhs };
    subtractedQ -= val;
    return subtractedQ;
}

//double - Quad
Quad operator-(const double& val, const Quad& rhs){
    Quad subtractedQ{ val - rhs[1], val - rhs[2], val - rhs[3], val - rhs[4] };
    return subtractedQ;
}

//Quad * Quad
Quad operator*(const Quad& lhs, const Quad& rhs){
    Quad multipliedQ{ lhs };
    multipliedQ *= rhs;
    return multipliedQ;
}

//Quad * double
Quad operator*(const Quad& lhs, const double& val){
    Quad multipliedQ{ lhs };
    multipliedQ *= val;
    return multipliedQ;
}

//double * Quad
Quad operator*(const double& val, const Quad& rhs){
    Quad multipliedQ{ rhs };
    multipliedQ *= val;
    return multipliedQ;
}

//Quad / Quad
Quad operator/(const Quad& lhs, const Quad& rhs){
    Quad dividedQ{ lhs };
    dividedQ /= rhs;
    return dividedQ;
}

//Quad / double
Quad operator/(const Quad& lhs, const double& val){
    Quad dividedQ{ lhs };
    dividedQ /= val;
    return dividedQ;
}

//double / Quad
Quad operator/(const double& val, const Quad& rhs){
    Quad dividedQ{ rhs.inverse() };
    dividedQ *= val;
    return dividedQ;
}

//Quad == Quad
bool operator==(const Quad& lhs, const Quad& rhs) {
    Quad difference = lhs - rhs;
    double tolerance = Quad::tolerance;
    return (difference.absoluteValue() <= tolerance);
}


//Quad != Quad
bool operator!=(const Quad& lhs, const Quad& rhs){
    return (lhs == rhs) ? false : true;
}

//Quad < Quad
bool operator<(const Quad& lhs, const Quad& rhs){
    double lhsAbsSum = lhs.absoluteValue();
    double rhsAbsSum = rhs.absoluteValue();
    
    return (!(lhs == rhs) && lhsAbsSum < rhsAbsSum);
}

//Quad <= Quad
bool operator<=(const Quad& lhs, const Quad& rhs){
    return (lhs < rhs || lhs == rhs);
}

//Quad > Quad
bool operator>(const Quad& lhs, const Quad& rhs){
    return (rhs < lhs);
}

//Quad >= Quad
bool operator>=(const Quad& lhs, const Quad& rhs){
    return (lhs < rhs) ? false : true;
}


//unary positive
Quad Quad::operator+(){
    double x1 = this -> quad.at(0) *= 1.0;
    double x2 = this -> quad.at(1) *= 1.0;
    double x3 = this -> quad.at(2) *= 1.0;
    double x4 = this -> quad.at(3) *= 1.0;
    Quad posQ(x1, x2, x3, x4);
    return posQ;
}

//unary negative
Quad Quad::operator-(){
    double x1 = this -> quad.at(0);
    double x2 = this -> quad.at(1);
    double x3 = this -> quad.at(2);
    double x4 = this -> quad.at(3);
    Quad negQ(x1 * -1.0, x2 * -1.0, x3 * -1.0, x4 * -1.0);
    return negQ;
}

//prefix increment
Quad Quad::operator++(){
   this -> quad.at(0) += 1.0;
   this -> quad.at(1) += 1.0;
   this -> quad.at(2) += 1.0;
   this -> quad.at(3) += 1.0;
   return *this;
}

//postfix increment
Quad Quad::operator++(int){
    double x1 = this -> quad.at(0);
    double x2 = this -> quad.at(1);
    double x3 = this -> quad.at(2);
    double x4 = this -> quad.at(3);
    Quad incrementQ(x1++, x2++, x3++, x4++);
    this -> quad.at(0) += 1.0;
    this -> quad.at(1) += 1.0;
    this -> quad.at(2) += 1.0;
    this -> quad.at(3) += 1.0;
    return incrementQ;
}

//prefix decrement
Quad Quad::operator--(){
    this -> quad.at(0) -= 1.0;
    this -> quad.at(1) -= 1.0;
    this -> quad.at(2) -= 1.0;
    this -> quad.at(3) -= 1.0;
    return *this;
}

//postfix decrement
Quad Quad::operator--(int){
    double x1 = this -> quad.at(0);
    double x2 = this -> quad.at(1);
    double x3 = this -> quad.at(2);
    double x4 = this -> quad.at(3);
    Quad decrementQ(x1--, x2--, x3--, x4--);
    this -> quad.at(0) -= 1.0;
    this -> quad.at(1) -= 1.0;
    this -> quad.at(2) -= 1.0;
    this -> quad.at(3) -= 1.0;
    return decrementQ;
}



double& Quad::operator[](int index) {
    if (index > 4 || index < 1) {
        throw std::out_of_range("index out of bounds");
    }
    return this->quad[index - 1];
}

const double& Quad::operator[](int index) const {
    if (index > 4 || index < 1) {
        throw std::out_of_range("index out of bounds");
    }
    return this->quad[index - 1];
}

double Quad::operator()() {
    return std::max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}

double Quad::operator()(size_t i) {
    if (i < 1 || i > 4) {
        throw std::out_of_range("index out of bounds");
    }
    return (*this)[i];
}

double Quad::operator()(size_t i, size_t j) {
    if (i < 1 || i > 4 || j < 1 || j > 4) {
        throw std::out_of_range("index out of bounds");
    }
    return std::max({ (*this)[i], (*this)[j] });
}

double Quad::operator()(size_t i, size_t j, size_t k) {
    if (i < 1 || i > 4 || j < 1 || j > 4 || k < 1 || k >4) {
        throw std::out_of_range("index out of bounds");
    }
    return std::max({ (*this)[i], (*this)[j], (*this)[k] });
}

double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
    if (i < 1 || i > 4 || j < 1 || j > 4 || k < 1 || k >4 || l < 1  || l > 4) {
        throw std::out_of_range("index out of bounds");
    }
    return std::max({ (*this)[i], (*this)[j], (*this)[k], (*this)[l] });
}

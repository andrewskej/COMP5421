#include<iostream>
#ifndef Token_h
#define Token_h
#include "ArrayList.h"

using std::ostream;
using std::cout;
using std::endl;

class Token {
private:
    char* cstr;  //pointer to the string part (character string)
    int frequency; //frequency of the given token
    ArrayList number_list; //number list

public:
    Token() = delete;  //basic constructor: no need

    Token(const char* cstr, int line_num); //constructor with parameters

    Token(const Token& token); //copy constructor

    Token(Token&& token) noexcept; //move constructor

    virtual ~Token(); //destructor

    Token& operator=(const Token& rhs); //copy assignment

    Token& operator=(Token&& rhs) noexcept; //move assignment

    const char* c_str() const; //returns string part of the Token

    void addLineNumber(int line_num); //add a given line number

    size_t size() const; //returns the size of the Token

    int getFrequency() const; //returns the frquency

    void setFrequency(int frequency); //sets the frequency of the Token

    void print(ostream& sout) const; //prints out the Token

    const ArrayList& getNumberList() const; //returns the number_list

    void setNumberList(ArrayList& numberList); //sets the number_list

    const int compare(const Token& aToken) const; //compares the string value of two tokens

};

ostream& operator<<(ostream& sout, const Token& f); //operator overload: <<


#endif
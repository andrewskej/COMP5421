#include <cstring>
#include "Token.h"

/*
* Basic constructor
* @param *astr given character pointer
* @param line_num line number
*/
Token::Token(const char* astr, int line_num)
    : frequency{ 1 }, cstr{ new char[strlen(astr) + 1] }, number_list{} {
    strcpy(cstr, astr);
    number_list.pushBack(line_num);
};

/*
* copy constructor
* @param &originalTkn original token to be copied
*/
Token::Token(const Token& originalTkn)
    : frequency{ originalTkn.getFrequency() }, cstr{ new char[strlen(originalTkn.cstr) + 1] }, number_list{ originalTkn.getNumberList() }{
    strcpy(cstr, originalTkn.cstr);
}

/*
* move constructor
* @param &&originalTkn original token to be moved
*/

Token::Token(Token&& originalTkn) noexcept
    : frequency{ originalTkn.frequency }, cstr{ originalTkn.cstr }, number_list{ originalTkn.number_list }{

    number_list = std::move(originalTkn.number_list);

    originalTkn.cstr = new char[1];
    originalTkn.cstr[0] = '\0';
    originalTkn.frequency = 0;
}

/*
* copy assignment
* @param &rhs right hand side(original token) to be copied
*/
Token& Token::operator=(const Token& rhs) {
    if (&rhs != this) {
        delete[] cstr;
        cstr = new char[strlen(rhs.c_str()) + 1];
        strcpy(cstr, rhs.cstr);
        frequency = rhs.getFrequency();
        number_list = rhs.getNumberList();
    }
    return *this;
}

/*
* move assignment
* @param &rhs right hand side(original token) to be move
*/
Token& Token::operator=(Token&& rhs) noexcept {
    if (&rhs != this) {
        delete[] cstr;
        cstr = rhs.cstr;
        frequency = rhs.frequency;
        number_list = std::move(rhs.number_list);

        rhs.cstr = new char[1];
        rhs.cstr[0] = '\0';
        rhs.frequency = 0;
    }
    return *this;
}

/*
* desctructor
*/
Token::~Token() {
    delete[] cstr;
}

/*
* adds the given line number to the number_list
* @param line_num line number given
*/
void Token::addLineNumber(int line_num) {
    frequency++;
    number_list.pushBack(line_num);
}

/*
* gets the size of the Token
*/
size_t Token::size() const {
    size_t tokenSize = strlen(cstr);
    return tokenSize;
}

/*
* gets the string part of the token
*/
const char* Token::c_str() const {
    return cstr;
}

/*
* gets the frequency of the Token
*/
int Token::getFrequency() const {
    return frequency;
}

/*
* sets the frequency of the Token
* @param freq frequency to set
*/
void Token::setFrequency(int freq) {
    this->frequency = freq;
}

/*
* prints out the Token
* @param &sout ostream
*/
void Token::print(ostream& sout) const {
    if (cstr != NULL) { sout << cstr; }

    sout << " (" << getFrequency() << ") ";

    if (getNumberList().size()) {
        sout << getNumberList();
    }
}

/*
* gets the number_list part of the Token
*/
const ArrayList& Token::getNumberList() const {
    return number_list;
}

/*
* sets the number_list of the Token
* @params numberList 
*/
void Token::setNumberList(ArrayList& numberList) {
    this->number_list = numberList;
}

/*
* compares the string part of current token and the given Token
* @param &aToken the given token
*/
const int Token::compare(const Token& aToken) const {
    if (cstr == NULL) { //if string is null, return 1
        return 1;
    }
    else { //returns the string compare value of current token and given token (its character string part)
        return std::strcmp(cstr, aToken.cstr);
    }
}

/*
* operator overloading: <<
*/
ostream& operator<<(ostream& sout, const Token& t) {
    t.print(sout);
    return sout;
}
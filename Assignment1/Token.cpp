#include <cstring>
#include "Token.h"
using std::cout;
using std::endl;

Token::Token(const char *astr, int line_num)
: frequency{1}, cstr{new char[strlen(astr) + 1]}, number_list{} {
    strcpy(cstr, astr);
    number_list.pushBack(line_num);
};


Token::Token(const Token& originalTkn)
: frequency{originalTkn.getFrequency()}, cstr{new char[strlen(originalTkn.cstr) + 1]}, number_list{originalTkn.getNumberList()}{
    strcpy(cstr, originalTkn.cstr);
}

Token::Token(Token&& originalTkn) noexcept
: frequency{originalTkn.frequency}, cstr{originalTkn.cstr}, number_list{originalTkn.number_list}{

    number_list = std::move(originalTkn.number_list);
    
    originalTkn.cstr = new char[1];
    originalTkn.cstr[0] = NULL;
    originalTkn.frequency = 0;
}

Token& Token::operator=(const Token& rhs){
    if(&rhs != this){
        delete [] cstr;
        cstr = new char[strlen(rhs.c_str()) + 1];
        strcpy(cstr, rhs.cstr);
        frequency = rhs.getFrequency();
        number_list = rhs.getNumberList();
    }
    return *this;
}

Token& Token::operator=(Token&& rhs) noexcept{
    if(&rhs != this){
        delete[] cstr;
        cstr = rhs.cstr;
        frequency = rhs.frequency;
        number_list = std::move(rhs.number_list);
        
        rhs.cstr = new char[1];
        rhs.cstr[0] = NULL;
        rhs.frequency = 0;
    }
    return *this;
}

Token::~Token(){
    delete[] cstr;
}


void Token::addLineNumber(int line_num){
    frequency++;
    number_list.pushBack(line_num);
}

size_t Token::size() const {
    size_t tokenSize = strlen(cstr);
    return tokenSize;
}

const char* Token::c_str() const {
    return cstr;
}

int Token::getFrequency() const {
    return frequency;
}

void Token::setFrequency(int freq){
    this -> frequency = freq;
}

void Token::print(ostream& sout) const {
    if(cstr != NULL){ sout << cstr; }

    sout << " (" << getFrequency() << ") ";

    if(getNumberList().size()){
        sout << getNumberList();
    }
}

const ArrayList& Token::getNumberList() const{
    return number_list;
}

void Token::setNumberList(ArrayList& numberList){
    this -> number_list = numberList;
}

const int Token::compare(const Token& aToken) const{
    if(cstr == NULL){
        return 1;
    } else {
        return std::strcmp(cstr, aToken.cstr);
    }   
}

ostream& operator<<(ostream& sout, const Token& t){
    t.print(sout);
    return sout;
}

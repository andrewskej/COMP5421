#include <cstring>
#include "Token.h"
using std::cout;
using std::endl;

Token::Token(const char *astr, int line_num)
: frequency{1}, cstr{new char[strlen(astr) + 1]}, number_list{} {
    strcpy(cstr, astr);
    number_list.pushBack(line_num);
};


Token::Token(const Token& tkn)
: frequency{tkn.getFrequency()}, cstr{tkn.cstr}, number_list{tkn.getNumberList()}{
    strcpy(tkn.cstr, cstr);
}

Token::Token(Token&& tkn)
: frequency{tkn.frequency}, cstr{tkn.cstr}, number_list{tkn.number_list}{
    cout << "--Token:move constructor--" << endl;
    tkn.cstr = nullptr;
    tkn.frequency = 0;
    //how to remove tkn.number_list ? 
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
    cout << "--Token:move assignment--" << endl;
    if(&rhs != this){
        delete[] cstr;
        cstr = new char[strlen(rhs.cstr) + 1];
        strcpy(cstr, rhs.cstr);
        frequency = rhs.frequency;
        number_list = rhs.number_list;
        rhs.cstr = nullptr;
        rhs.frequency = 0;
        //how to remove rhs.number_list?
    }
    return *this;
}

Token::~Token(){
    delete [] cstr;
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

void Token::print(ostream& sout) const {
    if(cstr){ sout << cstr; }
    sout << " (" << frequency << ") ";
    if(number_list.size()){sout << number_list;}
}

const ArrayList& Token::getNumberList() const{
    return number_list;
}

const int Token::compare(const Token& aToken){
    if(aToken.cstr > cstr){
        return 1;
    }else if(aToken.cstr < cstr){
        return -1;
    }else {
        return 0;
    }
}

ostream& operator<<(ostream& sout, const Token& t){
    t.print(sout);
    return sout;
}

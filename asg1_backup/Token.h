#include<iostream>
#ifndef Token_h
#define Token_h
#include "ArrayList.h"

using std::ostream;
using std::cout;
using std::endl;

class Token {
    private:
        char* cstr;
        int frequency;
        ArrayList number_list;

    public:
        Token() = delete;

        Token(const char* cstr, int line_num);
    
        Token(const Token& token);
        
        Token(Token&& token) noexcept;

        virtual ~Token();
        
        Token& operator=(const Token& rhs);

        Token& operator=(Token&& rhs) noexcept;
        
        const char* c_str() const;
        
        void addLineNumber(int line_num);

        size_t size() const;
    
        int getFrequency () const;
    
        void setFrequency (int frequency);
        
        void print (ostream& sout) const;
        
        const ArrayList& getNumberList() const;
        
        void setNumberList(ArrayList& numberList);
    
        const int compare(const Token& aToken) const;
    
};

ostream& operator<<(ostream& sout, const Token& f);


#endif

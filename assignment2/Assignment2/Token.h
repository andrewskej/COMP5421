#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Token{
    private:
        string text;
        size_t frequency;
        vector<size_t> line_number_list;
    
    public:
        Token(string text, size_t line_number); //normal constructor
};


#endif /* Token_hpp */

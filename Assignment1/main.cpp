#include <iostream>
#include <vector>
#include<cassert>
#include "Token.h"
#include "TokenList.h"

//#include "Dictionary.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::move;

int main(int argc, const char * argv[]) {
    
    TokenList bucket;
    Token t1("Hello", 1);
    bucket.addSorted(t1);
    Token t2("Hello", 11);
    bucket.addSorted(t2);
    Token t3("Hello", 111);
    bucket.addSorted(t3);
    
    Token tArray[]{ Token("How", 1), Token("are", 11), Token("you", 2),
    Token("today?", 22), Token("#tag", 3), Token("bye", 3) };
    for (Token t : tArray)
    {
    bucket.addSorted(t);
    }
    bucket.print(cout); // ideally we prefer cout << bucket << endl;
    cout << endl;
    return 0; // 0 means success!
  
}

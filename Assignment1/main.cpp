#include <iostream>
#include <vector>
#include<cassert>
#include "ArrayList.h"
#include "Token.h"
//#include "Dictionary.h"
//#include "TokenList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::move;

int main(int argc, const char * argv[]) {
    cout << "Testing an Object of Class Token\n";
    Token t1{ "Hello", 1 };
    
     cout << "A) t1: "; t1.print(cout); cout << endl;
     t1.addLineNumber(11);
     t1.addLineNumber(13);
     t1.addLineNumber(74);
     t1.addLineNumber(92);
     cout << "B) t1: "; t1.print(cout); cout << endl;

     Token t2 = t1; // copy constructor (not copy assignment)
     t1.addLineNumber(11111);
     cout << "C) t1: "; t1.print(cout); cout << endl;
     cout << "D) t2: "; t2.print(cout); cout << endl;
     t2 = t1; // copy assignment
     cout << "E) t1: "; t1.print(cout); cout << endl;
     cout << "F) t2: "; t2.print(cout); cout << endl;
    
     Token t3 = move(t2); // move constructor
     cout << "G) t3: "; t3.print(cout); cout << endl;
     cout << "H) t2: "; t2.print(cout); cout << endl; // warning C26800:
     t1 = move(t3); // move assignment
     cout << "I) t3: "; t3.print(cout); cout << endl; // warning C26800:
     cout << "J) t1: "; t1.print(cout); cout << endl;
     ArrayList ia = t1.getNumberList();
     cout << "J) ia: "; ia.print(cout); cout << endl;
    
     return 0;
    
  
}

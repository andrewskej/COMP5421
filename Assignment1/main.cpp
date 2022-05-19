//
//  main.cpp
//  Assignment1
//
//  Created by Yousik Jeon on 2022-05-12.
//

#include <iostream>
#include "ArrayList.h"
//#include "Token.h"
//#include "Dictionary.h"
//#include "TokenList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Develop a program that indexes the tokens in an input text file, keeping track of (1) the line numbers of the lines in which the tokens appear, and (2) the frequency (number of occurrences) of the token in the input file.
//The program must accept the name of an input text file, read the contents of that file, line by line, split each line into tokens, and store each token into a sorted dictionary, associating tokens (keys) with their list of line numbers (values).
//Encountering a token that is not in the dictionary, the program must add the token to the dictionary; otherwise, the program must record the line number on which the token appears into the list of the line numbers associated with that token; however, if a token appears multiple times in a line, then the number of that line must be recorded only once, but the frequency count must reflect each of the multiple occurrences.
//Finally, the program must display the resulting index, formatting it similar to an index at the end of a typical textbook.


int main(int argc, const char * argv[]) {
    
    cout << "Tesing ArrayList!\n";
    ArrayList list{};
    
    cout << "list-1 -> " << list << endl;
    assert(list.getCapacity() == 1);

    list.pushBack(19);
    cout << "list-2 -> " << list << endl;
    assert(list.getCapacity() == 1);
    assert(list.size() == 1);

    list.pushBack(32);
    cout << "list-3 -> " << list << endl;
    assert(list.getCapacity() == 2);
    assert(list.size() == 2);

    list.pushBack(21);
    cout << "list-4 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.size() == 3);

    list.pushBack(7);
    cout << "list-5 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.size() == 4);

    list.pushBack(18);
    cout << "list-6 -> " << list << endl;
    assert(list.getCapacity() == 8);
    assert(list.size() == 5);
    
    cout << "ArrayList Test Successful" << endl;
    return 0;
    
    
    
}

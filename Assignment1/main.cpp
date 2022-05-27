#include <iostream>
#include <cassert>
#include "Dictionary.h"



int main(int argc, const char * argv[]) {

    std::cout << "Enter the name of input text file: " ;
    string filename;
    std::cin >> filename;
    Dictionary dictionary(filename);
    dictionary.print(std::cout);

    return 0; // 0 means success!
  
}


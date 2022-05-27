#include <iostream>
#include <cassert>
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::move;

int main(int argc, const char * argv[]) {

//    cout << "Enter the name of input text file: " ;
//    string filename;
//    cin >> filename;
//    Dictionary dictionary(filename);
    
    
    Dictionary dictionary("/Users/andrewskej/Documents/dev/concordia/COMP5421/Assignment1/input_file_A1.txt");
    dictionary.print(cout);

    return 0; // 0 means success!
  
}


#include <iostream>
#include "Dictionary.h"

using std::cout;
using std::cin;

int main(int argc, const char* argv[]) {

//    cout << "Enter the name of input text file: " ;
    string filename{"/Users/andrewskej/Documents/dev/concordia/COMP5421/Assignment1/input_file_A1.txt"};
//    cin >> filename;
    Dictionary dictionary(filename);
    dictionary.print(std::cout);

    return 0; // 0 means success!

}

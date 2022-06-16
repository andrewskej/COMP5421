#include <iostream>
#include <vector>
#include <string>
#include "Dictionary.h"

using std::string;
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

string mainInterface(){
    cout << "" << endl;
    cout << "Choose one of the options listed below and, optionally," << endl;
    cout << "enter the initial character of the tokens to print:" << endl;
    cout << " 1 - Print input lines" << endl;
    cout << " 2 - Print original unsorted tokens" << endl;
    cout << " 3 - Print tokens sorted by text" << endl;
    cout << " 4 - Print tokens sorted by frequency" << endl;
    cout << " 5 - Print tokens sorted by length" << endl;
    cout << " 0 - Exit" << endl;
    cout << "Enter your input:" << endl;
    string userInput;
    cin >> userInput;
    return userInput;
}

void menuRouter(int menuOptionInt, string displayInputString){
    set<char> displayInputSet (displayInputString.begin(), displayInputString.end());

    string theSeparators = ". ;?(),13579=-\"\t\n";
    
    string filename = "/Users/andrewskej/Documents/dev/concordia/COMP5421/Assignment2/Assignment2/Seuss.txt";

    cout << "filename: " << filename << endl;
    cout << "selected:" << menuOptionInt << endl;

    cout << "will display: [ ";
    for(char displayElement: displayInputSet){
        cout << displayElement << " ";
    }
    cout << "]" << endl;
    
    Dictionary dictionary(filename, theSeparators);
    cout << " " << endl;


    switch(menuOptionInt){
        case 1:
            dictionary.print_input_lines(displayInputSet);
            break;
        case 2:
            cout << "Dictionary Unsorted" << endl;
            displayInputSet.size() > 0 ?
            dictionary.print_input_tokens(displayInputSet)
            : dictionary.print_input_tokens();
            break;
        case 3:
            cout << "Dictionary sorted by token text" << endl;
            displayInputSet.size() > 0 ?
            dictionary.print_sorted_on_token_text(displayInputSet):
            dictionary.print_sorted_on_token_text();
            break;
        case 4:
            cout << "Dictionary sorted by token frequency" << endl;
            displayInputSet.size() > 0 ?
            dictionary.print_sorted_on_token_frequency(displayInputSet):
            dictionary.print_sorted_on_token_frequency();
            break;
        case 5:
            cout << "Dictionary sorted by token length" << endl;
            displayInputSet.size() > 0 ?
            dictionary.print_sorted_on_token_length(displayInputSet):
            dictionary.print_sorted_on_token_length();
            break;
        case 0:
            cout << "terminating..." << endl;
            return;
        default:
            cout << "=== wrong input value ===" << endl;
            break;
    }
}

int main() {
    
    string userInput{};
    string displayInputString{};
    set<int> validMenuOptions = {0,1,2,3,4,5};
    char menuOption{};
    int menuOptionInt{99};

    while(menuOptionInt != 0){
        userInput = mainInterface();

        menuOption = userInput[0];
        menuOptionInt = menuOption - '0';
        displayInputString = userInput.substr(1, userInput.length());
       
        if(menuOptionInt && validMenuOptions.count(menuOptionInt) == 1){
            menuRouter(menuOptionInt, displayInputString);
        } else if(userInput[0] == 0 || menuOptionInt == 0){
            cout << "terminating..." << endl;
            return 0;
        } else {
            cout << "=== wrong input value ===" << endl;
        }
    }

    return 0;
}


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
using std::getline;

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

    string theSeparators{};
    string filename{};

    cout << "Directory Source File: ";
    cin >> filename;
    
    cout << "separator characters: ";
    cin.ignore();  //this will allow to escape semicolon to keep the entire input
    getline(cin, theSeparators);

    theSeparators = Dictionary::restore_fake_tab_newline_chars(theSeparators);
    
    Dictionary dictionary(filename, theSeparators);
    cout << " " << endl;

    //This switch selectively runs print options
    //switch by upon selected menuOption & if there is displayInputSet
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
    //only one of these numbers are accepted as menu option
    set<int> validMenuOptions = {0,1,2,3,4,5};
    char menuOption{};
    //initialize menuOption with 99, for while loop condition
    int menuOptionInt{99};

    //while you are not giving 0, it loops
    while(menuOptionInt != 0){
        //get userInput here
        userInput = mainInterface();

        //first letter of the input decides menu
        menuOption = userInput[0];
        //convert menuOption into int
        menuOptionInt = menuOption - '0';
        //except for the first letter, the rest is inputString to display
        displayInputString = userInput.substr(1, userInput.length());
       
        //if menuOption is valid (between 0 - 5),
        if(menuOptionInt && validMenuOptions.count(menuOptionInt) == 1){
            //run menuRouter to run appropriate functions
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


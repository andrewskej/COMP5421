#include "Dictionary.h"
#include "Token.h"
#include "TokenList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

/*
* basic constructor
* @param filename
*/
Dictionary::Dictionary(const string& filename) : filename(filename) {

    // create an input file stream
    std::ifstream fin(filename);

    if (!fin) {
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line); // very important first attempt to read;
    // this first attempt will get the i/o flags initialized
    while (fin) {
        //        cout << line << endl;
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        string tokenStr;

        // extract token strings
        while (sin >> tokenStr) {
            processToken(tokenStr, linenum);
        }
        getline(fin, line); // attempt to read the next line, if any
    }
    fin.close();
}

/*
* prints out the Dictionary
* @param &cout ostream
*/
void Dictionary::print(ostream& cout) const {
    //prepare a list of alphabets + '\0' for non-alphabet letters
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'
    };

    for (int i = 0; i < 27; i++) {
        cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
        tokenListBuckets[i].print(cout);
    }
}

/*
* processes Token to be inserted in proper place
* @param &token the given token
* @param linenum the given line number
*/
void Dictionary::processToken(const string& token, int linenum) {
    size_t index = bucketIndex(token);   //gets the index of the token to be placed in the bucket
    tokenListBuckets[index].addSorted(token, linenum);  //add the token in the bucket, at the designated location
}

/*
* gets the index of the given token to be placed in the bucket
* @param token the given token
*/
size_t Dictionary::bucketIndex(const string& token) const {
    // bucket index for tokens not beginning with a letter
    size_t index = 26;
    if (isalpha(token[0])) {
        if (isupper(token[0])) {
            index = token[0] - 'A';
        }
        else {
            index = token[0] - 'a';
        }
    }

    return index;
}

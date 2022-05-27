#include "Dictionary.h"
#include "Token.h"
#include "TokenList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

Dictionary::Dictionary(const string& filename) : filename(filename){
    
    // create an input file stream
    std::ifstream fin(filename);
    
    if (!fin){
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line); // very important first attempt to read;
    // this first attempt will get the i/o flags initialized
    while (fin){
//        cout << line << endl;
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        string tokenStr;

        // extract token strings
        while (sin >> tokenStr){
            processToken(tokenStr, linenum);
        }
        getline(fin, line); // attempt to read the next line, if any
    }
    fin.close();
}

void Dictionary::print(ostream& cout) const{
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'
    };
    
    for(int i = 0; i < 27; i++){
        cout << "<" << alphabet[i] << ">" << endl;
        tokenListBuckets[i].print(cout);
    }
}


void Dictionary::processToken(const string& token, int linenum){
    size_t index = bucketIndex(token);
    tokenListBuckets[index].addSorted(token, linenum);
}


size_t Dictionary::bucketIndex(const string& token) const{
    // bucket index for tokens not beginning with a letter
    size_t index = 26;
    if (isalpha(token[0])){
        if(isupper(token[0])) {
            index = token[0] - 'A';
        } else {
            index = token[0] - 'a';
        }
    }

    return index;
}
    

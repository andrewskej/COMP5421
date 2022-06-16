#include "Dictionary.h"
#include "Token.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <forward_list>
#include <iomanip>

using std::string;
using std::vector;
using std::array;
using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::forward_list;
using std::setw;

Dictionary::Dictionary(const string& filename, const string& theSeparators): filename(filename), theSeparators(theSeparators){

    cout << "Separator characters:" << escape_tab_newline_chars(theSeparators) << endl;
    
    vector<string> v1{};
    array<list<Token>, 27> t1{};
    this -> input_lines = v1;
    this -> token_list_buckets = t1;
    
    ifstream fin(filename);
    
    if (!fin){
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line);

    while (fin){
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        extract_and_push(line, linenum);
        getline(fin, line); // attempt to read the next line, if any
    }
    fin.close();
};


//returns the index of the bucket corresponding to tokenText[0]
size_t Dictionary::bucket_index(const string &tokenText) const {
    size_t index = 26;
    if (isalpha(tokenText[0])) {
        if (isupper(tokenText[0])) {
            index = tokenText[0] - 'A';
        }
        else {
            index = tokenText[0] - 'a';
        }
    }
    return index;
}



void printTokens(const string& line, const string& separators) {
    size_t sndx{ line.find_first_not_of(separators) };     // find the start index of first token, if any
    while (sndx != string::npos){    // while there are tokens
         size_t endIndex = line.find_first_of(separators, sndx + 1);      // find the end of current token that starts at sndx
        
         if (endIndex == string::npos){ // we did reach the of line, so set sndx to end of line
             endIndex = line.length();
         }
        
         string token{line.substr(sndx, endIndex - sndx) };  // extract the token
         sndx = line.find_first_not_of(separators, endIndex + 1);  // again, find the start index of next token, if any
         cout << token << endl;
     }
}


//extracts and returns the tokens separated by theSeparators in the specified line
vector<string> Dictionary::extract_tokens_from_line(const string &line) const{
    // find the start index of first token, if any
    size_t sndx{ line.find_first_not_of(theSeparators) };
    
    //a vector to hold list of tokens, separated by theSeparators
    vector<string> tokens{};

    while (sndx != string::npos){    // while there are tokens
         size_t endIndex = line.find_first_of(theSeparators, sndx + 1);      // find the end of current token that starts at sndx
        
         if (endIndex == string::npos){ // we did reach the of line, so set sndx to end of line
             endIndex = line.length();
         }
        
         string token{line.substr(sndx, endIndex - sndx) };  // extract the token
         sndx = line.find_first_not_of(theSeparators, endIndex + 1);  // again, find the start index of next token, if any
        tokens.push_back(token);
     }
    return tokens;
}

//creates a token with the specified tokenText and line_number and then pushes (inserts)
//the token at the end of the bucket list corresponding to tokenText[0]
void Dictionary::push_back_into_bucket(const string &tokenText, size_t line_number){
    size_t bucketPosition = bucket_index(tokenText);
    Token newToken = {tokenText, line_number};
    token_list_buckets[bucketPosition].push_back(newToken);
}


//using extract_tokens_from_line and push_back_into_bucket, inserts the tokens
//extracted from the specified line and line_number into appropriate buckets
void Dictionary::extract_and_push(const string &line, size_t line_number){
    vector<string> tokens = extract_tokens_from_line(line);

    for (string &tokenText : tokens) {
        size_t bucketIndex = bucket_index(tokenText);
        list<Token> &targetList = token_list_buckets[bucketIndex];
        Token targetToken = {tokenText, line_number};
        
        if(hasToken(targetList, targetToken)){
            getToken(targetList, targetToken).push_back_line_number(line_number);
        } else {
            push_back_into_bucket(tokenText, line_number);
        }
    }
}


//prints all input lines, each preceded by line number
//prints the input lines beginning with the characters stored in char_set
//each line is preceded by its line numbers in the input file
//if char_set is empty, then it prints all input lines
void Dictionary::print_input_lines(set<char>& char_set) const {
    cout << "Input Lines" << endl << "===========" << endl;
    
    ifstream fin(filename);
    int linenum = 1;
    string line;
    getline(fin, line);

    while (fin){
        if(char_set.size() > 0){
            //get first character of each line, in lower case
            char firstCharacter = tolower(line[0]);
            
            //if first char of each line is included in given char_set, display line
            if(char_set.find(firstCharacter) != char_set.end()){
                cout << linenum << ". " <<  line << endl;
            }
            
        } else {
            cout << linenum << ". " <<  line << endl;
        }
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        getline(fin, line); // attempt to read the next line, if any
  
    }
    fin.close();
}

//compare function to give as a parameter to forward_list.sort()
bool tokenTextCompare(Token token1, Token token2){
    return token1 < token2;
}

void Dictionary::print_sorted_template(int filter) const {
    cout << "===================" << endl;
    //prepare a list of alphabets
    char alphabet[27] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    
    for (int i = 0; i < 27; i++) {
        //prints the sub-title of current index
        cout << "<" << alphabet[i] << ">" << endl;

        if (filter == 2) {
            for (Token tkn : token_list_buckets[i]){
               cout << tkn << "\n";
            }
        } else {
            forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

            switch(filter){
                case 3: flist.sort(tokenTextCompare);
                    break;
                case 4: flist.sort(isLessFrequent);
                    break;
                case 5: flist.sort(isShorter);
                    break;
            }

            for (Token tkn : flist){
               cout << tkn << "\n";
            }
        }

        cout << "" << endl;
        
    }
}

void Dictionary::print_sorted_template(set<char>& char_set, int filter) const{
    cout << "===================" << endl;
    //prepare a list of alphabets
    char alphabet[27] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    //set a flag 'hasNonAlpha' indicates if the char_set contains any non-alphabet
    bool hasNonAlpha = false;
    for(char ch: char_set){
        if(!isalpha(ch)){
            hasNonAlpha = true;
        }
    }
    
    for (int i = 0; i < 27; i++) {
        if(char_set.find( tolower(alphabet[i]) ) != char_set.end() || (i == 26 && hasNonAlpha)){
            char subTitleAlphabet = alphabet[i];
            cout << "<" << (char) tolower(subTitleAlphabet) << ">" << endl;

            if (filter == 2) {
                for (Token tkn : token_list_buckets[i]){
                   cout << setw(20) << tkn << "\n";
                }
            } else {
                forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

                switch(filter){
                    case 3: flist.sort(tokenTextCompare);
                        break;
                    case 4: flist.sort(isLessFrequent);
                        break;
                    case 5: flist.sort(isShorter);
                        break;
                }

                for (Token tkn : flist){
                   cout << setw(20) << tkn << "\n";
                }
            }

            cout << "" << endl;
        }
        
    }
}

//prints original unsorted tokens
//for each character ch in char-set:
//if ch is a letter, it prints original unsorted bucket corresponding to ch;
//if ch is not a letter, it prints the original unsorted foreign bucket.
void Dictionary::print_input_tokens() const {
    print_sorted_template(2);
}

void Dictionary::print_input_tokens(set<char>& char_set) const {
    print_sorted_template(char_set, 2);
}

//prints all buckets sorted on token text
void Dictionary::print_sorted_on_token_text() const {
    print_sorted_template(3);
}

//prints buckets of given char set sorted on token text
void Dictionary::print_sorted_on_token_text(set<char>& char_set) const {
    print_sorted_template(char_set, 3);
}

//prints all buckets sorted on token frequency
void Dictionary::print_sorted_on_token_frequency() const {
    print_sorted_template(4);
}

//prints buckets of given char set sorted on token frequency
void Dictionary::print_sorted_on_token_frequency(set<char>& char_set) const {
    print_sorted_template(char_set, 4);
}

//prints all buckets sorted on token length
void Dictionary::print_sorted_on_token_length() const {
    print_sorted_template(5);
}

//prints buckets of given char set sorted on token length
void Dictionary::print_sorted_on_token_length(set<char>& char_set) const {
    print_sorted_template(char_set, 5);
}


//replace \t and \n with \\t and \\n in separators and returns the resulting string
string Dictionary::escape_tab_newline_chars(const string& separators){
    string result{};

    for (char ch : separators){
        switch (ch){
            case '\n':
                result += "\\n";
                break;
            case '\t':
                result += "\\t";
                break;
            default:
                result += ch;
                break;
        }
    }
    return result;
}


bool Dictionary::hasToken(list<Token>& tokenList, Token& targetToken){
    for (list<Token>::iterator it = tokenList.begin(); it != tokenList.end(); ++it){
        if ((*it).compare(targetToken) == 0) return true;
    }
    return false;
}


Token& Dictionary::getToken(list<Token>& tokenList, Token& targetToken){
    for (list<Token>::iterator it = tokenList.begin(); it != tokenList.end(); ++it){
        if ((*it).compare(targetToken) == 0) return (*it);
    }
    return targetToken;
}

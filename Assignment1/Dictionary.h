#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include<string>
#include "TokenList.h"

using std::string;
class Dictionary {
    private:
        string filename; //file name to be parsed

        TokenList tokenListBuckets[27]; // 26 alpha buckets + 1 none-alpha bucket

        size_t bucketIndex(const string& token) const; //gets the index of given token to be placed in a bucket
    public:
        Dictionary(const string& filename); //constructor

        void processToken(const string& token, int linenum); //process the token to place in a bucket in right order

        void print(ostream& cout) const; //prints out the Dictionary

        Dictionary() = delete; // no default ctor

        ~Dictionary() = default; // default dtor

        Dictionary(const Dictionary&) = default; // copy ctor

        Dictionary(Dictionary&&) = default; // move ctor

        Dictionary& operator=(const Dictionary&) = default; // copy assignment

        Dictionary& operator=(Dictionary&&) = default; // move assignment
};

#endif


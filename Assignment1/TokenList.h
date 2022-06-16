#ifndef TokenList_h
#define TokenList_h
#include "Token.h"

using std::ostream;
using std::string;

class TokenList {
private:
    struct TNode {  //node inside of the TokenList
        Token theToken;  //Token inside of the node
        TNode* next;  //a pointer pointing the next node of current node

        TNode(const Token& aToken, TNode* next = nullptr) : theToken(aToken), next(next) {} //constructor with params
        TNode() = delete;   //basic constructor: no need
        TNode(const TNode& other) = delete; //copy constructor: no need
        TNode(TNode&& other) = delete; //move constructor: no need

        TNode& operator=(const TNode& other) = delete; //copy assignment: no need
        TNode& operator=(TNode&& other) = delete; //move assignment: no need
        virtual ~TNode() = default; //destructor
    };

    TNode* head{ nullptr }; //head of the TokenList
    TNode* tail{ nullptr }; //tail of the TokenList
    size_t theSize{ 0 }; //size of the TokenList

    bool remove(TNode* nodePtr); //remove a certain node
    TNode* lookup(const Token& aToken) const; //looks up for a certain Token from the TokenList
    void addAfter(TNode* p, const Token& aToken); //adds given token in front of the designated Node

public:
    TokenList();  //basic constructor

    TokenList(const TokenList& list); //copy constructor

    TokenList(TokenList&& list); //move constructor

    TokenList& operator=(const TokenList& rhs); //copy asisgnment

    TokenList& operator=(TokenList&& rhs); //move assignment

    ~TokenList(); //destructor

    bool empty() const; //checks if empty

    size_t size() const; //returns size of the TokenList

    void print(ostream& sout) const; //prints the TokenList

    const Token& front() const; //returns the head

    const Token& back() const; //returns the tail

    void addSorted(const Token& aToken); //add a Token to the TokenList upon sorting logic

    void addSorted(const string& str, int lineNum); //gets string and lineNum, wraps it as Token and add to the TokenList

    bool removeFront(); //removes head Node

    bool removeBack(); //removes tail Node

    bool search(const Token& aToken) const; //searches if the given token exists in the TokenList

    void addFront(const Token& aToken); //adds a Token to the Head

    void addBack(const Token& aToken); //adds a Token to the Tail

    void clear(); //cleans up the Token
};

ostream& operator<<(ostream& sout, const Token& f);


#endif /* TokenList_h */
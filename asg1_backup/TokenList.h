#ifndef TokenList_h
#define TokenList_h
#include "Token.h"

using std::ostream;
using std::string;

class TokenList {
private:
    struct TNode{
        Token theToken;
        TNode* next;
        
        TNode(const Token& aToken, TNode* next = nullptr): theToken(aToken), next(next){}
        TNode() = delete;
        TNode(const TNode& other) = delete;
        TNode(TNode&& other) = delete;
        
        TNode& operator=(const TNode& other) = delete;
        TNode& operator=(TNode&& other) = delete;
        virtual ~TNode() = default;
    };
    
    TNode* head{ nullptr };
    TNode* tail{ nullptr };
    size_t theSize { 0 };
    
    bool remove(TNode* nodePtr);
    TNode* lookup(const Token& aToken) const;
    void addAfter(TNode* p, const Token& aToken);
    
public:
    TokenList();
       
    TokenList(const TokenList& list);
    
    TokenList(TokenList&& list);
    
    TokenList& operator=(const TokenList& rhs);

    TokenList& operator=(TokenList&& rhs);

    ~TokenList();
    
    bool empty() const;

    size_t size() const;

    void print (ostream& sout) const;
    
    const Token& front() const;
    
    const Token& back() const;
    
    void addSorted(const Token& aToken);
    
    void addSorted(const string& str, int lineNum);
    
    bool removeFront();
    
    bool removeBack();
    
    bool search(const Token& aToken) const;
    
    void addFront(const Token& aToken);

    void addBack(const Token& aToken);

    void clear();
};

ostream& operator<<(ostream& sout, const Token& f);


#endif /* TokenList_h */

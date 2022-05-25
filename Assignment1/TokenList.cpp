#include <stdio.h>
#include "TokenList.h"
#include "Token.h"

TokenList::TokenList(): head{}, tail{}, theSize{}{}

//copy constructor
TokenList::TokenList(const TokenList& list){
    
}

//move constructor
TokenList::TokenList(TokenList&& list){
    
}

//copy assignment
TokenList& TokenList::operator=(const TokenList& rhs){
    if(&rhs != this){
        
    }
    
    return *this;
}

//move assignment
TokenList& TokenList::operator=(TokenList&& rhs){
    if(&rhs != this){
        
    }

    return *this;
}

TokenList::~TokenList(){
    head -> next = nullptr;
    head = NULL;
}

bool TokenList::empty() const {
    return size() == 0 ? true : false;
}

size_t TokenList::size() const {
    size_t tokenSize = 0;
    TNode *temp = head;
    if(head == NULL){
        return 0;
    }
    if(head == tail){
        return 1;
    } else {
        while(temp != NULL){
            temp = temp -> next;
            tokenSize++;
        }
    }
    return tokenSize;
}



void TokenList::print(ostream& sout) const {
    sout << "[" << endl;
     for (TNode* temp = head; temp != nullptr; temp = temp -> next)
     {
         sout << temp -> theToken << " " << endl;
     }
     sout << "]" << endl;
}

//const Token& TokenList::front() const {
//
//}
//
//const Token& TokenList::back() const {
//
//}

void TokenList::addSorted(const Token &aToken){
    if(head == NULL){
        addBack(aToken);
        return;
    } else {
        int compVal = head->theToken.compare(aToken);

        if(compVal < 0){
            addBack(aToken);
        } else {
            addFront(aToken);
        }
    }
    return;
}

void TokenList::addSorted(const string& str, int lineNum){
    
}

//bool TokenList::removeFront(){

//}

//bool TokenList::removeBack(){

//}

//bool TokenList::search(const Token& aToken) const(){}
//

void TokenList::addFront(const Token& aToken){
    TNode *newNode = new TNode(aToken);
    newNode->next = head;
    head = newNode;
    theSize++;
    
    if (tail == NULL){
        tail = head;
    }
    return;
}

void TokenList::addBack(const Token& aToken){
    TNode* newNode = new TNode(aToken);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    theSize++;
}

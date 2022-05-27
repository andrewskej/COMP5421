#include <stdio.h>
#include "TokenList.h"
#include "Token.h"
using std::cout;
using std::endl;
TokenList::TokenList(): head{nullptr}, tail{nullptr}, theSize{}{}

//copy constructor
TokenList::TokenList(const TokenList& list): head{}, tail{}, theSize{}{
    cout << "copy ctor" << endl;
    head = list.head;
    tail = list.tail;
    theSize = list.theSize;
}

//move constructor
TokenList::TokenList(TokenList&& list): head{}, tail{}, theSize{}{
    cout << "move ctor" << endl;
    head = list.head;
    tail = list.tail;
    theSize = list.theSize;

    list.head -> next = nullptr;
    list.head = NULL;
    list.theSize = 0;
}

//copy assignment
TokenList& TokenList::operator=(const TokenList& rhs){
    if(&rhs != this){
        cout << "copy assignment" << endl;
        delete head;
        head = rhs.head;
        tail = rhs.tail;
        theSize = rhs.theSize;
    }
    
    return *this;
}

//move assignment
TokenList& TokenList::operator=(TokenList&& rhs){
    if(&rhs != this){
        cout << "move assignment" << endl;
        delete head;
        head = rhs.head;
        tail = rhs.tail;
        theSize = rhs.theSize;
        
        rhs.head -> next = nullptr;
        rhs.head = NULL;
        rhs.theSize = 0;
    }

    return *this;
}

TokenList::~TokenList(){
//    if(head -> next != nullptr)head -> next = nullptr;
    head = NULL;
    tail = NULL;
}

bool TokenList::empty() const {
    return size() == 0 ? true : false;
}

void TokenList::clear(){
    while(!empty()){
        removeFront();
    }
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
//    sout << endl;
     for (TNode* temp = head; temp != nullptr; temp = temp -> next)
     {
         sout << " " << temp -> theToken << " " << endl;
     }
     sout << endl;
}

 
void TokenList::addSorted(const Token& aToken){
    ArrayList list = aToken.getNumberList();
    int line_number{};
    list.get(list.size() - 1, line_number);
    addSorted(aToken.c_str(), line_number);
}

void TokenList::addSorted(const string& str, int lineNumber){
    Token aToken(str.c_str(), lineNumber);
    TNode* nodePtr = lookup(aToken);

    if (nodePtr == nullptr){
      addFront(aToken);
      return;
    }

   if ((nodePtr->theToken).compare(aToken) == 0){
      (nodePtr->theToken).addLineNumber(lineNumber);
      return;
   } else {
      addAfter(nodePtr, aToken);
      return;
   }
}

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

//Retruns the token in this list
const Token& TokenList::front() const {
    TNode *temp = head;
    return temp -> theToken;
}

//Retruns the token in this list
const Token& TokenList::back() const {
    TNode *temp = tail;
    return temp -> theToken;
}


bool TokenList::removeFront(){
    if(head != NULL){
        head = head -> next;
        theSize--;
        return true;
    }else{
        return false;
    }
}

bool TokenList::removeBack(){
    if(head != NULL){
        TNode *currentNode;
        currentNode = head;
        
        while(currentNode -> next != NULL){
            currentNode = currentNode -> next;
            tail = currentNode;
            if(tail -> next -> next == NULL){
                tail -> next = NULL;
                theSize--;
                return true;
            }
        }
        return true;
    }else{
        return false;
    }
}

// Determines whether aToken is in the list.
bool TokenList::search(const Token& aToken) const{
    
    if(head != NULL){
        TNode * currentNode{head};
        
        while(currentNode -> next != NULL){
            int compareVal = (currentNode -> theToken).compare(aToken);
            if(compareVal == 0){
                cout << "It is in the list" << endl;
                return true;
            } else {
                cout << "Checking next node..." << endl;
                currentNode = currentNode -> next;
            }
        }
    }else{
        cout << "Empty list" << endl;
        return false;
    }
    cout << "No result" << endl;
    return false;
}


bool TokenList::remove(TNode* nodePtr){
    if(nodePtr != nullptr){
        if(nodePtr == head){
            removeFront();
            return true;
        }
        
        TNode *current{};
        current = head;
        
        while(current -> next != nullptr){
            if(current -> next != nodePtr){
                current = current -> next;
            } else {
                current -> next = current -> next -> next;
                theSize--;
                return true;
            }
        }
    }
    return false;
}


//the Token aToken goes after TNode p
void TokenList::addAfter(TNode* p, const Token& aToken){

    if(p == nullptr){
        addFront(aToken);
    }
    
    TNode *newNode = new TNode(aToken);
    TNode *current = head;
    
    while(current != p){
        current = current -> next;
    }
    
    if(current == tail){
        addBack(aToken);
    } else {
        newNode -> next = current -> next;
        current -> next = newNode;
        theSize++;
    }
}

TokenList::TNode* TokenList::lookup(const Token& aToken) const{
   if (head == nullptr) {
       return nullptr;
   }

   if (aToken.compare(head->theToken) < 0){
      return nullptr;
   }
  
   TNode* prev = head;          // may or may not be the node of interest
   TNode* current = head->next; // ->next works because head is not nullptr

   while (current != nullptr) {
      

      if ((current->theToken).compare(aToken) > 0){
        
          return prev;
      }

      prev = current;
      current = current->next;
   }

   return tail;
}

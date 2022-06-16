#include <stdio.h>
#include "TokenList.h"
#include "Token.h"

/*
* basic constructor
*/
TokenList::TokenList() : head{ nullptr }, tail{ nullptr }, theSize{}{}

/*
* copy constructor
@param list: the original TokenList to be copy
*/
TokenList::TokenList(const TokenList& list) : head{}, tail{}, theSize{}{
    head = list.head;
    tail = list.tail;
    theSize = list.theSize;
}

/*
* move constructor
@param list: the original TokenList to be moved
*/
TokenList::TokenList(TokenList&& list) : head{}, tail{}, theSize{}{
    head = list.head;
    tail = list.tail;
    theSize = list.theSize;

    list.head->next = nullptr;
    list.head = NULL;
    list.theSize = 0;
}

/*
* copy assignment operator overloading
@param rhs: the right hand side TokenList to be copied
*/
TokenList& TokenList::operator=(const TokenList& rhs) {
    if (&rhs != this) {
        delete head;
        head = rhs.head;
        tail = rhs.tail;
        theSize = rhs.theSize;
    }

    return *this;
}

/*
* move assignment operator overloading
@param rhs: the right hand side TokenList to be moved
*/
TokenList& TokenList::operator=(TokenList&& rhs) {
    if (&rhs != this) {
        delete head;
        head = rhs.head;
        tail = rhs.tail;
        theSize = rhs.theSize;

        rhs.head->next = nullptr;
        rhs.head = NULL;
        rhs.theSize = 0;
    }

    return *this;
}

/*
* desctructor
*/
TokenList::~TokenList() {
    head = NULL;
    tail = NULL;
}

/*
* check if it is empty or not
*/
bool TokenList::empty() const {
    return size() == 0 ? true : false;
}

/*
* clear out the list
*/
void TokenList::clear() {
    while (!empty()) {
        removeFront();
    }
}

/*
* find outand return the size of the list
* @return tokenSize
*/
size_t TokenList::size() const {
    size_t tokenSize = 0;
    TNode* temp = head;

    //if the list is empty
    if (head == NULL) {
        return 0;
    }
    //if the list is only size of 1
    if (head == tail) {
        return 1;
    }
    else {
        //while there is more node
        while (temp != NULL) {
            //traverse to next node, and add up the size to measure
            temp = temp->next;
            tokenSize++;
        }
    }
    return tokenSize;
}

/*
* print out the TokenList
* @param sout ostream to be passed on
*/
void TokenList::print(ostream& sout) const {
    for (TNode* temp = head; temp != nullptr; temp = temp->next)
    {
        sout << " " << temp->theToken << " " << std::endl;
    }
    sout << std::endl;
}

/*
* add Token with sorting logic
* @param aToken Token to be added
*/
void TokenList::addSorted(const Token& aToken) {
    ArrayList list = aToken.getNumberList();
    int line_number{};
    list.get(list.size() - 1, line_number);
    addSorted(aToken.c_str(), line_number);
}

/*
* add Token with sorting logic
* @param str given string to be wrapped as Token
* @param lineNumber given line number to be wrapped as Token
*/
void TokenList::addSorted(const string& str, int lineNumber) {
    Token aToken(str.c_str(), lineNumber);
    TNode* nodePtr = lookup(aToken);

    if (nodePtr == nullptr) {
        addFront(aToken);
        return;
    }

    if ((nodePtr->theToken).compare(aToken) == 0) {
        (nodePtr->theToken).addLineNumber(lineNumber);
        return;
    }
    else {
        addAfter(nodePtr, aToken);
        return;
    }
}

/*
* add Token to the front of the TokenList
* @param aToken given Token to be added
*/
void TokenList::addFront(const Token& aToken) {
    TNode* newNode = new TNode(aToken);
    newNode->next = head;
    head = newNode;
    theSize++;

    if (tail == NULL) {
        tail = head;
    }
    return;
}

/*
* add Token to the back of the TokenList
* @param aToken given Token to be added
*/
void TokenList::addBack(const Token& aToken) {
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

/*
* Retruns the head token of the list
*/
const Token& TokenList::front() const {
    TNode* temp = head;
    return temp->theToken;
}

/*
* Retruns the tail token of the list
*/
const Token& TokenList::back() const {
    TNode* temp = tail;
    return temp->theToken;
}

/*
* removes the head Token
*/
bool TokenList::removeFront() {
    if (head != NULL) {
        head = head->next;
        theSize--;
        return true;
    }
    else {
        return false;
    }
}

/*
* removes the tail Token
*/
bool TokenList::removeBack() {
    if (head != NULL) {
        TNode* currentNode;
        currentNode = head;

        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
            tail = currentNode;
            if (tail->next->next == NULL) {
                tail->next = NULL;
                theSize--;
                return true;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

/*
* Determines whether aToken is in the list.
* @param aToken given token to be searched
*/ 
bool TokenList::search(const Token& aToken) const {

    if (head != NULL) {
        TNode* currentNode{ head };

        while (currentNode->next != NULL) {
            int compareVal = (currentNode->theToken).compare(aToken);
            if (compareVal == 0) {
                return true;
            }
            else {
                currentNode = currentNode->next;
            }
        }
    }
    else {
        return false;
    }
    return false;
}

/*
* removes the Token of given pointer Node 
* @param *nodePtr a node pointer to be removed
*/
bool TokenList::remove(TNode* nodePtr) {
    if (nodePtr != nullptr) {
        if (nodePtr == head) {
            removeFront();
            return true;
        }

        TNode* current{};
        current = head;

        while (current->next != nullptr) {
            if (current->next != nodePtr) {
                current = current->next;
            }
            else {
                current->next = current->next->next;
                theSize--;
                return true;
            }
        }
    }
    return false;
}


/*
* the Token aToken goes after TNode p
*/
void TokenList::addAfter(TNode* p, const Token& aToken) {

    if (p == nullptr) {
        addFront(aToken);
    }

    TNode* newNode = new TNode(aToken);
    TNode* current = head;

    while (current != p) {
        current = current->next;
    }

    if (current == tail) {
        addBack(aToken);
    }
    else {
        newNode->next = current->next;
        current->next = newNode;
        theSize++;
    }
}

/*
* looks up for a given Token from the TokenList
*/
TokenList::TNode* TokenList::lookup(const Token& aToken) const {
    if (head == nullptr) {
        return nullptr;
    }

    if (aToken.compare(head->theToken) < 0) {
        return nullptr;
    }

    TNode* prev = head;          // may or may not be the node of interest
    TNode* current = head->next; // ->next works because head is not nullptr

    while (current != nullptr) {

        if ((current->theToken).compare(aToken) > 0) {
            return prev;
        }

        prev = current;
        current = current->next;
    }

    return tail;
}
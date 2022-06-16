#include<iostream>
#include "ArrayList.h"
using std::ostream;

/*
* basic constructor
*/
ArrayList::ArrayList()
    : capacity{ 1 }, used{ 0 }, pArray{ new int[1] }{}

/*
* copy constructor
@param originalAry: the original ArrayList to be copied
*/
ArrayList::ArrayList(const ArrayList& originalAry)
    : capacity{ originalAry.getCapacity() }, used{ originalAry.size() }, pArray{ new int[originalAry.size()] }{

    for (int i = 0; i < used; i++) {
        pArray[i] = originalAry.pArray[i];
    }
}

/*
* move constructor
@param originalAry: the original ArrayList to be moved
*/
ArrayList::ArrayList(ArrayList&& originalAry) noexcept
    : capacity{ originalAry.capacity }, used{ originalAry.used }{
    originalAry.capacity = 1;
    originalAry.used = 0;
    originalAry.pArray = nullptr;
}

/*
* copy assignment operator overloading
@param rhs: the right hand side ArrayList to be copied
*/
ArrayList& ArrayList::operator=(const ArrayList& rhs) {
    if (&rhs != this) {
        delete[] pArray;

        capacity = rhs.capacity;
        used = rhs.used;
        pArray = new int[capacity];

        for (int i = 0; i < used; i++) {
            pArray[i] = rhs.pArray[i];
        }
    }
    return *this;
}

/*
* move assignment operator overloading
@param rhs: the right hand side ArrayList to be moved
*/
ArrayList& ArrayList::operator=(ArrayList&& rhs) noexcept {
    if (&rhs != this) {
        delete[] pArray;

        pArray = rhs.pArray;
        used = rhs.used;
        capacity = rhs.capacity;

        rhs.pArray = nullptr;
        rhs.used = 0;
        rhs.capacity = 1;
    }
    return *this;
}


/*
* desctructor
*/
ArrayList::~ArrayList() {
    delete[] pArray;
}

/*
* resize its capacity by double
*/
void ArrayList::resize() {
    int cap = 2 * capacity;
    int* temp = new int[cap];

    for (int k = 0; k < capacity; ++k) {
        temp[k] = pArray[k];
    }
    delete[] pArray;
    pArray = temp;
    capacity = cap;
}

/*
* check if the ArrayList is empty
*/
bool ArrayList::empty() const {
    return used == 0;
}

/*
* check if the ArrayList is full. if used area is same is current capacity, it is full
*/
bool ArrayList::full() const {
    return used == capacity;
}

/*
@return the size of used area of the ArrayList
*/
int ArrayList::size() const {
    return used;
}

/*
* push a given value into the ArrayList
* @param x the given value
*/
void ArrayList::pushBack(int x) {
    if (used == capacity) {
        resize();
    }

    pArray[used] = x;
    used++;
}

/*
* check to see if the ArrayList contains the given value
* @param x the given value to be checked
*/
bool ArrayList::contains(int x) const {
    for (int i = 0; i < used; i++) {
        if (pArray[i] == x) {
            return true;
        }
    }
    return false;
}

/*
* to check the value from the ArrayList at given position
* @param position position to find the value
* @param &value value to find
*/
bool ArrayList::get(int position, int& value) const {
    if (position > used) {
        return false;

    }
    else {
        value = pArray[position];
        return true;
    }
}

/*
* gets the capacity of the ArrayList
*/
int ArrayList::getCapacity() const {
    return capacity;
}

/*
* print out the ArrayList
* @param sout ostream to be passed on
*/
void ArrayList::print(ostream& sout) const {
    if (used > 0) {
        for (int i = 0; i < used; i++) {
            if (i == used - 1) {
                sout << pArray[i] << "";
            }
            else {
                sout << pArray[i] << " ";
            }
        }
    }
    else {
        sout << " ";
    }
}

/*
* operator overloading: <<
*/
ostream& operator<<(ostream& sout, const ArrayList& f) {
    f.print(sout);
    return sout;
}
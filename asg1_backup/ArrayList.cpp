#include<iostream>
#include "ArrayList.h"
using std::ostream;

ArrayList::ArrayList()
    : capacity{1}, used{0}, pArray{new int[1]}{}

//copy constructor
ArrayList::ArrayList(const ArrayList& originalAry)
: capacity{originalAry.getCapacity()}, used{originalAry.size()}, pArray{new int[originalAry.size()]}{

    for(int i = 0; i < used; i++){
        pArray[i] = originalAry.pArray[i];
    }
}

//move constructor
ArrayList::ArrayList(ArrayList&& originalAry) noexcept
    : capacity{originalAry.capacity}, used{originalAry.used}{
        originalAry.capacity = 1;
        originalAry.used = 0;
        originalAry.pArray = nullptr;
}

//copy assignment operator overloading
ArrayList& ArrayList::operator=(const ArrayList& rhs){
    if(&rhs != this){
        delete [] pArray;
        
        capacity = rhs.capacity;
        used = rhs.used;
        pArray = new int[capacity];
        
        for(int i = 0; i < used; i++){
            pArray[i] = rhs.pArray[i];
        }
    }
    return *this;
}

//move assignment operator overloading
ArrayList& ArrayList::operator=(ArrayList&& rhs) noexcept{
    if (&rhs != this){
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


ArrayList::~ArrayList(){
    delete[] pArray;
}

void ArrayList::resize(){
    int cap = 2 * capacity;
    int *temp = new int[cap];
    
    for(int k = 0; k < capacity; ++k){
        temp[k] = pArray[k];
    }
    delete[] pArray;
    pArray = temp;
    capacity = cap;
}

bool ArrayList::empty() const{
    return used == 0;
}

bool ArrayList::full() const {
    return used == capacity;
}

int ArrayList::size() const {
    return used;
}

void ArrayList::pushBack(int x){
    if(used == capacity){
        resize();
    }

    pArray[used] = x;
    used++;
}

bool ArrayList::contains(int x) const {
    for(int i = 0; i < used; i++){
        if(pArray[i] == x){
            return true;
        }
    }
    return false;
}


bool ArrayList::get(int position, int &value) const {
    if(position > used) {
        return false;
        
    } else {
        value = pArray[position];
        return true;
    }
}

int ArrayList::getCapacity() const{
    return capacity;
}


void ArrayList::print(ostream& sout) const{
    if(used > 0){
        for(int i = 0; i < used; i++){
            if(i == used-1){
                sout << pArray[i] << "";
            } else {
                sout << pArray[i] << " ";
            }
        }
    } else {
        sout << " ";
    }
}


ostream& operator<<(ostream& sout, const ArrayList& f){
    f.print(sout);
    return sout;
}

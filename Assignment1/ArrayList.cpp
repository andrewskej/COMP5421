#include<iostream>
#include<cassert>
#include "ArrayList.h"
using std::cout;
using std::endl;
using std::ostream;

ArrayList::ArrayList()
    :capacity{1},used{0},pArray{new int[1]}{}


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


//wip;
bool ArrayList::get(int position, int &value) const {
    //returns false if position is out of range
    //otherwise, places the value stored at position
    //in the reference parameter value and then returns true
    if(position > used) {
        return false;
        
    } else {
        pArray[position] = value;
        return true;
    }
}

int ArrayList::getCapacity(){
    return capacity;
}


void ArrayList::print(ostream& sout) const{
    if(used > 0){
        for(int i = 0; i < used; i++){
            if(i == used-1){
                sout << pArray[i] << "";
            } else {
                sout << pArray[i] << ", ";
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

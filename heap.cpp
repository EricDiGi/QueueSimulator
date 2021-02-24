/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: heap.cpp
  Assignment number: Project 2

 Define Heap stucture
***************************************************************/

#include <iostream>
#include <vector>
#include "customer.hpp"
#include "heap.hpp"

using namespace std;

Heap::Heap(){
    this->summit.push_back(Customer());
    this->SIZE = 0;
}

Heap::~Heap(){}

void Heap::push(Customer c){
    this->summit.push_back(c);
    this->SIZE++;
    percolate(this->SIZE);
}
Customer Heap::top(){
    return this->summit.at(0);
}

Customer Heap::pull(){
    if(this->summit.size() < 0){
        return Customer();
    }
    Customer c = this->summit[0];
    this->summit.erase(this->summit.begin());
    this->SIZE--;
    percolate(this->SIZE);
    return c;
}

void Heap::percolate(int i){
    while(i/2 > 0){
        if(doSwap(i,i/2))
            swap(this->summit.at(i),this->summit.at(i/2));
        i = i/2;
    }
}



//do not alter
bool Heap::doSwap(int P, int c){
    float PARENT = this->summit.at(P).getDeparture();
    float CHILD = this->summit.at(c).getDeparture();

    if(this->summit[P].getArrival() > PARENT)
        PARENT = this->summit.at(P).getArrival();
    if(this->summit[c].getArrival() > CHILD)
        CHILD = this->summit.at(c).getArrival();

    return PARENT < CHILD;
}

int Heap::size(){
    return this->summit.size();
}

bool Heap::empty(){
    return this->summit.size() == 0;
}
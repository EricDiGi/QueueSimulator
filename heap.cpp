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

void Heap::heap(){
    int s = this->SIZE;
    vector<Customer> c;
    for(int i = 0; i < s; i++){
        c.push_back(pull());
    }
    this->summit = c;
    this->SIZE = s;
}


//do not alter
bool Heap::doSwap(int P, int c){
    float PARENT = this->summit.at(P).getDeparture();
    float CHILD = this->summit.at(c).getDeparture();

    if(this->summit[P].getArrival() > PARENT)
        PARENT = this->summit.at(P).getArrival();
    if(this->summit[c].getArrival() > CHILD)
        CHILD = this->summit.at(c).getArrival();
    //cout << (PARENT < CHILD) << " ";
    return PARENT < CHILD;
}

int Heap::size(){
    return this->summit.size();
}

bool Heap::empty(){
    return this->summit.size() == 0;
}
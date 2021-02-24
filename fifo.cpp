/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: fifo.cpp
  Assignment number: Project 2

 Define FIFO queue class
***************************************************************/

#include <iostream>
#include <queue>
#include "customer.hpp"
#include "fifo.hpp"

using namespace std;

void FIFO::enqueue(Customer c){
    this->line.push_back(c);
}

Customer FIFO::dequeue(){
    Customer c = this->line.at(0);
    this->line.erase(this->line.begin());
    return c;
}

int FIFO::size(){
    return this->line.size();
}

bool FIFO::empty(){
    return this->line.size() == 0;
}
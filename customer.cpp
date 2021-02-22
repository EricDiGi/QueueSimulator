#include <iostream>
#include "customer.hpp"

using namespace std;

Customer::Customer(){
    this->arrivalTime = 0;
    this->startOfService = 0;
    this->departureTime = 0;
    this->next = NULL;
}

Customer::Customer(float t){
    this->arrivalTime = t;
    this->startOfService = 0;
    this->departureTime = 0;
    this->next = NULL;
}

Customer::Customer(const Customer &c){
    this->arrivalTime = c.arrivalTime;
    this->startOfService = c.startOfService;
    this->departureTime = c.departureTime;
    //this->q = 0;
    this->next = c.next;
}

Customer::~Customer(){
    this->next = NULL;
}

void Customer::setArrival(float t){
    this->arrivalTime = t;
    //this->q = t;
}
float Customer::getArrival(){
    return this->arrivalTime;
}

void Customer::setSOS(float t){
    this->startOfService = t;
}
float Customer::getSOS(){
    return this->startOfService;
}

void Customer::setDeparture(float t){
    this->departureTime = t;
    //this->q = t;
}
float Customer::getDeparture(){
    return this->departureTime;
}

void Customer::setNext(Customer* n){
    this->next = n;
}
Customer* Customer::getNext(){
    return this->next;
}
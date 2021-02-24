/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: customer.cpp
  Assignment number: Project 2

 Define customer class
***************************************************************/

#include <iostream>
#include "customer.hpp"

using namespace std;

Customer::Customer(){
    this->arrivalTime = 0;
    this->startOfService = 0;
    this->departureTime = 0;
}

Customer::Customer(float t){
    this->arrivalTime = t;
    this->startOfService = 0;
    this->departureTime = 0;
}

Customer::Customer(const Customer &c){
    this->arrivalTime = c.arrivalTime;
    this->startOfService = c.startOfService;
    this->departureTime = c.departureTime;
}

Customer::~Customer(){} // More of a formality

void Customer::setArrival(float t){
    this->arrivalTime = t;
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
}
float Customer::getDeparture(){
    return this->departureTime;
}

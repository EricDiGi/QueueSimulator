/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: sim.cpp
  Assignment number: Project 2

 Define Simulation parameters and processes
***************************************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"
#include "statistics.hpp"
#include "sim.hpp"

using namespace std;

Simulation::Simulation(){
    srand((unsigned int)time(NULL));
    this->M = this->n = 0;
    this->lambda = this->mu = 0;
    this->massTime = 0.0;
    this->numCust = 0;
    this->servers = 0;
    this->stats.setInitialState(this->n,this->lambda,this->mu,this->M);
    this->currentDepartTime = 0;
    this->totalWait = 0;
    this->serviceTime = 0;
    this->idleTime = 0;
}

Simulation::Simulation(int n, float l, float m, int M){
    srand((unsigned int)time(NULL));
    this->M = M;
    this->n = n;
    this->lambda = l;
    this->mu = m;
    this->massTime = 0.0;
    this->numCust = 0;
    this->servers = 0;
    this->stats.setInitialState(this->n,this->lambda,this->mu,this->M);
    this->currentDepartTime = 0;
    this->totalWait = 0;
    this->serviceTime = 0;
    this->idleTime = 0;
}

bool Simulation::moreArrivals(){
    return this->numCust < this->n;
}

void Simulation::putPQ(int v){
    float t = 0.0;
    for(int i = 0; (i < v) && moreArrivals(); i++){
        t = nextRand(this->lambda);
        this->massTime += t;
        Customer c = Customer(this->massTime);
        this->PQ.push(c);
        this->numCust++;
    }
}


double Simulation::nextRand(float avg){
    int max = 10000;
    double r = -1;
    while(r <= 0){
        r = double(rand()%(max-1))/double((max));
    }
    double i = -1.0*(1.0/avg)*log(r);
    return i;

}

void Simulation::processNextEvent(){
    Customer c = this->PQ.pull();
    if(c.getArrival() > c.getDeparture()){
        if(this->servers > 0){
            this->servers --;
            c.setSOS(c.getArrival());
            float i = nextRand(this->mu);
            c.setDeparture(c.getSOS() + i);
            this->PQ.push(c);
        }
        else{
            this->FQ.enqueue(c);
        }
    }
    else{
        this->servers++;
        this->currentDepartTime = c.getDeparture();
        processStats(c);
        
        //JUST IN CASE
        if(this->PQ.size() >= 200)
            cout << "too big\n";
        if(this->FQ.size() > 0){
            c = this->FQ.dequeue();
            this->servers--;
            float i = nextRand(this->mu);
            c.setSOS(this->currentDepartTime);
            i = nextRand(this->mu);
            c.setDeparture(c.getSOS() + i);
            this->PQ.push(c);
        }
    }
}

void Simulation::processStats(Customer c){
    this->stats.allTime(this->currentDepartTime);
    double waitTime = c.getSOS() - c.getArrival();
    if(waitTime > 0)
        this->stats.incrementCustomerWait();
    this->stats.totalWait(waitTime);
    this->stats.serviceTime((double)c.getDeparture() - (double)c.getSOS());
    if(this->servers == M && this->FQ.empty() && !this->PQ.empty()){
        if(this->PQ.top().getArrival() > this->currentDepartTime)
            this->stats.idleTime(this->PQ.top().getArrival() - this->currentDepartTime);
    }
}

void Simulation::main_(){
    this->servers = this->M;
    putPQ(this->M);
    while(!this->PQ.empty()){
        processNextEvent();
        if(moreArrivals() && this->PQ.size() <= 2*this->M+1)
            putPQ(this->M);
    }
    this->stats.Display();
}
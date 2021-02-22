#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"
#include "sim.hpp"

using namespace std;

Simulation::Simulation(){
    srand((unsigned int)time(NULL));
    this->M = this->n = 0;
    this->lambda = this->mu = 0;
    this->massTime = 0.0;
    this->numCust = 0;
    this->servers = 0;
    this->currentDepartTime = 0;
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
    this->currentDepartTime = 0;
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


float Simulation::nextRand(float avg){
    float r = float(rand()%(RAND_MAX-1))/float((RAND_MAX));
    float i = -1.0*(1.0/avg)*log(r);
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
            this->FQ.push(c);
        }
    }
    else{
        this->servers++;
        this->currentDepartTime = c.getDeparture();
        //JUST IN CASE
        if(this->PQ.size() >= 200)
            cout << "too big\n"
            
        if(this->FQ.size() > 0){
            c = this->FQ.pull();
            this->servers--;
            float i = nextRand(this->mu);
            c.setSOS(this->currentDepartTime);
            i = nextRand(this->mu);
            c.setDeparture(c.getSOS() + i);
            this->PQ.push(c);
        }
    }
}

void Simulation::main_(){
    this->servers = this->M;
    putPQ(this->M);
    while(!this->PQ.empty()){
        processNextEvent();
        if(moreArrivals() && this->PQ.size() <= this->M+1)
            putPQ(this->M);
    }
    cout << this->PQ.size() << " " << this->FQ.size() << endl;
    cout << this->numCust << endl;
    cout << this->currentDepartTime << endl;
}
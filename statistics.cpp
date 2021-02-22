#include <iostream>
#include <cmath>
#include "statistics.hpp"

using namespace std;

int Statistics::factorial(int i){
    if(i == 0)
        return 1;
    return i*factorial(i-1);
}

double Statistics::sum(int M, double l, double mu){
    double acc = 0.0;
    for(int i = 0; i < M; i++){
        acc += (1.0/(double)factorial(i))*pow(l/mu, i);
    }
    return acc;
}

void Statistics::setInitialState(int n, float l, float m, int M){
    this->n = n;
    this->lambda = l;
    this->mu = m;
    this->M = M;
}


void Statistics::incrementCustomerWait(){
    this->customerWait++;
}

void Statistics::totalWait(float v){
    this->totalWaitTime += v;
}

void Statistics::serviceTime(float v){
    this->accumServiceTime += v;
}

void Statistics::idleTime(float v){
    this->totalIdleTime += v;
}

void Statistics::allTime(float v){
    this->totalTime = v;
}


double Statistics::percentIdle(){
        double SUM = sum(this->M, this->lambda, this->mu);
        double addon = (1.0/(double)factorial(M))*pow(this->lambda/this->mu, this->M);
        double mod = (this->M*this->mu);
        double mult = mod/(mod-this->lambda);
        double Po = 1.0 / (SUM + addon*mult);
        return Po;
}

double Statistics::truePercentIdle(){
    return (this->totalIdleTime/this->totalTime); //% of all time spent idling
}


double Statistics::avgPopulation(){
    double numerator = (this->lambda*this->mu) * pow((double)this->lambda/(double)this->mu, this->M);
    double denom = factorial(this->M-1)*pow((this->M*this->mu) - this->lambda, 2);
    double full = (numerator/denom)*percentIdle() + ((double)this->lambda/(double)this->mu);
    return full;
}

double Statistics::trueAvgPopulation(){
    return this->accumServiceTime/this->M;
}

double Statistics::avgTimeIn(){
    double aTI = avgPopulation()/this->lambda;
    return aTI;
}

double Statistics::trueAvgTimeIn(){
    float time = this->totalWaitTime + this->accumServiceTime;
    return time/this->n;
}

double Statistics::avgNumInQ(){
    double aNIQ = avgPopulation() - (this->lambda/this->mu);
    return aNIQ;
}

double Statistics::trueAvgNumInQ(){
    return trueAvgTimeIn() * (this->totalWaitTime / this->totalTime);
}

double Statistics::avgTimeWaiting(){
    double aTW = avgNumInQ()/this->lambda;
    return aTW;
}

double Statistics::trueAvgTimeWaiting(){
    return (this->totalWaitTime)/(float)this->n;
}

double Statistics::RHO(){
    double rho = this->lambda/(this->M*this->mu);
    return rho;
}

double Statistics::trueRHO(){
    return this->accumServiceTime/(this->M*this->totalTime);
}

void Statistics::FULLSEND(){
    cout << "customer waited - " << this->customerWait << "\n"
    << "total time - " << this->totalTime << "\n"
    << "total wait time - " << this->totalWaitTime << "\n"
    << "total service time - " << this->accumServiceTime << "\n"
    << "total idle time - " << this->totalIdleTime << "\n";

    cout << "Po = " << percentIdle() << "\tActual Percent Idle:: " << truePercentIdle() << endl;
    //cout << "L = " << avgPopulation() << "\t" << trueAvgPopulation() << endl;
    cout << "W = " << avgTimeIn() << "\tActual Avg Time in System:: " << trueAvgTimeIn() << endl;
    //cout << "Lq = " << avgNumInQ() << "\t" << trueAvgNumInQ() << endl;
    cout << "Wq = " << avgTimeWaiting() << "\tActual Time Waiting:: " << trueAvgTimeWaiting() << endl;
    cout << "rho = " << RHO() << "\tActual Util. Factor:: " << trueRHO() << endl;
}
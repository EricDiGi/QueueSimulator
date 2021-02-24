/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: statistics.cpp
  Assignment number: Project 2

 Define Statistical equations
***************************************************************/


#include <iostream>
#include <iomanip>
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
    return (this->accumServiceTime + (this->totalWaitTime/this->accumServiceTime))/this->totalTime;
}

double Statistics::avgTimeIn(){
    double aTI = avgPopulation()/this->lambda;
    return aTI;
}

double Statistics::trueAvgTimeIn(){
    float time = (this->totalWaitTime/this->accumServiceTime) + this->accumServiceTime;
    return time/this->n;
}

double Statistics::avgNumInQ(){
    double aNIQ = avgPopulation() - (this->lambda/this->mu);
    return aNIQ;
}

double Statistics::trueAvgNumInQ(){
    return trueAvgTimeIn() * (this->customerWait / this->n);
}

double Statistics::avgTimeWaiting(){
    double aTW = avgNumInQ()/this->lambda;
    return aTW;
}

double Statistics::trueAvgTimeWaiting(){
    double wc = this->totalWaitTime / (double)this->n;
    double qc = (double)this->customerWait/(double)this->n;
    return (wc * qc) / this->totalTime;
}

double Statistics::RHO(){
    double rho = this->lambda/(this->M*this->mu);
    return rho;
}

double Statistics::trueRHO(){
    return this->accumServiceTime/(this->M*this->totalTime);
}

void Statistics::Display(){
    cout << endl;
    cout.setf(ios::fixed); cout.setf(ios::showpoint);
    cout.setf(ios::right);
    //Analytical Measures for checking equations
    /*cout << endl;
    cout << setw(10) << "Cust. Q - " << setw(15) << this->customerWait << "\n";
    cout << setw(10)<< "TOTAL - " << setw(15) <<  this->totalTime<< "\n";
    cout << setw(10)<< "wait - " << setw(15) <<  this->totalWaitTime<< "\n";
    cout << setw(10)<< "service - " << setw(15) <<  this->accumServiceTime << "\n";
    cout << setw(10)<< "idle - " << setw(15) <<  this->totalIdleTime << "\n\n";*/
    cout << setfill('=') << setw(23) <<  "---";
    cout.setf(ios::left);
    cout << " STATISTICS ---";
    cout.setf(ios::right);
    cout << setw(23) << "\n"; cout << setfill(' ');
    cout << "||  " << setw(56) << "||"<< endl;
    cout << "||  " << setw(20) << " " << setw(12) << "Modeled" <<"\t"<< setw(12) << "Simulated" << setw(8) << "||" << endl;
    cout << "||  " << setw(20) << "Percent Idle :: " << setw(12) << percentIdle() << "\t" << setw(12) << truePercentIdle() << setw(8) << "||" << endl;
     cout << "||  " << setw(20) << "Avg Population :: " << setw(12) << avgPopulation() << "\t" << setw(12) << "-.------" << setw(8) << "||" << endl;
    cout << "||  " << setw(20) << "Avg Time In Sys :: " << setw(12) << avgTimeIn() << "\t" << setw(12) << trueAvgTimeIn() << setw(8) << "||" << endl;
     cout << "||  " << setw(20) << "Avg Num In Queue :: " << setw(12) << avgNumInQ() << "\t" << setw(12) << "-.------" << setw(8) << "||" << endl;
    cout << "||  " << setw(20) << "Avg Time Waiting :: " << setw(12) << avgTimeWaiting() << "\t"<< setw(12) << trueAvgTimeWaiting() << setw(8) << "||" << endl;
    cout << "||  " << setw(20) << "Util. Factor :: " << setw(12) << RHO() << "\t" << setw(12) << trueRHO() << setw(8) << "||" << endl;
    cout << "||  " << setw(56) << "||"<< endl;
    cout << "||  " << setw(16) << " " << setw(20) << "Prob. of Wait: " << setw(12) << (double)this->customerWait/(double)this->n << setw(8) << "||" << endl;
    cout << "||  " << setw(56) << "||"<< endl;
    cout << setfill('=') << setw(60) << "=" << endl << endl; 
}
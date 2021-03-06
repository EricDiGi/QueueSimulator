/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testSim.cpp
  Assignment number: Project 2

 Test Simulation Functions and operation
***************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"
#include "sim.hpp"

using namespace std;

int main(){
    int n, M;
    float mu, lambda;
    cout << "\nNumber of Customers 1000-5000: ";
    cin >> n;
    while(n < 1000 || n > 5000)
        cin >> n;
    cout << "Average arrivals per time: ";
    cin >> lambda;
    cout << "Average number served per time: ";
    cin >> mu;
    cout << "Number of servers: ";
    cin >> M;
    while(M < 1 || M > 10){
        cin >> M;
    }

    Simulation S = Simulation(n, lambda, mu , M);
    S.main_();
}
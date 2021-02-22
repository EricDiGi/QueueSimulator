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
    cout << "Number of Customers 1000-5000: ";
    cin >> n;
    cout << "Average arrivals per time: ";
    cin >> lambda;
    cout << "Average number served per time: ";
    cin >> mu;
    cout << "Number of servers: ";
    cin >> M;

    Simulation S = Simulation(n, lambda, mu , M);
    S.main_();
}
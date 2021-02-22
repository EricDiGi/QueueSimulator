#ifndef sim_HPP
#define sim_HPP

#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"

class Simulation{
    private:
        int M, n;
        float mu, lambda;
        
        float massTime;
        int numCust;
        Heap PQ;
        FIFO FQ;
        
        int servers;

        float currentDepartTime;
    public:
        Simulation();
        Simulation(int n, float l, float m, int M);
        float nextRand(float avg);
        bool moreArrivals();
        void putPQ(int v);
        void processNextEvent();
        void main_();
};

#endif
/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: sim.hpp
  Assignment number: Project 2

 Define Simulation parameters and processes
***************************************************************/

#ifndef sim_HPP
#define sim_HPP

#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"
#include "statistics.hpp"

class Simulation{
    private:
        int M, n;
        float mu, lambda;
        
        float massTime;
        float totalTime = 0;
        int numCust;
        Heap PQ;
        FIFO FQ;
        Statistics stats;
        
        int servers;

        double currentDepartTime;
        double totalWait;
        double serviceTime;
        double idleTime;
    public:
        Simulation();
        Simulation(int n, float l, float m, int M);
        double nextRand(float avg);
        bool moreArrivals();
        void putPQ(int v);
        void processNextEvent();
        void processStats(Customer c);
        void main_();
};

#endif
/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: statistics.hpp
  Assignment number: Project 2

 Define Statistical equations
***************************************************************/

#ifndef statistics_HPP
#define statistics_HPP
//#include "PriorityQ.hpp"

class Statistics{
    private:
        int n = 0; 
        float lambda = 1.0; 
        float mu = 1.0;
        int M = 1;

        int customerWait = 0;
        float totalWaitTime = 0;
        float accumServiceTime = 0;
        float totalIdleTime = 0;
        float totalTime = 0;

        int factorial(int i);
        double sum(int M, double l, double mu);
    public:
        void setInitialState(int n, float l, float m, int M);

        void incrementCustomerWait();
        void totalWait(float v);
        void serviceTime(float v);
        void idleTime(float v);
        void allTime(float v);
        //1
        double percentIdle();
        double truePercentIdle();
        //2
        double avgPopulation();
        double trueAvgPopulation();
        //3
        double avgTimeIn();
        double trueAvgTimeIn();
        //4
        double avgNumInQ();
        double trueAvgNumInQ();
        //5
        double avgTimeWaiting();
        double trueAvgTimeWaiting();
        //6
        double RHO();
        double trueRHO();

        void Display();
};

#endif
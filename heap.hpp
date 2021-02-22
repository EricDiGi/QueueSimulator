#ifndef heap_HPP
#define heap_HPP

#include <iostream>
#include "customer.hpp"
#include <vector>
class Heap{
    private:
        std::vector<Customer> summit;
        int SIZE;
        bool doSwap(int P, int c);
    public:
        Heap();
        ~Heap();

        void push(Customer c);
        Customer pull();
        Customer top();
        void heap();
        void percolate(int i);
        int size();
        bool empty();


        friend std::ostream &operator<< (std::ostream &out, const Heap &h){
            out << "HEAP:: ";
            for(int i = 0; i < h.SIZE+1; i++){
                Customer c = h.summit.at(i);
                if(c.getArrival() > c.getDeparture()){
                    out << "+" << c.getArrival() << " ";
                }
                else{
                    out << "-" << c.getArrival() << " ";
                }
            }
            out << std::endl;
            return out;
        }
};

#endif
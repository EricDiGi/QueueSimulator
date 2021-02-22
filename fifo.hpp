#ifndef fifo_HPP
#define fifo_HPP

#include <iostream>
#include <queue>
#include "customer.hpp"
#include <vector>

class FIFO{
    private:
        std::vector<Customer> line;
        int SIZE;
    
    public:
        //FIFO();
        //~FIFO();

        void push(Customer c);
        Customer pull();

        int size();
        bool empty();

        friend std::ostream &operator<< (std::ostream &out, const FIFO &f){
            out << "FIFO:: ";
            for(int i = 0; i < (int)f.line.size(); i++){
                Customer c = f.line.at(i);
                if(c.getArrival() > c.getDeparture())
                    out << "+" << c.getArrival() << " ";
                else
                    out << "-" << c.getArrival() << " ";
            }
            out << std::endl;
            return out;
        }
};

#endif
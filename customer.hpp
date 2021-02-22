#ifndef customer_HPP
#define customer_HPP

#include <iostream>

class Customer{
    private:
        float arrivalTime;
        float startOfService;
        float departureTime;
        Customer* next;
    public:
        Customer();
        Customer(const Customer &c);
        Customer(float t);
        ~Customer();

        void setArrival(float t);
        float getArrival();

        void setSOS(float t);
        float getSOS();

        void setDeparture(float t);
        float getDeparture();

        float qTime();

        void setNext(Customer* n);
        Customer* getNext();

        friend std::ostream &operator<< (std::ostream &out, const Customer &c){
            out << c.arrivalTime << " - " << c.startOfService << " - " << c.departureTime << "\n";
            return out;
        }
};

#endif
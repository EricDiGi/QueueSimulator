#include <iostream>
#include "customer.hpp"
#include "heap.hpp"
#include "fifo.hpp"

using namespace std;

int main(){
    Heap h;
    FIFO F;
    Customer a, b, c, d, e, f;
    a.setArrival(1);
    b.setArrival(2);
    c.setArrival(3);
    d.setArrival(4);
    e.setArrival(5);
    f.setArrival(6);
    a.setDeparture(3.5);
    h.push(a);F.push(a);
    h.push(b);F.push(b);
    h.push(c);F.push(c);
    h.push(d);F.push(d);
    h.push(e);F.push(e);
    h.push(f);F.push(f);
    cout << F;
    cout << h;
    cout << h.pull();
    cout << h.pull();
    cout << h.pull();
    cout << h.pull();
    cout << h.pull();
    cout << h.pull();
    cout << h.pull();
    cout << h;

}
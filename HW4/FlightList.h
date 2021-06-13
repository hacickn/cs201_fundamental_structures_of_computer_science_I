/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_FLIGHTLIST_H
#define HW4_FLIGHTLIST_H
#include <string>
#include "Flight.h"
#include <iostream>
#include <cstddef>

using namespace std;
typedef Flight listItemType;

class FlightList {
public:
    FlightList();
    FlightList(const FlightList& secondList);
    ~FlightList();
    bool isEmpty() const;
    int getLength() const;



    bool insert(int index, Flight flight);

    bool remove(int index);

    int findById(const int id) const;


    Flight& getFlightByIndex(const int index) const;

private:
    struct ListNode{
        Flight  flight;
        ListNode* next;
    };

    int size;
    ListNode* head;

    ListNode* find(int index) const;
};


#endif //HW4_FLIGHTLIST_H

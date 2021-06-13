/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_CITYLIST_H
#define HW4_CITYLIST_H
#include <string>
#include "City.h"
#include <iostream>
#include <cstddef>
using namespace std;
typedef City listType;

class CityList {
public:
    CityList();
    CityList(const CityList& secondList);
    ~CityList();
    bool isEmpty() const;
    int getLength() const;

    bool insert(int index, City city);

    bool remove(int index);

    int findByName(const string name) const;

    City& getCityByIndex(const int index) const;

private:
    struct ListNode{
        City  city;
        ListNode* next;
    };

    int size;
    ListNode* head;

    ListNode* find(int index) const;
};


#endif //HW4_CITYLIST_H

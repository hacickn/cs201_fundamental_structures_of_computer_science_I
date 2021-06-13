/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_STACK_H
#define HW4_STACK_H

#include "City.h"

const int MAX_STACK = 15;
typedef City StackItemType;

class Stack {
public:
    Stack();
    bool isEmpty() const;
    bool push(City newCity);
    bool pop();
    bool pop(City& stackTop);
    City& getTopCity();

private:
    City items[MAX_STACK];
    int top;
};


#endif //HW4_STACK_H

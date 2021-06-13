/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */
#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() const {
    return top < 0;
}

bool Stack::push(City newCity) {
    if (top >= MAX_STACK - 1) {
        return false;
    } else {
        top++;
        items[top] = newCity;
        return true;
    }
}

bool Stack::pop() {

    if (isEmpty())
        return false;
    else {
        top--;
        return true;
    }

}

bool Stack::pop(City& stackTop) {

    if (isEmpty())
        return false;
    else {
        stackTop = items[top];
        top--;
        return true;
    }

}

City & Stack::getTopCity() {
    return items[top];
}
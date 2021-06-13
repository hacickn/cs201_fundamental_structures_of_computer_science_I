/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#include <sstream>
#include <iostream>
#include "Flight.h"

Flight::Flight() {

}

Flight::Flight( string newDeptCity,  string newDestCity,  string newCode,  string newCost) {
    deptCity = newDeptCity;
    destCity = newDestCity;
    stringstream codeTemp(newCode);
    codeTemp >> code;
    stringstream costTemp(newCost);
    costTemp >> cost;
}

string Flight::getDeptCity() const {
    return deptCity;
}

string Flight::getDestCity() const {
    return destCity;
}

int Flight::getCode() const {
    return code;
}

int Flight::getCost() const {
    return cost;
}

/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#include "City.h"
City::City() {
    name = "";
    isVisited = false;
}

City::City(const string name) {
    this->name = name;
    isVisited = false;
}

City::City(const City& second) {
    this->name = second.name;
    this->isVisited = second.isVisited;
}

string City::getName() const {
    return name;
}

bool City::getVisited() const {
    return isVisited;
}

void City::setName(string name) {
    this->name = name;
}

void City::setVisited(bool isVisit) {
    this->isVisited = isVisit;
}
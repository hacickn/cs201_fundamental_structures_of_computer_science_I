/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_FLIGHTMAP_H
#define HW4_FLIGHTMAP_H
#include <string>
#include "FlightList.h"
#include "CityList.h"
#include "Stack.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;
class FlightMap {
public:
    FlightMap(const string cityFile, const string flightFile);
    FlightMap();
    ~FlightMap();

    void displayAllCities() const;
    void displayAdjacentCities( const string cityName) const;
    void displayFlightMap() const;

    void findFlights( const string deptCity, const string destCity) const;
    void findLeastCostFlight(const string deptCity,const string destCity) const;
    void runFlightRequests(const string requestFile) const;
    void markVisited(string cityName) const;
    void unVisitAll() const;
    City& getNextCity(string fromCity) const;
    bool searchS(string originCity, string destinationCity, bool sayCheapOne) const;
    void checkAlreadyExist(string cityName, Stack secondStack) const;
    void makeOldConnectionsUnVisit(string cityName) const;
    int printRoute(Stack newStack) const;
    string to_string(const int num) const;
private:
    FlightList flightList;
    CityList cityList;
};


#endif //HW4_FLIGHTMAP_H

/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#include <fstream>
#include "FlightMap.h"
#include <string>
#include "FlightList.h"
#include "CityList.h"
#include "Stack.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

FlightMap::FlightMap() {

}

FlightMap::FlightMap(const string cityFile, const string flightFile) {
    string text ="";

    ifstream CityReader(cityFile.c_str());
    ifstream FlightReader(flightFile.c_str());

    while (getline(CityReader, text)) {
        cityList.insert(cityList.getLength() + 1, City(text));
    }
    CityReader.close();

    while (getline(FlightReader, text)) {
        string delimiter = ",";

        int temp = text.find(delimiter);
        string dept = text.substr(0, temp);
        text.erase(0, temp + 1);

        temp = text.find(delimiter);
        string dest = text.substr(0, temp);
        text.erase(0, temp + 1);

        temp = text.find(delimiter);
        string code = text.substr(0, temp);
        text.erase(0, temp + 1);

        temp = text.find(delimiter);
        string cost = text.substr(0, temp);
        text.erase(0, temp + 1);
        Flight flight(dept, dest, code, cost);
        flightList.insert(flightList.getLength() + 1, flight);

    }
    CityReader.close();
}

FlightMap::~FlightMap() {

}

void FlightMap::displayAllCities() const {
    for (int a = 1; a <= cityList.getLength(); a++) {
        cout << cityList.getCityByIndex(a).getName() << ", ";
    }
    cout << endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const {
    CityList tempList;
    for (int a = 1; a <= flightList.getLength(); a++) {
        Flight f = flightList.getFlightByIndex(a);
        if (f.getDeptCity() == cityName) {
            tempList.insert(tempList.getLength() + 1, City(f.getDestCity()));
        }
    }

    if (tempList.isEmpty()) {
        cout << cityName << " -> " << endl;
    } else {
        cout << cityName << " -> ";
        for (int i = tempList.getLength(); i >= 1; i--) {
            cout << tempList.getCityByIndex(i).getName() << ", ";
        }
        cout << endl;
    }
}

void FlightMap::displayFlightMap() const {
    for (int a = 1; a <= cityList.getLength(); a++) {
        displayAdjacentCities(cityList.getCityByIndex(a).getName());
    }
}

void FlightMap::findFlights(const string deptCity, const string destCity) const {
    searchS(deptCity, destCity, false);
}

void FlightMap::findLeastCostFlight(const string deptCity, const string destCity) const {
    searchS(deptCity, destCity, true);
}

void FlightMap::runFlightRequests(const string requestFile) const {
    CityList deptCities;
    CityList destCities;
    string text ="";
    ifstream RequestReader(requestFile.c_str());

    while (getline(RequestReader, text)) {
        string delimiter = ",";
        int temp = text.find(delimiter);
        string dept = text.substr(0, temp);
        text.erase(0, temp + 1);
        string dest = text.substr(0,text.find(" "));
        if (!dept.empty()){
            findLeastCostFlight(dept, dest);
            cout << endl;
        }
    }
    RequestReader.close();
}

void FlightMap::markVisited(string cityName) const {
    cityList.getCityByIndex(cityList.findByName(cityName)).setVisited(true);
}

void FlightMap::unVisitAll() const {
    for (int a = 1; a <= cityList.getLength(); a++) {
        cityList.getCityByIndex(a).setVisited(false);
    }
}


City& FlightMap::getNextCity(string fromCity) const {
    for (int a = 1; a <= flightList.getLength(); a++) {
        Flight f = flightList.getFlightByIndex(a);
        if (f.getDeptCity() == fromCity) {
            if (!cityList.getCityByIndex(cityList.findByName(f.getDestCity())).getVisited()) {
                return cityList.getCityByIndex(cityList.findByName(f.getDestCity()));
            }
        }
    }

    return cityList.getCityByIndex(cityList.findByName(fromCity));
}

bool FlightMap::searchS(string originCity, string destinationCity, bool sayCheapOne) const {
    cout << "Request is to fly from " << originCity << " to " << destinationCity << ":" << endl;
    Stack myStack;
    Stack cheap;
    int cheapOneValue = 0;
    unVisitAll();
    markVisited(originCity);
    myStack.push(cityList.getCityByIndex(cityList.findByName(originCity)));

    while (!myStack.isEmpty()) {
        City city = getNextCity(myStack.getTopCity().getName());
        if (city.getName() != myStack.getTopCity().getName()) {
            markVisited(cityList.getCityByIndex(
                    cityList.findByName(city.getName())).getName());
            myStack.push(cityList.getCityByIndex(
                    cityList.findByName(city.getName())));

        } else if (city.getName() == originCity) {
            City temp;
            myStack.pop(temp);
            makeOldConnectionsUnVisit(temp.getName());
        } else {
            City temp;
            myStack.pop(temp);
            checkAlreadyExist(temp.getName(), myStack);
        }

        if (myStack.getTopCity().getName() == destinationCity) {
            if (cheap.isEmpty()) {
                cheapOneValue = printRoute(myStack);
                cheap = myStack;
            } else {
                int tempValue = printRoute(myStack);
                if (tempValue < cheapOneValue) {
                    cheapOneValue = tempValue;
                    cheap = myStack;
                }
            }

            City temp;
            myStack.pop(temp);
        }


    }

    if (sayCheapOne && !cheap.isEmpty()) {
        cout << "A least cost path from " << originCity << " to " << destinationCity << " is ";
        string path = cheap.getTopCity().getName();
        cheap.pop();
        while (!cheap.isEmpty()) {
            path = cheap.getTopCity().getName() + " -> " + path;
            cheap.pop();
        }
        cout << path << " and its cost is " << cheapOneValue << " TL" << endl;
    } else if (cheap.isEmpty()) {
        cout << "Sorry. HPAir does not fly from " << originCity << " to " << destinationCity << endl;
    }
}

int FlightMap::printRoute(Stack newStack) const {
    Flight flight;
    City dest;
    City dept;
    int total = 0;
    string willBePrint = "";
    string temp ="";
    while (!newStack.isEmpty()) {
        dest = newStack.getTopCity();
        newStack.pop();
        if (newStack.isEmpty()) {
            cout << willBePrint;
            cout << "Total Cost ................... " << total << " TL" << endl << endl;
            return total;
        }
        dept = newStack.getTopCity();
        for (int a = 1; a <= flightList.getLength(); a++) {
            flight = flightList.getFlightByIndex(a);
            if (flight.getDestCity() == dest.getName() && flight.getDeptCity() == dept.getName()) {
                temp ="Flight #" + to_string(flight.getCode()) + " from " + dept.getName() + " to " + dest.getName();
                for(int k = 0; k < 40- temp.length(); k++){
                    temp = temp + " ";
                }
                willBePrint =temp+ "Cost: " + to_string(flight.getCost()) + " TL" + "\n" + willBePrint;
                total = total + flight.getCost();
            }
        }

    }
    return 0;
}

void FlightMap::checkAlreadyExist(string cityName, Stack secondStack) const {
    CityList tempList;
    for (int a = 1; a <= flightList.getLength(); a++) {
        Flight f = flightList.getFlightByIndex(a);
        if (f.getDeptCity() == cityName) {
            if (cityList.getCityByIndex(cityList.findByName(f.getDestCity())).getVisited()) {
                tempList.insert(tempList.getLength() + 1,
                                cityList.getCityByIndex(cityList.findByName(f.getDestCity())));
            }
        }
    }
    makeOldConnectionsUnVisit(cityName);
    //cout << tempList.getLength() << "           ******* "<< endl;

    Stack tempStack = secondStack;
    for (int a = 1; a <= tempList.getLength(); a++) {
        while (!tempStack.isEmpty()) {
            if (tempStack.getTopCity().getName() == tempList.getCityByIndex(a).getName()) {
                markVisited(tempList.getCityByIndex(a).getName());

            }
            tempStack.pop();
        }

    }

}

void FlightMap::makeOldConnectionsUnVisit(string cityName) const {
    for (int i = 1; i <= flightList.getLength(); ++i) {
        if (flightList.getFlightByIndex(i).getDeptCity() == cityName) {
            cityList.getCityByIndex(cityList.findByName(flightList.getFlightByIndex(i).getDestCity())).setVisited(
                    false);
        }

    }

}

string FlightMap::to_string(const int num) const {
    stringstream stream;
    stream << num;
    return stream.str();
}
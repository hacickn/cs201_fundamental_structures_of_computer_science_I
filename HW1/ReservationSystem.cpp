//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//

#include "ReservationSystem.h"
#include <string>
#include <iostream>
using namespace std;
ReservationSystem::ReservationSystem() {
    numberOfReservations = 0;
    numberOfFlights = 0;
    allFlights = NULL; // nullptr also can be used
    allReservations = NULL;
}

ReservationSystem::~ReservationSystem() {
    if (numberOfReservations > 0) {
        delete[] allReservations;
    }
    if (numberOfFlights > 0) {
        delete[] allFlights;
    }
}

void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {
    if (rowNo > 0 && seatNo > 0 && flightNo > 0) {
        // if there is no flight before adding
        if (numberOfFlights == 0) {
            numberOfFlights++;
            allFlights = new Flight[numberOfFlights];
            allFlights[0] = Flight(flightNo, rowNo, seatNo);
            cout << "Flight " << flightNo << " has been added" << endl;
        }// if there is/are flights before adding
        else {
            bool check = true;
            for (int a = 0; a < numberOfFlights; a++) {
                if (allFlights[a].getFlightCode() == flightNo)
                    check = false;
            }
            // if there is no flight with this code
            if (check) {
                numberOfFlights++;
                Flight* tempList = allFlights;
                allFlights = new Flight[numberOfFlights];
                for (int b = 0; b < numberOfFlights - 1; b++) {
                    allFlights[b] = tempList[b];
                }
                allFlights[numberOfFlights - 1] = Flight(flightNo, rowNo, seatNo);
                cout << "Flight " << flightNo << " has been added" << endl;
                delete[] tempList;
            }// if this flight code already had been taken
            else {
                // warning about the same flight code
                cout << "Flight " << flightNo << " already exists" << endl;
            }
        }
    } else {
        // warming about the positive values
        cout << "Flight no, row no and seat have to be POSITIVE" << endl;
    }
    cout << endl;
}

void ReservationSystem::cancelFlight(const int flightNo) {
    //check whether there is flight with this code
    int trace = -1;
    for (int a = 0; a < numberOfFlights; a++) {
        if (allFlights[a].getFlightCode() == flightNo)
            trace = a;
    }

    //if it does not exist with this code
    if (trace < 0) {
        cout << "Flight " << flightNo << " does not exist" << endl;
    }// if there is flight with this code
    else {
        // delete all reservation related to this flight
        for (int m = 0; m < numberOfReservations; m++) {
            if (allReservations[m].getFlightCode() == flightNo) {
                cancelReservationDueToFlight(allReservations[m].getReservationCode());
                m--;
            }
        }

        // if there is last one flight which has this code simply delete flight array
        if (numberOfFlights == 1) {
            delete[] allFlights;
        } // it there are more than 1 flight we should recreate list
        else {
            Flight* temp = allFlights;
            allFlights = new Flight[numberOfFlights - 1];
            for (int k = 0; k < trace; k++) {
                allFlights[k] = temp[k];
            }
            for (int k = trace + 1; k < numberOfFlights; k++) {
                allFlights[k - 1] = temp[k];
            }
            delete[] temp;
        }
        numberOfFlights--;
        cout << "Flight " << flightNo << " and all of its reservations are canceled" << endl;
    }
    cout << endl;
}

void ReservationSystem::showFlight(const int flightNo) {
    for (int a = 0; a < numberOfFlights; a++) {
        if (allFlights[a].getFlightCode() == flightNo) {
            allFlights[a].showSeatInfo();
            return;
        }
    }
    // if method could not reach return statement, this means that there is no flight with this code
    cout << "Flight " << flightNo << " does not exist" << endl;
    cout << endl;
}

void ReservationSystem::showAllFlights() {
    if (numberOfFlights == 0) {
        cout << "No flights exist" << endl;
    } else {
        cout << "Flights currently operated:" << endl;
        for (int a = 0; a < numberOfFlights; a++) {
            cout << "Flight " << allFlights[a].getFlightCode() << " (" << allFlights[a].getNumberOfAvailableSeat()
                 << " available seats)" << endl;
        }
    }
    cout << endl;
}

int ReservationSystem::makeReservation(const int flightNo, const int numPassengers, const int* seatRow,
                                       const char* seatCol) {
    // check whether there is flight with this code
    int trace = -1;
    for (int a = 0; a < numberOfFlights; a++) {
        if (allFlights[a].getFlightCode() == flightNo)
            trace = a;
    }

    // if there is no flight with this code
    if (trace == -1) {
        cout << "There is no flight with code " << flightNo << endl;
        return -1;
    }//there is flight with this code
    else {
        /*
         * check whether seats are available if it is not, show unavailable seats( check availability method do this).
         * if they are available, make seats unavailable( check availability method also do this) and create a reservation
         * object( inside of if do this). All printing staff are making in checkAvailability method
         */
        if (allFlights[trace].checkAvailability(numPassengers, seatRow, seatCol)) {
            // if there is no reservation before adding this one
            numberOfReservations++;
            if (numberOfReservations == 1) {
                allReservations = new Reservation[numberOfReservations];
                allReservations[0] = Reservation(1, flightNo, numPassengers, seatRow, seatCol);
            }// if there is / are reservations before adding this one
            else {
                Reservation* temp = allReservations;
                allReservations = new Reservation[numberOfReservations];
                for (int i = 0; i < numberOfReservations - 1; i++) {
                    allReservations[i] = temp[i];
                }
                allReservations[numberOfReservations - 1] = Reservation(
                        allReservations[numberOfReservations - 2].getReservationCode() + 1, flightNo, numPassengers,
                        seatRow, seatCol);
                delete[] temp;
            }
            return allReservations[numberOfReservations - 1].getReservationCode();
        } else
            return -1;
    }
}

void ReservationSystem::cancelReservation(const int resCode) {
    // check whether there is reservation with this code or not
    int trace = -1;
    for (int a = 0; a < numberOfReservations; a++) {
        if (allReservations[a].getReservationCode() == resCode)
            trace = a;
    }

    // if not exist
    if (trace == -1) {
        cout << "No reservations are found under code " << resCode << endl;
    }// if exist
    else {
        // find the place of flight
        int traceForFlight = 0;
        for (int i = 0; i < numberOfFlights; i++) {
            if (allFlights[i].getFlightCode() == allReservations[trace].getFlightCode())
                traceForFlight = i;
        }

        // making seat available
        allFlights[traceForFlight].seatSeatsAvailable(allReservations[trace].getSeatList(),
                                                      allReservations[trace].getNumOfPassengers());
        // if it is last reservation
        if (numberOfReservations == 1) {
            cout << "Reservation for the seats ";
            for (int l = 0; l < allReservations[trace].getNumOfPassengers(); l++) {
                cout << allReservations[trace].getSeatList()[l] << " ";
            }
            cout << "is canceled in Flight " << allReservations[trace].getFlightCode() << endl;
            delete[] allReservations;
        }// if it is not last reservation
        else {
            Reservation* temp = allReservations;
            allReservations = new Reservation[numberOfReservations - 1];
            for (int m = 0; m < trace; m++) {
                allReservations[m] = temp[m];
            }
            for (int m = trace + 1; m < numberOfReservations; m++) {
                allReservations[m - 1] = temp[m];
            }
            cout << "Reservation for the seats ";
            for (int l = 0; l < temp[trace].getNumOfPassengers(); l++) {
                cout << temp[trace].getSeatList()[l] << " ";
            }
            cout << "is canceled in Flight " << temp[trace].getFlightCode() << endl;

            delete[] temp;
        }
        numberOfReservations--;
    }
}

//it is for canceling reservation due to canceling flight. In flight canceling there is no seat is printed in the example output
void ReservationSystem::cancelReservationDueToFlight(const int resCode) {
    int trace = -1;
    for (int a = 0; a < numberOfReservations; a++) {
        if (allReservations[a].getReservationCode() == resCode)
            trace = a;
    }

    // if not exist
    if (trace == -1) {
        cout << "No reservations are found under code " << resCode << endl;
    }// if exist
    else {
        // find the place of flight
        int traceForFlight = 0;
        for (int i = 0; i < numberOfFlights; i++) {
            if (allFlights[i].getFlightCode() == allReservations[trace].getFlightCode())
                traceForFlight = i;
        }

        // making seat available
        allFlights[traceForFlight].seatSeatsAvailable(allReservations[trace].getSeatList(),
                                                      allReservations[trace].getNumOfPassengers());
        // if it is last reservation
        if (numberOfReservations == 1) {
            delete[] allReservations;
        }// if it is not last reservation
        else {
            Reservation* temp = allReservations;
            allReservations = new Reservation[numberOfReservations - 1];
            for (int m = 0; m < trace; m++) {
                allReservations[m] = temp[m];
            }
            for (int m = trace + 1; m < numberOfReservations; m++) {
                allReservations[m - 1] = temp[m];
            }

            delete[] temp;
        }
        numberOfReservations--;
    }
}

void ReservationSystem::showReservation(const int resCode) {
    int trace = -1;
    for (int a = 0; a < numberOfReservations; a++) {
        if (allReservations[a].getReservationCode() == resCode)
            trace = a;
    }

    if (trace == -1) {
        cout << "No reservations under Code " << resCode << endl;
    } else {
        allReservations[trace].showReservation();
    }
}
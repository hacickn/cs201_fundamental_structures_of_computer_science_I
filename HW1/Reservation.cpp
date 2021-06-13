//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//

#include "Reservation.h"
#include <string>
#include <exception>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

Reservation::Reservation() {
    reservationCode = -1;
    numOfPassengers = 0;
    flightCode = -1;
    listOfSeats = NULL;
}

Reservation::Reservation(const int reservationCode, const int flightCode, const int numOfPassengers, const int* seatRow,
                         const char* seatCol) {
    this->reservationCode = reservationCode;
    this->flightCode = flightCode;
    this->numOfPassengers = numOfPassengers;


    if (numOfPassengers > 0) {
        listOfSeats = new string[numOfPassengers];
        //this for adding while sorting
        listOfSeats[0] = to_string(seatRow[0]) + seatCol[0];
        for (int a = 1; a < numOfPassengers; a++) {
            int aimedPlace = 0;
            if (((((seatRow[a] - 1) * 10) + (static_cast<int>(seatCol[a]) - 65)) <
                                          ((int(listOfSeats[0][0]) )- 49) * 10 + int(listOfSeats[0][1]) - 65)) {
                aimedPlace = 0;
            } else if (((((seatRow[a] - 1) * 10) + (static_cast<int>(seatCol[a]) - 65)) >
                                                 ((int(listOfSeats[a - 1][0]) )- 49) * 10 + int(listOfSeats[a - 1][1]) -
                                                  65)) {
                aimedPlace = a;
            } else {
                for (int b = 0; b < a - 1; b++) {
                    if (((((seatRow[a] - 1) * 10) + (static_cast<int>(seatCol[a]) - 65)) >
                    (int((listOfSeats[b][0]) - 49) * 10 + int(listOfSeats[b][1]) - 65))
                        && ((((seatRow[a] - 1) * 10) + (static_cast<int>(seatCol[a]) - 65)) <
                        (int((listOfSeats[b + 1][0]) - 49) * 10 +int(listOfSeats[b + 1][1]) - 65))) {
                        aimedPlace = b + 1;
                    }
                }
            }
            for(int i = a; i > aimedPlace ; i--){
                listOfSeats[i] = listOfSeats[i-1];
            }
            listOfSeats[aimedPlace] = to_string(seatRow[a]) + seatCol[a];

        }
    } else {
        listOfSeats = NULL;
    }

}

Reservation::~Reservation() {
    if (numOfPassengers > 0)
        delete[] listOfSeats;
}

void Reservation::showReservation() const {
//Reservations under Code 1 in Flight 104: 1B 1C 3A 3B
    cout << "Reservations under Code " << reservationCode << " in Flight " << flightCode << ":";
    for (int a = 0; a < numOfPassengers; a++) {
        cout << " " << listOfSeats[a];
    }
    cout << endl;
}

Reservation& Reservation::operator=(const Reservation& reservation) {
    reservationCode = reservation.reservationCode;
    flightCode = reservation.flightCode;
    if (numOfPassengers == reservation.numOfPassengers) {
        if (numOfPassengers > 0) {
            for (int a = 0; a < numOfPassengers; a++) {
                listOfSeats[a] = reservation.listOfSeats[a];
            }
        } else {
            listOfSeats = NULL;
        }
    } else {
        if (numOfPassengers > 0)
            delete[] listOfSeats;
        numOfPassengers = reservation.numOfPassengers;
        if (numOfPassengers == 0) {
            listOfSeats = NULL;
        } else {
            listOfSeats = new string[numOfPassengers];
            for (int a = 0; a < numOfPassengers; a++) {
                listOfSeats[a] = reservation.listOfSeats[a];
            }
        }
    }
    return *this;
}

string& Reservation::operator[](const int num) {
    if (num >= 0 && num < numOfPassengers) {
        return listOfSeats[num];
    } else {
        throw out_of_range("invalid index");
    }
}

int Reservation::getFlightCode() const {
    return flightCode;
}

int Reservation::getNumOfPassengers() const {
    return numOfPassengers;
}

int Reservation::getReservationCode() const {
    return reservationCode;
}

string* Reservation::getSeatList() const {
    return listOfSeats;
}

string Reservation::to_string(const int num){
    std::stringstream stream;
    stream << num;
    return stream.str();
}
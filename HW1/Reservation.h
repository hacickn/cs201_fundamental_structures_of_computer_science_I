//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//

#ifndef HW1_C201_RESERVATION_H
#define HW1_C201_RESERVATION_H
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Reservation {
private:
    int reservationCode;
    int numOfPassengers;
    int flightCode;
    string* listOfSeats;
public:
    Reservation();

    Reservation(const int reservationCode, const int flightCode, const int numOfPassengers, const int* seatRow,
                const char* seatCol);

    ~Reservation();

    Reservation& operator=(const Reservation& reservation);

    string& operator[](const int num);

    void showReservation() const;
    int getReservationCode() const;

    int getNumOfPassengers() const;
    string to_string(const int num);
    int getFlightCode() const;

    string* getSeatList() const;

};


#endif //HW1_C201_RESERVATION_H

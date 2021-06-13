//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//
#include "Flight.h"
#include "Reservation.h"
#ifndef HW1_C201_RESERVATIONSYSTEM_H
#define HW1_C201_RESERVATIONSYSTEM_H
#include <string>
#include <iostream>
using namespace std;

class ReservationSystem {
private:
    int numberOfFlights;
    int numberOfReservations;
    Flight* allFlights;
    Reservation* allReservations;

public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight(const int flightNo, const int rowNo, const int seatNo);
    void cancelFlight(const int flightNo);
    void showAllFlights();
    void showFlight(const int flightNo);
    void cancelReservationDueToFlight(const int resCode);



    int makeReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol);
    void cancelReservation(const int resCode);
    void showReservation(const int resCode);

};

#endif //HW1_C201_RESERVATIONSYSTEM_H

//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//
#ifndef HW1_C201_FLIGHT_H
#define HW1_C201_FLIGHT_H
#include <sstream>
#include <string>
#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;


class Flight {

private:
    int flightCode;
    int numberOfRow;
    int numberOfColumn;
    int numberOfAvailableSeat;

    bool* seatList;


public:
    const static string letter;

    Flight(const int flightNo = -1, const int row = 0, const int column = 0);

    Flight(const Flight& copy);

    ~Flight();

    Flight& operator=(const Flight& right);

    bool& operator[](const int num);

    void seatSeatsAvailable(string* listOfString, const int numOfPassenger);

    int getFlightCode() const;

    int getNumberOfRow() const;

    int getNumberOfColumn() const;

    int getNumberOfAvailableSeat() const;

    bool checkAvailability(const int numberOfPassengers, const int* seatRow, const char* seatColumn);

    void setSeatsReserved(const int numberOfPassengers, const int* seatRow, const char* seatColumn);
    string to_string(const int num);
    void showSeatInfo() const;
};


#endif //HW1_C201_FLIGHT_H

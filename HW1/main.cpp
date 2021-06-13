//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//
#include "ReservationSystem.h"

#include <string>
#include <iostream>
using namespace std;

int main() {
    ReservationSystem R;
    R.showAllFlights();

    R.addFlight(104, 4, 3);
    R.addFlight(234, 8, 3);
    R.addFlight(76, 6, 2);
    R.addFlight(12, 10, 10);
    R.showAllFlights();

    R.addFlight(104, 8, 6);

    R.showAllFlights();

    R.showFlight(104);
    int rowRes1[4] = {3, 3, 1, 1};
    char colRes1[4] = {'A', 'B', 'B', 'C'};
    int code1 = R.makeReservation(104, 4, rowRes1, colRes1);
    if (code1 != -1)
        cout << "Your reservation code is " << code1 << endl;

    R.showFlight(12);
    int rowRes5[7] = {3, 3, 1, 1,2,2,3};
    char colRes5[7] = {'A', 'B', 'B', 'C','B', 'C','D'};
    int code5 = R.makeReservation(12, 7, rowRes5, colRes5);
    if (code5 != -1)
        cout << "Your reservation code is " << code5 << endl;
    R.showFlight(12);

    R.showFlight(104);
    int rowRes2[2] = {2, 4};
    char colRes2[2] = {'A', 'C'};
    int code2 = R.makeReservation(104, 2, rowRes2, colRes2);
    if (code2 != -1)
        cout << "Your reservation code is " << code2 << endl;
    R.showFlight(104);
    int rowRes3[2] = {2, 3};
    char colRes3[2] = {'B', 'A'};
    int code3 = R.makeReservation(104, 2, rowRes3, colRes3);
    if (code3 != -1)
        cout << "Your reservation code is " << code3 << endl;
    R.showFlight(104);
    int rowRes4[7] = {1, 2, 2, 3, 2, 3, 1};
    char colRes4[7] = {'A', 'B', 'C', 'C', 'A', 'B', 'B'};
    int code4 = R.makeReservation(104, 7, rowRes4, colRes4);
    if (code4 != -1)
        cout << "Your reservation code is " << code4 << endl;

    R.showFlight(104);
    R.showAllFlights();

    R.showReservation(100);

    R.showReservation(code1);

    R.cancelReservation(300);
    R.cancelReservation(code1);
    R.cancelReservation(code2);
    R.cancelReservation(code3);
    R.cancelReservation(code4);
    R.cancelReservation(code5);
    int code6 = R.makeReservation(104, 7, rowRes4, colRes4);
    if (code6 != -1)
        cout << "Your reservation code is " << code6 << endl;
    R.cancelReservation(code6);
    R.showFlight(104);
    R.showAllFlights();
    /*
    R.cancelFlight(234);
    R.showFlight(234);
    R.showAllFlights();
    R.cancelFlight(674);
    R.showAllFlights();
    cout << "---------------"<<endl;
    R.cancelFlight(104);
    cout << "---------------"<<endl;
    cout << code5 << endl;
    R.cancelReservation(code5);
    R.showReservation(code1);
    R.cancelFlight(76);
    R.showFlight(12);
    R.cancelFlight(12);
    R.showAllFlights();
    R.addFlight(104, 4, 3);
    R.showFlight(104);
    int rowRes6[7] = {3, 3, 1, 1,2,2,3};
    char colRes6[7] = {'A', 'B', 'B', 'C','B', 'C','c'};
    int code6 = R.makeReservation(104, 7, rowRes6, colRes6);
    if (code6 != -1)
        cout << "Your reservation code is " << code6 << endl;
    R.showFlight(104);
     */
}

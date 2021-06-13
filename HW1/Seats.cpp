//
// Created by Aslı Dinç on 6.11.2020.
//

#include "Seats.h"
#include <iostream>
using namespace std;
#include <string>

const char LETTERS[] = {'A','B','C','D','E','F'};

//Constructor
Seats::Seats(const int rows, const int columns) {
    rowNumber = rows;
    columnNumber = columns;
    freeSeatNumber = 0;
    arrForSeats = new bool* [rowNumber];

    for ( int i = 0; i < rowNumber; i++ )
        arrForSeats[i] = new bool [columnNumber];
}
//Deconstructor
Seats::~Seats(){
    for ( int k = 0; k < rowNumber; k++ )
        delete [] arrForSeats[k];

    delete [] arrForSeats;
}

//returns the total number of seats in the flight
int  Seats:: getSeatNum(){
    return rowNumber*columnNumber;
}

//shows the availability of the seats in the flight
void Seats::showSeats() {
freeSeatNumber = rowNumber*columnNumber;

    std::cout << std::endl;

    for (int i = 0; i < rowNumber; ++i)
    {
        cout << i+1 << ' ';
        for (int j = 0; j < columnNumber; ++j)
        {
            if (arrForSeats[i][j] == 0)
                cout << "O" << ' ';
            else {
                cout << "X" << ' ';
                freeSeatNumber--;
            }
        }
        std::cout << std::endl;
    }

}

//returns the free seat number in the flight
int Seats::availableSeatNum() {
 freeSeatNumber = 0;
    for (int i = 0; i < rowNumber; ++i)
    {
        for (int j = 0; j < columnNumber; ++j)
        {
            if (arrForSeats[i][j] == 0)
                freeSeatNumber++;
        }
    }
    return freeSeatNumber;
}

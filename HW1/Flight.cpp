//
// Created by Hacı Çakın on 08.11.2020.
// 21802641
//
#include <iostream>
#include <stdexcept>
#include "Flight.h"
#include <string>

using namespace std;

const string Flight::letter = "ABCDEFGHIJKLMNOPRSTUVYXWS";

Flight::Flight(const int flightNo, const int row, const int column) {
    flightCode = flightNo;
    numberOfRow = row;
    numberOfColumn = column;
    numberOfAvailableSeat = numberOfColumn * numberOfRow;
    if (flightCode == -1 || numberOfAvailableSeat == 0) {
        seatList = NULL;
    } else {
        seatList = new bool[numberOfAvailableSeat];
        for (int a = 0; a < numberOfAvailableSeat; a++) {
            seatList[a] = 1;
        }
    }
}

Flight::Flight(const Flight& copy) {
    flightCode = copy.flightCode;
    numberOfRow = copy.numberOfRow;
    numberOfColumn = copy.numberOfColumn;
    numberOfAvailableSeat = copy.numberOfAvailableSeat;
    if (numberOfColumn * numberOfRow > 0) {
        seatList = new bool[numberOfColumn * numberOfRow];
        for (int a = 0; a < numberOfRow * numberOfColumn; a++) {
            seatList[a] = copy.seatList[a];
        }
    } else {
        seatList = NULL;
    }
}

Flight& Flight::operator=(const Flight& right) {
    if (&right != this) {
        flightCode = right.flightCode;
        numberOfAvailableSeat = right.numberOfAvailableSeat;
        //if their seatList size are equal
        if (numberOfColumn * numberOfColumn == right.numberOfColumn * right.numberOfRow) {
            numberOfRow = right.numberOfRow;
            numberOfColumn = right.numberOfColumn;
            // if their seatList size equal to 0
            if (numberOfRow * numberOfColumn == 0) {
                seatList = NULL;
            }// if their seatList size bigger than 0
            else {
                for (int a = 0; a < numberOfColumn * numberOfRow; a++) {
                    seatList[a] = right.seatList[a];
                }
            }
        }//if their seatList size are NOT equal
        else {
            // if left flight's seatList size is equal to 0
            if (numberOfRow * numberOfColumn == 0) {
                numberOfRow = right.numberOfRow;
                numberOfColumn = right.numberOfColumn;
                seatList = new bool[numberOfColumn * numberOfRow];
                for (int a = 0; a < numberOfColumn * numberOfRow; a++) {
                    seatList[a] = right.seatList[a];
                }
            }// if left flight's seatList size is bigger than 0
            else {
                delete[] seatList;
                numberOfRow = right.numberOfRow;
                numberOfColumn = right.numberOfColumn;
                if (numberOfRow * numberOfColumn == 0)
                    seatList = NULL;
                else {
                    seatList = new bool[numberOfColumn * numberOfRow];
                    for (int a = 0; a < numberOfColumn * numberOfRow; a++) {
                        seatList[a] = right.seatList[a];
                    }
                }

            }
        }
    }

    return *this;
}

Flight::~Flight() {
    if (numberOfColumn * numberOfRow > 0)
        delete[] seatList;
}

bool& Flight::operator[](const int num) {
    if (num >= 0 && num < numberOfRow * numberOfColumn)
        return seatList[num];
    else
        throw out_of_range("invalid index");
}

int Flight::getFlightCode() const {
    return flightCode;
}

int Flight::getNumberOfRow() const {
    return numberOfRow;
}

int Flight::getNumberOfColumn() const {
    return numberOfColumn;
}

int Flight::getNumberOfAvailableSeat() const {
    return numberOfAvailableSeat;
}

bool Flight::checkAvailability(const int numberOfPassengers, const int* seatRow, const char* seatColumn) {
    int tempNo = 0;
    string* tempList;
    for (int a = 0; a < numberOfPassengers; a++) {
        if (!(seatList[(seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65)])) {
            if (tempNo == 0) {
                tempList = new string[1];
                tempList[0] = (to_string(seatRow[a])) + seatColumn[a];
                tempNo++;
            } else {
                // this part adding unavailable seat by sorting them
                // first find a place where we should add
                int aimedPlace = 0;
                if ((seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65) <
                    (int((tempList[0][0]) - 49) * numberOfColumn + int(tempList[0][1]) - 65)) {
                    aimedPlace = 0;
                } else if ((seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65) >
                           (int((tempList[tempNo - 1][0]) - 49) * numberOfColumn + int(tempList[tempNo - 1][1]) -
                            65)) {
                    aimedPlace = tempNo;
                } else {
                    for (int i = 0; i < tempNo - 1; i++) {
                        if ((seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65) >
                            (int((tempList[i][0]) - 49) * numberOfColumn + int(tempList[i][1]) - 65) &&
                            (seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65) <
                            (int((tempList[i + 1][0]) - 49) * numberOfColumn + int(tempList[i + 1][1]) - 65))
                            aimedPlace = i + 1;
                    }
                }

                string* tempOfTemp = tempList;
                tempNo++;
                tempList = new string[tempNo];

                for (int i = 0; i < aimedPlace; i++) {
                    tempList[i] = tempOfTemp[i];
                }
                tempList[aimedPlace] = to_string(seatRow[a]) + seatColumn[a];
                for (int i = aimedPlace + 1; i < tempNo; i++) {
                    tempList[i] = tempOfTemp[i - 1];
                }
                delete[] tempOfTemp;

            }
        }
    }

    if (tempNo == 0) {
        setSeatsReserved(numberOfPassengers, seatRow, seatColumn);
        return true;
    } else {
        for (int m = 0; m < tempNo; m++) {
            cout << tempList[m] << " ";
        }
        if (tempNo == 1)
            cout << "is not available" << endl;
        else
            cout << "are not available" << endl;
        delete[] tempList;
        return false;
    }

}



void Flight::setSeatsReserved(const int numberOfPassengers, const int* seatRow, const char* seatColumn) {
    for (int a = 0; a < numberOfPassengers; a++) {
        seatList[(seatRow[a] - 1) * numberOfColumn + (static_cast<int>(seatColumn[a]) - 65)] = false;
        numberOfAvailableSeat--;
    }
}

void Flight::seatSeatsAvailable(string* listOfString, const int numOfPassenger) {
    for (int a = 0; a < numOfPassenger; a++) {
        numberOfAvailableSeat++;
        int num = listOfString[a][0] - 48;
        char col = listOfString[a][1];
        seatList[(num - 1) * numberOfColumn + (static_cast<int>(col) - 65)] = true;
    }
}

void Flight::showSeatInfo() const {
    cout << "Flight " << flightCode << " has " << numberOfAvailableSeat << " available seats" << endl;
    cout << "  ";
    for (int a = 0; a < numberOfColumn; a++) {
        cout << letter[a] << " ";
    }
    cout << endl;

    for (int b = 0; b < numberOfRow; b++) {
        cout << b + 1;
        for (int c = 0; c < numberOfColumn; c++) {
            if (seatList[(b * numberOfColumn) + c])
                cout << " o";
            else
                cout << " x";
        }
        cout << endl;
    }
}
string Flight::to_string(const int num){
    std::stringstream stream;
    stream << num;
    return stream.str();
}

//
// Created by Aslı Dinç on 6.11.2020.
//

#ifndef HW1_SEATS_H
#define HW1_SEATS_H


class Seats {
public:
    Seats(const int rows, const int columns);
    ~Seats();
    void showSeats();
    int getSeatNum();
    int availableSeatNum();

private:
    int rowNumber;
    int columnNumber;
    int freeSeatNumber;
    bool ** arrForSeats;
};


#endif //HW1_SEATS_H

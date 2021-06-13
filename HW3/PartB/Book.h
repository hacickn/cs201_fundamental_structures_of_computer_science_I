//
// Created by Hacı Çakın on 15.12.2020.
//

#ifndef HW3_B_BOOK_H
#define HW3_B_BOOK_H
#include <string>
using namespace std;
class Book {
public:
    Book();
    ~Book();
    Book(const int newId, const string newName, const int newYear);
    int getId();
    string getName();
    int getYear();
    void setId(const int newId);
    void setName(const string newName);
    void setYear(const int newYear);
private:
    int id;
    string name;
    int year;
};


#endif //HW3_B_BOOK_H

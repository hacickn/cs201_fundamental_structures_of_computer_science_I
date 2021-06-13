//
// Created by Hacı Çakın on 15.12.2020.
//

#include "Book.h"
Book::Book() {

}

Book::Book(const int newId, const string newName, const int newYear) {
    id = newId;
    name = newName;
    year = newYear;
}

Book::~Book() {

}

string Book::getName() {
    return name;
}

void Book::setName(const string newName) {
    name = newName;
}

int Book::getId() {
    return id;
}

void Book::setId(const int newId) {
    id = newId;
}

int Book::getYear() {
    return year;
}

void Book::setYear(const int newYear) {
    year = newYear;
}
//
// Created by Hacı Çakın on 15.12.2020.
//

#include "Student.h"
Student::Student() {
    id = 0;
    name = "";
}

Student::Student(const int newId, const std::string newName) {
    id = newId;
    name = newName;
}

Student::~Student() {
}

int Student::getId() {
    return id;
}

void Student::setId(const int newId) {
    id = newId;
}

string Student::getName() {
    return name;
}

void Student::setName(const string newName) {
    name = newName;
}

BookList& Student::getBookList() {
    return list;
}

bool Student::insertBook(Book book) {
    if(list.insert(list.getLength() + 1, book )){
        return true;
    }else{
        return false;
    }
}
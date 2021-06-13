//
// Created by Hacı Çakın on 14.12.2020.
//

#include "SimpleStudent.h"

Student::Student() {
    name = "";
    id = -1;
}

Student::Student(const int newId, const std::string newName) {
    name = newName;
    id = newId;
}

Student::~Student() {

}

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

void Student::setId(const int newId) {
    id = newId;
}

void Student::setName(const std::string newName) {
    name = newName;
}
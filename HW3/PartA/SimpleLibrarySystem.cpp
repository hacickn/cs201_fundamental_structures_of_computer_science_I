//
// Created by Hacı Çakın on 14.12.2020.
//

#include "SimpleLibrarySystem.h"

LibrarySystem::LibrarySystem() {

}

LibrarySystem::~LibrarySystem() {

}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    if (studentId < 1) {
        cout << "Student Id should be positive " << endl;
    } else if (list.findById(studentId) == -1) {
        if (!list.insert(list.getLength() + 1, Student(studentId, studentName))) {
            cout << "Operation can not be done " << endl;
        }else{
            cout << "Student " << studentId << " has been added" << endl;
        }
    } else {
        cout << "Student " << studentId << " already exist" << endl;
    }
}

void LibrarySystem::deleteStudent(const int studentId) {
    if (list.findById(studentId) == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
    } else {
        if (!list.remove(list.findById(studentId))) {
            cout << "Operation can not be done " << endl;
        }else{
            cout << "Student " << studentId << " has been deleted" << endl;
        }
    }

}

void LibrarySystem::showStudent(const int studentId) const {
    if (list.findById(studentId) == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
    } else {
        list.showIndex(studentId);
    }

}
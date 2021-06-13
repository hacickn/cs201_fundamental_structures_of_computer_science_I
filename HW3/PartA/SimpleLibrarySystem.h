//
// Created by Hacı Çakın on 14.12.2020.
//

#ifndef HW3_SIMPLELIBRARYSYSTEM_H
#define HW3_SIMPLELIBRARYSYSTEM_H
#include <string>
#include "StudentList.h"

using namespace std;

class LibrarySystem {
private:
    StudentList list;
public:
    LibrarySystem();
    ~LibrarySystem();

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;
};


#endif //HW3_SIMPLELIBRARYSYSTEM_H

//
// Created by Hacı Çakın on 15.12.2020.
//

#ifndef HW3_B_STUDENTLIST_H
#define HW3_B_STUDENTLIST_H

#include "Student.h"
#include <iostream>
#include <cstddef>

typedef Student Student;

class StudentList {
public:
    StudentList();

    StudentList(const StudentList& secondList);

    ~StudentList();

    bool isEmpty() const;

    int getLength() const;

    bool retrieve(int index, Student& student) const;

    bool insert(int index, Student student);

    bool remove(int index);

    int findById(const int id) const;

    void showIndex(const int id) const;
    Student& getStudentByIndex(const int index) const;
private:
    struct ListNode {
        Student student;
        ListNode* next;
    };

    int size;
    ListNode* head;

    ListNode* find(int index) const;
};

#endif //HW3_B_STUDENTLIST_H

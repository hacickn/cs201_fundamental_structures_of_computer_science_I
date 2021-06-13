//
// Created by Hacı Çakın on 14.12.2020.
//

#include "StudentList.h"

using namespace std;
StudentList::StudentList() {
    size = 0;
    head = NULL;
}

StudentList::StudentList(const StudentList& secondList) {
    if (secondList.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        head = new ListNode;
        (*head).student = (*secondList.head).student;

        ListNode* newPtr = head;

        for (ListNode* ptr = (*secondList.head).next; ptr != NULL; ptr = (*ptr).next) {
            (*newPtr).next = new ListNode;
            newPtr = (*newPtr).next;
            (*newPtr).student = (*ptr).student;
        }
        (*newPtr).next = NULL;
    }
}

StudentList::~StudentList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool StudentList::isEmpty() const {
    return size == 0;
}

int StudentList::getLength() const {
    return size;
}

StudentList::ListNode* StudentList::find(int index) const {
    if ((index < 1) || (index > getLength())) {
        return NULL;
    } else {
        ListNode* cur = head;
        for (int skip = 1; skip < index; ++skip) {
            cur = (*cur).next;
        }
        return cur;
    }
}

int StudentList::findById(const int id) const {
    ListNode* cur = head;
    for (int skip = 1; skip <= size; skip++) {

        if (cur->student.getId() == id) {
            return skip;
        }
        cur = (*cur).next;
    }
    return -1;
}

void StudentList::showIndex(const int id) const {
    int index = findById(id);
    ListNode* listNode = find(index);
    if(listNode != NULL){
        cout << "Student ID: " << listNode->student.getId() << " Student Name: " << listNode->student.getName() << endl;
    }else{
        std::cout << "There is null" << std::endl;
    }
}

bool StudentList::retrieve(int index, Student& student) const {
    if ((index < 1) || (index > getLength())) {
        return false;
    } else {
        ListNode* cur = find(index);
        student = (*cur).student;
        return true;
    }
}

bool StudentList::insert(int index, Student student) {

    if ((index < 1) || (index > getLength() + 1)) {
        return false;
    }

    ListNode* newPtr = new ListNode;
    size = getLength() + 1;
    (*newPtr).student = student;
    //cout << student.getId() << " * " << student.getName() << endl;

    if (index == 1) {
        (*newPtr).next = head;
        head = newPtr;
    } else {
        ListNode* prev = find(index - 1);
        (*newPtr).next = (*prev).next;
        (*prev).next = newPtr;
    }

    return true;
}

bool StudentList::remove(int index) {
    ListNode* cur;

    if ((index < 1) || (index > getLength())) {
        return false;
    }

    size--;
    if (index == 1) {
        cur = head;
        head = head->next;
    } else {
        ListNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}


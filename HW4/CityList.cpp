/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#include "CityList.h"

CityList::CityList() {
    size = 0;
    head = NULL;
}

CityList::CityList(const CityList& secondList) {
    if (secondList.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        head = new ListNode;
        (*head).city = (*secondList.head).city;

        ListNode* newPtr = head;

        for (ListNode* ptr = (*secondList.head).next; ptr != NULL; ptr = (*ptr).next) {
            (*newPtr).next = new ListNode;
            newPtr = (*newPtr).next;
            (*newPtr).city = (*ptr).city;
        }
        (*newPtr).next = NULL;

        size = secondList.size;
    }
}

CityList::~CityList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool CityList::isEmpty() const {
    return size == 0;
}

int CityList::getLength() const {
    return size;
}

CityList::ListNode* CityList::find(int index) const {
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

int CityList::findByName(const string name) const {
    ListNode* cur = head;
    for (int skip = 1; skip <= size; skip++) {

        if (cur->city.getName() == name) {
            return skip;
        }
        cur = (*cur).next;
    }
    return -1;
}

bool CityList::insert(int index, City city) {

    if ((index < 1) || (index > getLength() + 1)) {
        return false;
    }

    ListNode* newPtr = new ListNode;
    size = getLength() + 1;
    (*newPtr).city = city;
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

bool CityList::remove(int index) {
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

City& CityList::getCityByIndex(const int index) const {

    ListNode* cur = head;
    for (int skip = 1; skip < index; ++skip) {
        cur = (*cur).next;
    }
    return cur->city;
}
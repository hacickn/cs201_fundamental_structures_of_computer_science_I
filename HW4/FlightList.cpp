/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#include "FlightList.h"

FlightList::FlightList() {
    size = 0;
    head = NULL;
}

FlightList::FlightList(const FlightList& secondList) {
    if (secondList.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        head = new ListNode;
        (*head).flight = (*secondList.head).flight;

        ListNode* newPtr = head;

        for (ListNode* ptr = (*secondList.head).next; ptr != NULL; ptr = (*ptr).next) {
            (*newPtr).next = new ListNode;
            newPtr = (*newPtr).next;
            (*newPtr).flight = (*ptr).flight;
        }
        (*newPtr).next = NULL;

        size = secondList.size;
    }
}

FlightList::~FlightList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool FlightList::isEmpty() const {
    return size == 0;
}

int FlightList::getLength() const {
    return size;
}

FlightList::ListNode* FlightList::find(int index) const {
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

int FlightList::findById(const int id) const {
    ListNode* cur = head;
    for (int skip = 1; skip <= size; skip++) {

        if (cur->flight.getCode() == id) {
            return skip;
        }
        cur = (*cur).next;
    }
    return -1;
}

bool FlightList::insert(int index, Flight flight) {

    if ((index < 1) || (index > getLength() + 1)) {
        return false;
    }

    ListNode* newPtr = new ListNode;
    size = getLength() + 1;
    (*newPtr).flight = flight;
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

bool FlightList::remove(int index) {
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

Flight& FlightList::getFlightByIndex(const int index) const{

    ListNode* cur = head;
    for (int skip = 1; skip < index; ++skip) {
        cur = (*cur).next;
    }
    return cur->flight;

}
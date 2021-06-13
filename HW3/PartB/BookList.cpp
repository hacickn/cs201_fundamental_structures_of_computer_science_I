//
// Created by Hacı Çakın on 15.12.2020.
//

#include "BookList.h"
#include <math.h>
BookList::BookList() {
    size = 0;
    head = NULL;
}

BookList::BookList(const BookList& secondList) {
    if (secondList.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        head = new ListNode;
        (*head).book = (*secondList.head).book;

        ListNode* newPtr = head;

        for (ListNode* ptr = (*secondList.head).next; ptr != NULL; ptr = (*ptr).next) {
            (*newPtr).next = new ListNode;
            newPtr = (*newPtr).next;
            (*newPtr).book = (*ptr).book;
        }
        (*newPtr).next = NULL;
        size = secondList.size;
    }
}

BookList::~BookList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool BookList::isEmpty() const {
    return size == 0;
}

int BookList::getLength() const {
    return size;
}

bool BookList::retrieve(int index, Book& book) const {
    if ((index < 1) || (index > getLength())) {
        return false;
    } else {
        ListNode* cur = find(index);
        book = (*cur).book;
        return true;
    }
}

bool BookList::insert(int index, Book book) {
    if ((index < 1) || (index > getLength() + 1)) {
        return false;
    }

    ListNode* newPtr = new ListNode;
    size = getLength() + 1;
    (*newPtr).book = book;
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

bool BookList::remove(int index) {
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

int BookList::findById(const int id) const {
    ListNode* cur = head;
    for (int skip = 1; skip <= size; skip++) {

        if (cur->book.getId() == id) {
            return skip;
        }
        cur = (*cur).next;
    }
    return -1;
}


void BookList::showIndex(const int index) const {
    ListNode* listNode = find(index);
    if (listNode != NULL) {
        Book tempBook = listNode->book;
        int size = trunc(log10(tempBook.getId())) + 1;
        cout << tempBook.getId();
        for(int a = 0; a < 12 - size; a++){
            cout << " ";
        }
        cout << tempBook.getName();
        for(int a = 0; a < 30 - tempBook.getName().length(); a++){
            cout << " ";
        }
        cout << tempBook.getYear();
        int secondSize = trunc(log10(tempBook.getYear())) + 1;
        for(int a = 0; a < 16 - secondSize; a++){
            cout << " ";
        }
    } else {
        cout << "There is null" << endl;
    }
}

BookList::ListNode* BookList::find(int index) const {
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

Book& BookList::getBookByIndex(const int index) {
    ListNode* cur = head;
    for (int skip = 1; skip < index; ++skip) {
        cur = (*cur).next;
    }
    return cur->book;

}
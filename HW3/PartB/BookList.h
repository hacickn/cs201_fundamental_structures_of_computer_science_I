//
// Created by Hacı Çakın on 15.12.2020.
//

#ifndef HW3_B_BOOKLIST_H
#define HW3_B_BOOKLIST_H
#include <iostream>
#include <cstddef>
#include "Book.h"

typedef Book Book;

class BookList {
public:
    BookList();
    BookList(const BookList& secondList);
    ~BookList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, Book& book) const;
    bool insert(int index, Book book);
    bool remove(int index);
    int findById(const int id) const;
    void showIndex(const int index) const;
    Book& getBookByIndex(const int index);
private:
    struct ListNode{
        Book book;
        ListNode* next;
    };

    int size;
    ListNode* head;
    ListNode* find(int index) const;
};


#endif //HW3_B_BOOKLIST_H

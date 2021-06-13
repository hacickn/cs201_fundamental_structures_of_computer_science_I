//
// Created by Hacı Çakın on 15.12.2020.
//

#ifndef HW3_B_LIBRARYSYSTEM_H
#define HW3_B_LIBRARYSYSTEM_H
#include <string>
#include "StudentList.h"
#include "BookList.h"
#include "Student.h"
#include "Book.h"

using namespace std;

class LibrarySystem {
private:
    StudentList studentList;
    BookList bookList;
public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);

    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);

    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;
};


#endif //HW3_B_LIBRARYSYSTEM_H

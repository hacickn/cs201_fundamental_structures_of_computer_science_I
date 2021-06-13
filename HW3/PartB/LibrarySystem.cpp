//
// Created by Hacı Çakın on 15.12.2020.
//

#include "LibrarySystem.h"

LibrarySystem::LibrarySystem() {

}

LibrarySystem::~LibrarySystem() {

}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) {
    if (bookId < 1) {
        cout << "Book Id should be positive " << endl;
    } else if (bookList.findById(bookId) == -1) {
        if (!bookList.insert(bookList.getLength() + 1, Book(bookId, bookName, bookYear))) {
            cout << "Operation can not be done " << endl;
        } else {
            cout << "Book " << bookId << " has been added" << endl;
        }
    } else {
        cout << "Book " << bookId << " already exist" << endl;
    }
}

void LibrarySystem::deleteBook(const int bookId) {
    if (bookList.findById(bookId) == -1) {
        cout << "Book " << bookId << " does not exist" << endl;
    } else {
        for (int a = 1; a <= studentList.getLength(); a++) {
            for (int b = 1; b <= studentList.getStudentByIndex(a).getBookList().getLength(); b++) {
                if (studentList.getStudentByIndex(a).getBookList().getBookByIndex(b).getId() == bookId) {
                    cout << "Book " << bookId << " has been returned" << endl;
                    studentList.getStudentByIndex(a).getBookList().remove(b);
                }
            }
        }
        bookList.remove(bookList.findById(bookId));
        cout << "Book " << bookId << " has been deleted" << endl;

    }
}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    if (studentId < 1) {
        cout << "Student Id should be positive " << endl;
    } else if (studentList.findById(studentId) == -1) {
        if (!studentList.insert(studentList.getLength() + 1, Student(studentId, studentName))) {
            cout << "Operation can not be done " << endl;
        } else {
            cout << "Student " << studentId << " has been added" << endl;
        }
    } else {
        cout << "Student " << studentId << " already exist" << endl;
    }
}

void LibrarySystem::deleteStudent(const int studentId) {
    //TODO buraya öğrencinin aldığı tüm kitapları geri vermesi eklenecek
    if (studentList.findById(studentId) == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
    } else {
        Book s;
        int bookId;
        for(int a= 1; a <= studentList.getStudentByIndex(studentList.findById(studentId)).getBookList().getLength(); a++){
            studentList.getStudentByIndex(studentList.findById(studentId)).getBookList().retrieve(a,s);
            bookId = s.getId();
            returnBook(bookId);
            a--;
        }
        studentList.remove(studentList.findById(studentId));

        cout << "Student " << studentId << " has been deleted" << endl;

    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {

    if (bookList.findById(bookId) == -1) {
        cout << "Book " << bookId << " does not exist for checkout" << endl;
    } else if (studentList.findById(studentId) == -1) {
        cout << "Student " << studentId << " does not exist for checkout" << endl;
    } else {
        bool availability = true;

        for (int a = 1; a <= studentList.getLength(); a++) {
            for (int b = 1; b <= studentList.getStudentByIndex(a).getBookList().getLength(); b++) {
                if (studentList.getStudentByIndex(a).getBookList().getBookByIndex(b).getId() == bookId) {
                    availability = false;
                }
            }
        }

        if (availability) {
            Book book = bookList.getBookByIndex(bookList.findById(bookId));
            studentList.getStudentByIndex(studentList.findById(studentId)).insertBook(book);
            cout << "Book " << bookId << " has been check out by student " << studentId << endl;
        } else {
            cout << "Book " << bookId << " has been already check out by another student" << endl;
        }
    }
}

void LibrarySystem::returnBook(const int bookId) {
    if (bookList.findById(bookId) == -1) {
        cout << "Book " << bookId << " does not exist returned" << endl;
    } else {
        for (int a = 1; a <= studentList.getLength(); a++) {
            for (int b = 1; b <= studentList.getStudentByIndex(a).getBookList().getLength(); b++) {
                if (studentList.getStudentByIndex(a).getBookList().getBookByIndex(b).getId() == bookId) {
                    cout << "Book " << bookId << " has been returned" << endl;
                    studentList.getStudentByIndex(a).getBookList().remove(b);
                    return;
                }
            }
        }
        cout << "Book " << bookId << " has not been checked out" << endl;
    }
}

void LibrarySystem::showAllBooks() const {
    cout << "Book id     Book name                     Year            Status" << endl;
    Book b;
    for (int i = 1; i <= bookList.getLength(); i++) {
        bookList.retrieve(i, b);
        showBook(b.getId());
    }
}

void LibrarySystem::showBook(const int bookId) const {
    if (bookList.findById(bookId) == -1) {
        cout << "Book " << bookId << " does not exist" << endl;
    } else {
        bookList.showIndex(bookList.findById(bookId));

        bool availability = true;

        for (int a = 1; a <= studentList.getLength(); a++) {
            for (int b = 1; b <= studentList.getStudentByIndex(a).getBookList().getLength(); b++) {
                if (studentList.getStudentByIndex(a).getBookList().getBookByIndex(b).getId() == bookId) {
                    availability = false;
                    cout << "Checked out by student " << studentList.getStudentByIndex(a).getId() << endl;
                }
            }
        }

        if (availability) {
            cout << "Not checked out" << endl;
        }
    }
}

void LibrarySystem::showStudent(const int studentId) const {
    if (studentList.findById(studentId) == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
    } else {
        studentList.showIndex(studentId);
    }
}
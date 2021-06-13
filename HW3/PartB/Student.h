//
// Created by Hacı Çakın on 15.12.2020.
//

#ifndef HW3_B_STUDENT_H
#define HW3_B_STUDENT_H
#include <string>
#include "BookList.h"

using namespace std;
class Student {
private:
    int id;
    string name;
    BookList list;
public:
    Student();
    Student(const int newId,const std::string newName);
    ~Student();
    int getId();
    BookList& getBookList();
    string getName();
    void setId(const int newId);
    void setName(const string newName);
    bool insertBook(Book book);
};


#endif //HW3_B_STUDENT_H

//
// Created by Hacı Çakın on 14.12.2020.
//

#ifndef HW3_SIMPLESTUDENT_H
#define HW3_SIMPLESTUDENT_H
#include <string>

class Student {
private:
    int id;
    std::string name;
public:
    Student();
    Student(const int newId,const std::string newName);
    ~Student();
    int getId();
    std::string getName();
    void setId(const int newId);
    void setName(const std::string newName);
};


#endif //HW3_SIMPLESTUDENT_H

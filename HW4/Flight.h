/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_FLIGHT_H
#define HW4_FLIGHT_H
#include <string>
using namespace std;

class Flight {
private:
    string deptCity;
    string destCity;
    int code;
    int cost;
public:
    Flight();
    Flight( string newDeptCity, string newDestCity, string newCode, string newCost);

    string getDeptCity() const;

    string getDestCity() const;

    int getCode() const;

    int getCost() const;

};


#endif //HW4_FLIGHT_H

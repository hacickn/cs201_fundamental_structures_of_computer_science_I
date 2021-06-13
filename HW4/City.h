/*
 *  Hacı Çakın
 *  21802641
 *  Cs201 Section 01
 */

#ifndef HW4_CITY_H
#define HW4_CITY_H
#include <string>
using namespace std;
class City {
private:
    string name;
    bool isVisited;
public:
    City();
    City(const string name);
    City(const City& second);
    string getName() const;
    bool getVisited()const;
    void setName(string name);
    void setVisited(bool isVisit);
};


#endif //HW4_CITY_H

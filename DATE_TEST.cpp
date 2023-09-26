

#include <iostream>

#include "DATE.h"


using namespace std;

int main2()
{
    Date d (22,3,2004);

    cout<< d << endl;
    cout << endl;


    cout << "Test Setters" << endl;
    d.setDay(04);
    d.setMonth(12);
    d.setYear(2021);

   cout << d << endl;
   cout << endl;

   cout << "Test Getters" << endl;
   cout << d.getDay() << endl;
   cout << d.getMonth() << endl;
   cout << d.getYear() << endl;


    return 0;
}

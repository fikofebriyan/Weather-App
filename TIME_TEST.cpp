
#include <iostream>


#include "TIME.h"

using namespace std;

int main4()
{
   Time t(23,20);

   cout << t << endl;
   cout << endl;

   cout << "Test Setters" << endl;
   t.setHour(10);
   t.setMinute(12);
   cout <<"Time " << t<< endl;
   cout << endl;

   cout << "Test Getters"<< endl;
   cout << t.getHour() << endl;
   cout << t.getMinute() << endl;


return 0;
}

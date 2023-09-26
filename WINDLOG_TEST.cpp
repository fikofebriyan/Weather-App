
#include "WINDLOG.h"

using namespace std;

int main6()
{


    Windlog w (5, 80, 85);
   cout << w << endl;

   cout << endl;

   cout << "Test Windlog Setters"<<endl;
   w.SetWindSpeed(25);
   w.SetSolarRadiation(120);
   cout << w << endl;
   cout << endl;

    cout << "Test Windlog Getters"<<endl;
   cout << w.GetWindSpeed() <<endl;
   cout << w.GetRadiation() << endl;


return 0;
}

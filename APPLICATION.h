#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED



#include <iostream>
#include <fstream>

#include <map>
#include <vector>

//-------------------------------------------------------------------------------

// include classes
#include "DATE.h"
#include "TIME.h"
#include "WINDLOG.h"
#include "BinarySearchTree.h"

//------------------------------------------------------------------------------

    /**
	 * @class Binary Search Tree
	 *
	 * @author Fiko Febriyan
	 * @version 01
	 * @date 10/04/2022
	 *
	 **/

//-------------------------------------------------------------------------------

using namespace std;


// to use in option 5
typedef struct
{
    Date d ;
    Time TimeStruct;
    float radiation;

} WindLogType;

//-------------------------------------------------------------------------------


class Application
{

public:

    /**
    * @brief initialise vector windlog
    **/
    vector<WindLogType> windlog;

    /**
    * @brief initialise  BST
    **/
    BinarySearchTree <float> BST;

    /**
    * @brief display 6 menus
    * @return void
    **/
    void DisplayMenu();

    /**
    * @brief ask user for input
    * @return void
    **/
    void UserInput();

    /**
    * @brief to read the text file then CSV file
    * and do calculation for speed, radiation and temperature
    * @return void
    **/
    void ReadFile();

    /**
    * @brief function 1 print speed and air temperature
    * for specific month year
    **/
    void choice1();

    /**
    * @brief function 2 print Average wind speed
    *  and average ambient air temperature for each month of a specified year
    * @return void
    **/
    void choice2();


    /**
    * @brief function 3 print total solar radiation in kWh/m2
    *  for each month of a specified year
    * @return void
    **/
    void choice3();

    /**
    * @brief function 4 print average wind speed (km/h),
    * average ambient air temperature and
    * total solar radiation in kWh/m2 for each month of a specified year
    * and print into CSV file
    * @return void
    **/
    void choice4();

    /**
    * @brief Function 5 prints Highest Solar Radiation and Time for given Date
    * @return void
    **/
    void choice5();

    /**
    * @brief to be use in userInput method
    **/
    int month = 0;
    int year = 0;
    int day = 0;

    float AverageSpeed = 0;
    float radiation = 0;
    float AverageAirTemp = 0;

    Date dateApp;
    Time T;
    Windlog WindL;

private:
    map <int, map<int, vector<Windlog> > > MapW;

};



#endif // APPLICATION_H_INCLUDED

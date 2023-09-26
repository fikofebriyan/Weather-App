#ifndef WINDLOG_H_INCLUDED
#define WINDLOG_H_INCLUDED


#include <iostream>

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


class Windlog
{
public:

        /**
        * @brief default constructor
        **/
        Windlog();

        /**
        * @brief second constructor
        **/
        Windlog(float speed, float solarrad, float ATemp);


        /**
        * @brief set wind speed
        **/
        void SetWindSpeed(float speed);

        /**
        * @brief get wind speed
        **/
        float GetWindSpeed() const;

        /**
        * @brief set solar radiation
        **/
        void SetSolarRadiation(float solarR);

        /**
        * @brief get radiation
        **/
        float GetRadiation() const;

        /**
        * @brief set air temperature
        **/
        void SetAirTemperature(float ATemp);

        /**
        * @brief get air temperature
        **/
        float GetTemperature() const;

        /**
        * @brief istream method to read file
        * @return input
        **/
	    friend istream& operator >> (istream &input, Windlog &W);

private:

    float WindSpeed;
    float SolarRadiation;
    float airTemperature;
};

        /**
        * @brief ostream method to output or print to the screen
        * @return os
        **/
        ostream& operator << (ostream &os, const Windlog &W);




#endif // WINDLOG_H_INCLUDED

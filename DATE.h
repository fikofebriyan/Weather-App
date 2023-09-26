#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED


#include <iostream>

//------------------------------------------------------------------------------

    /**
	 * @class Date
	 *
	 * @author Fiko Febriyan
	 * @version 01
	 * @date 10/04/2022
	 *
	 **/

//-------------------------------------------------------------------------------


using namespace std;


class Date
{
public:

        /**
        * @brief default constructor
        **/
        Date();

        /**
        * @brief second constructor
        **/
        Date(int days, int months, int years);

        /**
        * @brief set the day
        **/
	    void setDay (int days);

        /**
        * @brief get the day
        **/
        int getDay () const;

        /**
        * @brief set month
        **/
	    void setMonth (int months);

        /**
        * @brief get month
        **/
	   int getMonth () const;

	    /**
        * @brief set year
        **/
        void setYear (int years);

        /**
        * @brief get year
        **/
        int getYear () const;

        /**
        * @brief set all the day, months, and year
        **/
	    void setDate (int days, int months, int years);

        /**
        * @brief get all the date
        **/
	    int getDate () const;

	    /**
        * @brief change the number to string of months
        **/
        string StringMonth(const int monthnumber);

	    /**
        * @brief istream method to read file
        * @return input
        **/
	    friend istream &operator >> (istream &input, Date &D);

private:

        int m_day;
        int m_month;
        int m_year;
        string MonthToString;
};

       /**
        * @brief ostream method to output or print to the screen
        * @return os
        **/
	     ostream &operator << (ostream &os, const Date &D);



#endif // DATE_H_INCLUDED

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED


#include <iostream>


//------------------------------------------------------------------------------

    /**
	 * @class Time
	 *
	 * @author Fiko Febriyan
	 * @version 01
	 * @date 10/04/2022
	 *
	 **/

//-------------------------------------------------------------------------------

using namespace std;

class Time
{

public:

	/**
	* @brief default constructor
	**/
	Time();

	/**
	* @brief second constructor
	**/
	Time (int hours, int minutes);

	/**
	* @brief set the hour
	**/
    void setHour (int hours);

    /**
	* @brief get hour
	**/
	int getHour () const;

    /**
	* @brief set the minute
	**/
	void setMinute (int minutes);

	/**
	* @brief the minute
	**/
	int getMinute () const;

	/**
	* @brief set all the time of hour and minute
	**/
	void setTime (int hours, int minutes);

	/**
	* @brief istream method to read file
	* @return input
	**/
	friend istream& operator >> (istream &input, Time &T);

private:

	int TheHour;
	int TheMinute;
};

    /**
	* @brief ostream method to output or print to the screen
	* @return os
	**/
     ostream& operator << (ostream &os, const Time &T);



#endif // TIME_H_INCLUDED

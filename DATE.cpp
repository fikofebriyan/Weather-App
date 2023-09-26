
//----------------------------------------------------
#include "DATE.h"
//----------------------------------------------------


//default constuctor
Date::Date ()
{
	m_day = 0;
	m_month = 0;
	m_year = 0;
}

//second constructor
Date::Date (int days, int months, int years)
{
	m_day = days;
	m_month = months;
	m_year = years;
}

//setters and getter methods
void Date::setDay (int days)
{
    m_day = days;
}

int Date::getDay () const
{
    return m_day;
}


void Date::setMonth (int months)
{
    m_month = months;
}

int Date::getMonth () const
{
    return m_month;
}

void Date::setYear (int years)
{
    m_year = years;
}

int Date::getYear () const
{
    return m_year;
}


void Date::setDate (int days, int months, int years)
{
    m_day = days;
    m_month = months;
    m_year = years;
}


string Date::StringMonth(const int s_month)
{
    switch(s_month)
    {
        case 1:
            MonthToString = "January";
            break;
        case 2:
            MonthToString = "February";
            break;
        case 3:
            MonthToString = "March";
            break;
        case 4:
            MonthToString = "April";
            break;
        case 5:
            MonthToString = "May";
            break;
        case 6:
            MonthToString = "June";
            break;
        case 7:
            MonthToString = "July";
            break;
        case 8:
            MonthToString =  "August";
            break;
        case 9:
            MonthToString ="September";
            break;
        case 10:
            MonthToString = "October";
            break;
        case 11:
            MonthToString = "November";
            break;
        case 12:
            MonthToString = "December";
            break;

    }
    return MonthToString;
}

istream &operator >> (istream &input, Date &D)
{
    input >> D.m_month >> D.m_year;
    return input;
}

ostream &operator << (ostream &os, const Date &D)
{
    os << "Date: "
    << D.getDay() << " / "
    << D.getMonth()  << " / "
    << D.getYear();

    return os;
}

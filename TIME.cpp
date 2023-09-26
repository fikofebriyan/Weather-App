
//----------------------------------------------------
#include "TIME.h"
//----------------------------------------------------


using namespace std;

//default constuctor
Time::Time ()

{
	TheHour = 00;
	TheMinute = 00;
}

//second constructor
Time::Time (int hours, int minutes)
{
	TheHour = hours;
	TheMinute = minutes;
}


//setters and getters methods
void Time::setHour (int hours)
{
    TheHour = hours;
}

int Time::getHour () const
{
    return TheHour;
}

void Time::setMinute (int minutes)
{
    TheMinute = minutes;
}

int Time::getMinute () const
{
    return TheMinute;
}


void Time::setTime (int hours, int minutes)
{
    TheHour = hours;
    TheMinute = minutes;
}


istream &operator >> (istream &input, Time &T)
{
    input >> T.TheHour >> T.TheMinute ;
    return input;
}

ostream &operator << (ostream &os, const Time &T)
{
    os << "Time " <<T.getHour() << " : " << T.getMinute();
    return os;
}



//----------------------------------------------------
#include "WINDLOG.h"
//----------------------------------------------------


//default constructor
Windlog::Windlog()
{
	WindSpeed = 0;
	SolarRadiation = 0;
	airTemperature = 0;
}

//second constructor
Windlog::Windlog(float speed, float solarR, float ATemp)
{
	WindSpeed = speed;
	SolarRadiation = solarR;
	airTemperature = ATemp;
}

// setters and getters method
void Windlog::SetWindSpeed(float speed)
{
    WindSpeed = speed;
}

float Windlog::GetWindSpeed() const
{
    return WindSpeed;
}

void Windlog::SetSolarRadiation(float solarR)
{
    SolarRadiation = solarR;
}

float Windlog::GetRadiation() const
{
    return SolarRadiation;
}


void Windlog::SetAirTemperature(float ATemp)
{
    airTemperature = ATemp;
}


float Windlog::GetTemperature() const
{
    return airTemperature;
}

ostream& operator << (ostream &os, const Windlog &W)
{
    os<<" Windlog " << W.GetWindSpeed() << ", " << W.GetRadiation() << ", " << W.GetTemperature();
    return os;
}

istream& operator >> (istream &input, Windlog &W)
{
    input>>W.WindSpeed>>W.SolarRadiation>>W.airTemperature;
    return input;
}

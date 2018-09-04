#include <iostream>// adding the iostream library 
#include <string> // adding the time library
#include "time.h" // adding the time header

using namespace std;

time::time()  // default constructor
{
	hour = 0;
	mins = 0;
}
time::time(int hh, int mm) // non - default constructor
{
	hour = hh; 
	mins = mm;
}
void time::setHours(int hh)  // method set hour
{
	hour = hh;
}
void time::setMins(int mm) // method set mins
{
	mins = mm;
}
void time::setTime(int hh, int mm) //method set time
{
	hour = hh;
	mins = mm;
}
int time::getHours()const // method to get hour
{
	return hour;
}
int time::getMins()const // method to get mins 
{
	return mins;
}
int time::getTime()const
{
	return (hour,mins);
}

void time::print()const // method to print
{
	cout<<hour<<":"<<mins;
}

istream& operator >>(istream& inputObj, time& t) // input operator 
{
	inputObj >>t.hour>>t.mins;
	return inputObj;
}
ostream& operator <<(ostream& outputObj, const time& t) //output operator
{
	outputObj<<t.hour <<":" <<t.mins;
	return outputObj;
}
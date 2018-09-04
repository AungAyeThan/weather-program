#include "date.h"
#include <string>
using namespace std;

date::date()    // default constructor
{
	day = 00;
	month = 00;
	year = 00;
}
date::date(int d, int m, int y) // non-default constructor
{
	day = d;
	month = m;
	year = y;
}

void date::setDay(int d)    // set method to get the day
{
	day  = d;
}
void date::setMonth(int m) // set method to get the month
{
	month = m;
}
void date::setYear(int y)  //set method to get the year
{
	year = y;
}
void date::setDate(int d, int m , int y) //set method to get the date
{
	day = d;
	month = m;
	year = y;
}

int date::getDay()const  //get method to return the day
{
	return day;
}
int date::getMonth()const // const method to return the month
{
	return month;
}
int date::getYear()const // const method to return the year
{
	return year;
}

void date::print()const // const method to print out the screen
{
	cout <<day<<"/"<<month<<"/"<<year;
}

istream& operator >>(istream& inputObj , date& d) //input operator
{
	inputObj >>d.day>>d.month>>d.year;
	return inputObj;
}
ostream& operator <<(ostream& outputObj , const date& d) //output operator
{
	outputObj<<d.day<<"/"<<d.month<<"/"<<d.year;
	outputObj<<endl;
	return outputObj;
}

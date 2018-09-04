#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include<iostream>
#include <string>
#include <fstream>

#include "date.h"
#include "time.h"
#include "Vector.h"
#include "bst.h"
#include <map>

using namespace std;

typedef struct // global variable
{
    date d;    // date class over composition
    time t;    // time class over composition
    float speed; // float variable named speed
	float SolarRadiation; //float variable SolarRadiation
}WindLogType; // name of the struct

class Program
{
public:
	/**
	 * @class Program
	 * @brief  Contains all the methods for the program to run and input the data
	 *
	 * Default constructor and non-default constructor are to be used in this date header.
	 *
	 * run method will be invoked and run in the main.
	 * menu void method is to be show the menu option and take a input from the user.
	 * maxWindSpeed method is to calculate the max wind speed from the data
	 * AvgWindSpeed method is to calculate the average wind speed from the data
	 * TotalSolarRadiation method is to calculate te total solar radiation
	 * SwitchMonthStatement method to swap the month name with the number input
	 *
	 *
	 * @author Aung Aye Than
	 * @version 01
	 * @date 20/02/2016
	 *
	 * @author Aung Aye Than
	 * @version 02
	 * @date 28/02/2016 Error checking and adding doxygen comments.
	 *
	 *
	 *
	 *
	 * @bug There aren't any bugs in the data headers. Everything tested out correctly.
	 *
	 */
	Program();
        /**
		 * @brief  run () method
		 *
		 * The method which will get invoked and run inside the main
		 * It contains menu every option method inside to run the program
		 *
		 * @return void
		 */
	void run();
        /**
		 * @brief  menu () method
		 *
		 * The method which contain menu option for the program
		 * It contains every option method inside for the user to choose
		 *
		 * @return Vector<WindLogType>windlog - parameter for vector template named windlog
		 */
	void menu(map<int, Vector<WindLogType> >myMap);
        /**
		 * @brief  menu () method
		 *
		 * The method which contain menu option for the program
		 * It contains every option method inside for the user to choose
		 *
		 * @return void
		 * @param Vector<WindLogType>windlog - parameter for vector template named windlog
		 */
	void maxWindSpeed (map<int, Vector<WindLogType> >myMap);
        /**
		 * @brief  maxWindSpeed () method
		 *
		 * The method which will find max wind speed depending on the user input year and month
		 *
		 * @return void
		 * @param Vector<WindLogType>windlog - parameter for vector template named windlog
		 */
	void AvgWindSpeed (map<int, Vector<WindLogType> >myMap);
        /**
		 * @brief  TotalSolarRadiation () method
		 *
		 * The method which will find average wind speed depending on the user input year.
		 *
		 * @return void
		 * @param Vector<WindLogType>windlog - parameter for vector template named windlog
		 */
	void TotalSolarRadiation (map<int, Vector<WindLogType> >myMap);
        /**
		 * @brief printAvgWindSpeed_TotalSR_toCSV () method
		 *
		 * The method which will print out the average windspeed and total solar radiation to the csv output file
		 *
		 * @return void
		 * @param Vector<WindLogType>windlog - parameter for vector template named windlog
		 */
	void printAvgWindSpeed_TotalSR_toCSV(map<int, Vector<WindLogType> >myMap);


        /**
		 * @brief SwitchMonthStatement () method
		 *
		 * The method which will print out the month name by swapping with the number input file
		 *
		 * @return string
		 * @param inputyear - int parameter to get the month from the user
		 */
	string SwitchMonthStatement(int inputyear);
	void MaxSolarRadiation(map<int, Vector<WindLogType> >myMap);
	
	
	void TestProgramForAllMethod (map<int, Vector<WindLogType> >myMap);
	

private:
	Vector<WindLogType>windlog; //vector
	map<int, Vector<WindLogType> >myMap;
    map <int, Vector<WindLogType> >::iterator record;
};
#endif

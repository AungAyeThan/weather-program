#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/**
	 * @class Time
	 * @brief  Contains all the methods to store for hour and minutes
	 * 
	 * Default constructor and non-default constructor are to be used in this time header.
	 * set methods and get methods are invoked in this Time  header 
	 *
	 *hours and minutes are declared and initialised as int type.
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
	 * @bug There aren't any bugs in the data headers. Everything tested out correctly.
	 * 
	 */

class time
{
	
public:
		/** 
		 * @brief  Default constructor
		 * 
		 * Default constructor with initial values.
		 *
		 * @pre 00:00 is the default value for day, month, year.
		 *
		 */
	time();
		/** 
		 * @brief  Non-Default constructor
		 * 
		 * Non-Default constructor with initial values.
		 *
		 * @pre 00:00 is the default value for hour and mins.
		 *
		 * @post values vary according to the user input.
		 *
		 */
	time(int hh, int mm);
		/** 
		 * @brief  set method to store for hour input
		 * 
		 * Method where the hour data are set and store
		 * 
		 * @param  hh - hour parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 * @pre 00 is the default hour
		 * 
		 */
	void setHours(int hh);
	/** 
		 * @brief  set method to store for minute input
		 * 
		 * Method where the minute data are set and store
		 * 
		 * @param  mm - day parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 * @pre 00 is the default date
		 * 
		 */
	void setMins(int mm);
	/** 
		 * @brief  set method to store for hour and minute input
		 * 
		 * Method where all together the hour and minute data are set and store
		 * 
		 * @param  hh - hour parameter with int type to initialise the value.
	     *	       mm - day parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 * @pre 00:00 is the default hour and minute
		 * @post values vary according to the user input.
		 * 
		 */
	void setTime(int hh, int mm);
		/** 
		 * @brief  set method to print the data
		 * 
		 * Method where the hour and minute data are to be print out
		 * 
		 * @param  mm - day parameter with int type to initialise the value.
		 *
		 * 
		 */
	void print()const;
		/** 
		 * @brief  get method to return the hour
		 * 
		 * Method where the hour and minute data are to be print out
		 * 
		 *
		 */
	int getHours()const;
		/** 
		 * @brief  get method to return the hour
		 * 
		 * Const Method where the hour data are to be return 
		 * 
		 *
		 */
	int getMins()const;
		/** 
		 * @brief  get method to return the mins
		 * 
		 * Method where the hour and minute data are to be print out
		 * 
		 */
	int getTime()const;
	friend ostream& operator <<(ostream&, const time& t); //output operator 
	friend istream& operator >>(istream& , time& t); //input operator
	
private:
	int hour;  // int variable
	int mins;  // int variable
};
#endif
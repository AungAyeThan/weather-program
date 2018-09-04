#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<fstream>
#include <string>
using namespace std;


	/**
	 * @class date
	 * @brief  Contains all the methods to store for day, month and year.
	 *
	 * Default constructor and non-default constructor are to be used in this date header.
	 * set methods and get methods are invoked in this date header
	 *
	 *day, month and year are declared and initialised as int type.
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

class date
{
	friend ostream& operator <<(ostream& ,const date& d); //operator
	friend istream& operator >>(istream& , date& d); //operator
public:
		/**
		 * @brief  Default constructor
		 *
		 * Default constructor with initial values.
		 * @pre 0,0,0 is the default value for day, month, year.
		 *
		 */
	date();
		/**
		 * @brief  Non-Default constructor
		 *
		 * Non-Default constructor which include int parameter values of day, month and year.

		 * @param d - parameter d to store date information.
		 *		  m - parameter m to store month information.
		 *		  y - parameter y to store year information.
		 *
		 */
	date(int d, int m, int y);
		/**
		 * @brief  set method to store for day input
		 *
		 * Method where the date data are set and store
		 *
		 * @param  d - day parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 * @pre 00 is the default date
		 *
		 */
	void setDay(int d);
		/**
		 * @brief  set method to store for month input
		 *
		 * Method where the month data are set and store inside
		 *
		 * @param  m - day parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 *
		 */
	void setMonth(int m);
		/**
		 * @brief  set method to store for year input
		 *
		 * Method where the year data are set and stored inside
		 *
		 * @param  y - year parameter with int type to initialise the value.
		 *
		 * @return void
		 *
		 */
	void setYear(int y);

		/**
		 * @brief  set method to store for date input
		 *
		 * Method where all together day, month and year are stored inside
		 *
		 * @param d - parameter d to store date information.
		 *		  m - parameter m to store month information.
		 *		  y - parameter y to store year information.
		 *
		 * @return void
		 *
		 */

	void setDate(int d, int m, int y);
		/**
		 * @brief  return for date input
		 *
		 * Method where the day data is get and return.
		 *
		 * @return const int;
		 *
		 */
	int getDay()const;
		/**
		 * @brief  return for month input
		 *
		 * Method where the day data is get and returned.
		 *
		 * @return const int;
		 *
		 */
	int getMonth()const;
		/**
		 * @brief  return for year input
		 *
		 * Method where the year data is get and return.
		 *
		 * @return const int;
		 *
		 */
	int getYear()const;
		/**
		 * @brief  print the day, month and year
		 *
		 * Method where the day, month and year will output on the screen
		 *
		 * @return void
		 *
		 */
	void print()const;

private:
	int day; // integer variable
	int month;// integer variable
	int year;// integer variable


};
#endif

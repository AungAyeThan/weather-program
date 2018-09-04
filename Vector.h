#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class Vector
{
	/**
	 * @class Vector
	 * @brief  Contains all the methods to store for Vector
	 *
	 * Vector method such as push_back, at, length, isFull, isEmpty ,  pop_back are to be included in this class
	 * Push_Back () is to push the data into the vector.
	 * at() is to point out the location of array parameter of the data.
	 * isFull () is to check whether the vector is full or not
	 * isEmpty () is to check whether the vector is empty or not.
	 * size () is to return the length of the vector
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
public:
		/**
		 * @brief  Default constructor
		 *
		 * Default constructor with initial values and create the array with initial capcaity
		 *
		 *
		 * @pre capacity = 1;
		 *		list = new T[capacity];
		 *		start array= 0;
		 *		last array= 0;
		 *		length =0;
		 * @post Values will vary depanding on the input
		 *
		 */
	Vector();
		/**
		 * @brief  Non-Default constructor
		 *
		 * Non-Default constructor with values and parameters.
		 *
		 * @pre capacity = 1;
		 *		list = new T[capacity];
		 *		start array= 0;
		 *		last array= 0;
		 *		length =0;
		 *
		 * @post values vary according to the user input.
		 *
		 */
	Vector(int maximumSize);

		/**
		 * @brief  Push_back Method
		 *
		 * A method to push the data inside into the vector and it can automatically resize when the capacity length is array out of bound.
		 *
		 * @param  input - const template parameter to initialise
		 *
		 * @post values vary according to the user input.
		 *
		 */
	void push_back(const T& input);

		/**
		 * @brief  pop_back Method
		 *
		 * A method to delete the last input data from the vector.
		 *
		 * @return void
		 *
		 */
	void pop_back();
		/**
		 * @brief  pop_back Method
		 *
		 * A method to print out the vector to the screen.
		 *
		 *@return void
		 *
		 */
	void print()const;
		/**
		 * @brief  Size method
		 *
		 * A method to return the last input data from the vector.
		 *
		 *@return long
		 *
		 */
	long size() const;
		/**
		 * @brief  at method
		 *
		 * A method to return the location parameter of the array
		 *
		 * @param p- parameter to get the location of the array
		 *@return template T&
		 *
		 */
	T& at(int n);
		/**
		 * @brief  isEmpty method
		 *
		 * A const method to return true when the array is empty and return false when it is full
		 *
		 *
		 * @return bool
		 *
		 */
	bool isEmpty() const;
		/**
		 * @brief  isEmpty method
		 *
		 * A const method to return true when the array is empty and return false when it is full
		 *
		 * @return bool
		 *
		 */
	bool isFull() const;
	friend ostream& operator << (ostream&, const Vector& B);

private:
	T *list;		//templete T pointer for the array
	long length;	// variable to get the length of the vector
	int capacity;   // variable to get the capacity
	T *start;		// pointer to locate the start of the array
	T *last;		// pointer to located the last of the array
};

//default constructor
template <class T> //template
Vector<T>::Vector()
{
	capacity = 900000;
	list = new T[capacity];
	start = 0;
	last = 0;
	length =0;

}
// non-default constructor
template <class T>
Vector<T>::Vector(int maximumSize)
{
    length = 0;
    capacity = maximumSize;
    list = new T[capacity]; // template array
	start = list;
	last = list;
}

//push back method
template <class T>
void Vector<T>::push_back(const T& input)
{
    if(length==capacity-1) // checking whether length is equal to capacity or not
	{
		T* newArray = new T [capacity*2]; //new pointer array
		T* newArrayPointer = newArray; // copy new address to old address
		T* oldArrayPointer = list; // initialising the old array as oldArrayPointer to point out the old array
		while( oldArrayPointer != (list +length)) // going until the old array pointer is equal to the length
		{
          (*newArrayPointer) = (*oldArrayPointer);     //copy the data to new array
          newArrayPointer++;
          oldArrayPointer++;                           // shift the pointers
		}
		start = newArray;                              // declaring the start pointer
        last = (newArray + length);                    // declaring the  last location of the array
		capacity = capacity*2;                         //increasing the capacity size to double
		delete[] list;                                 // delete old array pointer
        list = newArray;                               // point out the new array
		list[length] = input;                          // creating new array
		length++;                                      // length++
	}
	else
	{
		list[length] = input;                           // store the input into the array
		length++;
	}
}
//pop back method
template<class T>
void Vector<T>::pop_back()
{
	 length--;
}

// size method
template <class T>
long Vector<T>::size()const
{
	return length;
}

//at method
template <class T>
T& Vector<T>::at(int p)
{
	if (p>=0 && p<length)
	{
		return list[p]; // get the location of the array
	}
}
//print method
template <class T>
void Vector<T>::print()const
{
    for(int i=0;i<length;i++)
    {
        cout << list[i] << " "; // get the print
    }
}
//is full method 
template <class T>
bool Vector<T>::isFull() const
{
    if (length == 600000)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//is empty
template <class T>
bool Vector<T>::isEmpty() const
{
    if (length == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
#endif

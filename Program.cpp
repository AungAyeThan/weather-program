#include "Program.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Vector.h"
#include <map>

using namespace std;


	
Program::Program()      //default constructor
{
	//WindSpeed = 0;
	//SolarRadiation = 0;
	
}

void Program::run()  // method that will take all the method inside and is invoked by the main program to run the program
{
	string inputFile,inputDay, inputMonth, inputYear, inputHour, inputMins,WSstring, SRstring,csv;   // declare and initialise the variable to string
	float WSdata,SRdata;  // declare and initialise the variable to float
	WindLogType T1; // Declaring the variable as Windlogtype vector
    ifstream infile; // inserting the input line to open the file
	ifstream input;	 // inserting the input line to open the file
	//int check = 0;

	map<int, Vector<WindLogType> >myMap; // creating the map 
	map <int, Vector<WindLogType> >::iterator record; // adding the iterator pointer into the bst.

    infile.open("Metdata/met_index.txt"); //  open the input text file
	cout <<"Loading the data file from 2006-2016. Please Wait For A While"<<endl;
	cout <<endl;

	while(!infile.eof()) // process until end of line
	{
	   getline(infile,csv); // get the line from the txt file
	   string name = "Metdata/"+csv; // declaring the data name for the text file input
	   input.open(name.c_str()); 
		
		cout <<csv<<endl;
		if (input.is_open())
		{
			cout << "Finished loading. Going into another data " <<endl;
			cout <<endl;
		}
		else
		{
			cout << "Sorry: Cannot able to load the data"  <<endl;
			cout<<endl;
		}

		input.ignore(500,'\n'); // ignore the first line
		while (!input.eof()) // read the data until the line ends;
		{
			getline(input, inputDay,'/'); // get the input day
			getline(input, inputMonth,'/'); // get the input month
			getline(input, inputYear,' '); // get the input year
			getline(input, inputHour,':'); // get the input hour
			getline(input, inputMins,','); // get the input mins
			for (int i=0; i<10 ; i++)
			{
				getline(input, WSstring,','); // get the Wind speed from the csv
			}

			for (int i=0;i<1;i++)
			{
				getline(input, SRstring,','); // get the solar radiation data from the csv
			}
			
			for (int i=0;i<1;i++)
			{
				input.ignore(50,',');
				input.ignore(50,'\n');
			}
					
			if(WSstring !="N/A" && SRstring !="N/A") // condition to check not to have blank data and N/A data 
			{
				int dd=atof(inputDay.c_str());// converting the string to int for dd
				int mm=atof(inputMonth.c_str());// converting the string to int for mm
				int yy=atof(inputYear.c_str());// converting the string to int for yy
				int hour=atof(inputHour.c_str());// converting the string to int for hour
				int mins=atof(inputMins.c_str());// converting the string to int for mins
				WSdata = atof(WSstring.c_str());// converting the string to int for wind speed
				SRdata = atof(SRstring.c_str());// converting the string to int for solar radiation
				T1.d.setDate(dd,mm,yy); // add the date data into the vector
				T1.t.setTime(hour,mins);// add the time data into the vector
				T1.speed = WSdata;      // add the speed data into the vector
				T1.SolarRadiation = SRdata; // add the solar radiation into the vector
				
				int check = 0;
				for (record=myMap.begin();record!=myMap.end();record++)
				{
					 if ( record->first == yy)
					 {
						 record->second.push_back(T1);
						 check= 1;
					 }
				}

				if (check != 1)
				{
					Vector<WindLogType> data;
					data.push_back(T1);
					myMap.insert(pair <int, Vector<WindLogType> >(yy,data));
				}
			}
		}
		input.close();
	}
   cout <<"Finished processing the data. Here is the menu option"<<endl;
   menu(myMap);// calling menu () to print out the menu option.
}


void Program::menu(map<int, Vector<WindLogType> >myMap) // menu option
{
	int input;
	cout << "Welcome to the menu option"<<endl;
	cout << "========================================================================================="<<endl;
	cout << " Enter any options below to start the program"<<endl;
	cout << " Option 1: Maximum wind speed for a specified month and year" <<endl;
	cout << " Option 2: Average wind speed for each month of a specified year" <<endl;
	cout << " Option 3: Total solar radiation in kWh/m for each month of specific year"<<endl;
	cout << " Option 4: Average wind speed and solar radiation in kWh/m for each month of specific year"<<endl;
	cout << "           (Printed in the csv file)" <<endl;
	cout << " Option 5: Maximum Solar Radiation for the specific d/m/yyyy"<<endl;
	cout << " Option 7: END"<<endl;
	cout << "=========================================================================================="<<endl;
	cout <<"Enter the input option: ";
	cin >> input; // get the input from the user
	cout << endl;

    // loop won't stop until the input becomes 6
	while(input!=6)
	{
		if(input==1)
		{
			maxWindSpeed(myMap); //invoking the maxWindSpeed () method
		}
		
		else if (input==2)
		{
			AvgWindSpeed(myMap);//invoking the avgWindSpeed () method
		}
		
		else if(input==3)
		{
			TotalSolarRadiation(myMap);//invoking the TotalSolar radiation () method
		}
		
		else if(input==4)
		{
			 printAvgWindSpeed_TotalSR_toCSV(myMap);//invoking the printAvgWindSpeed_TotalSR_toCSV () method
		}
		else if (input ==5)
		{
			MaxSolarRadiation(myMap); // invoking the option 5 :MaxSolarRadiation 
		}
		else if(input==7)
		{
			TestProgramForAllMethod(myMap); // test program that tested the variable and class
		} 
		else
		{
			cout <<"Sorry: No option available" <<endl; //error message
		}
		cout <<endl;
		cout <<"Enter the input choice again (6 to end the program): ";
		cin >> input;
	}
}



void Program::maxWindSpeed(map<int, Vector<WindLogType> >myMap) // method to get the max wind speed
{
    // show the message to the user
	cout <<endl;
    cout <<"You choose option 1: finding max wind speed" <<endl; // output message
	int inputYear, inputMonth;
	string MaxInorderWS;
	int yearchecking = 0;
	int monthchecking = 0;

	cout <<"Enter the year and month to find the max wind speed" <<endl;// output message
	cout <<"Year :";
	cin  >>inputYear;
	cout <<"Month :";
	cin  >>inputMonth;
	cout <<endl;
	float MaxWS = 0;

	map <int, Vector<WindLogType> >::iterator record; // creating the map iterator
	BST<double> WSBST;
	ifstream inputMax;
	ofstream output ("bstoutput.txt");
	cout <<"Input Data for Month and Year is : "<<SwitchMonthStatement(inputMonth)<<" / "<<inputYear<<endl;
	cout << '\n';

	
	 for(record = myMap.begin();record!=myMap.end();record++) // for going throught all the data in the map 
    {
		if (record->first==inputYear ) // checking whether input year is available in the map or not
		{
			yearchecking++;
			for(int i=0; i <record->second.size();i++)
			{
				if( inputMonth==record->second.at(i).d.getMonth())
				{
					monthchecking++;
					if (record->second.at(i).speed > MaxWS) // getting the highest wind speed
					{
						WSBST.insert(record->second.at(i).speed); // insert the map data into the BST	
					}
				}
			}
		}
	 }
	WSBST.print(output); // print method into the txt file
	double Highestwindspeed = 0;
	inputMax.open("bstoutput.txt"); // open the txt file
	while(getline(inputMax,MaxInorderWS))
	{
		double HighestWS = atof(MaxInorderWS.c_str());
		while (HighestWS > Highestwindspeed)
		{
			Highestwindspeed = HighestWS; // get the highest wind speed
		}
	}
	
	if(Highestwindspeed !=0) // print out the screen only when the data is available
	{
        cout <<"Max windSpeed for the "<<SwitchMonthStatement(inputMonth)<<" of " <<inputYear<<" is : "<<Highestwindspeed<<endl;
	}
	else if(yearchecking <= 0) // show error msg when there is no data for this year or year is invalid
	{
		cout <<"Sorry: There is no data for year " << inputYear<<endl;
	}
	else if(monthchecking <=0) // show error msg when there is no data for this month or year is invalid
	{
		cout <<"Sorry: There is no data for month " << SwitchMonthStatement(inputMonth)<<endl;
	}
	else
	{
		cout<<"Sorry there is no available data for " <<SwitchMonthStatement(inputMonth)<<" of " <<inputYear<<endl; // error message
	} 
	
} //end method



void Program::AvgWindSpeed (map<int, Vector<WindLogType> >myMap)
{
	cout <<endl;
    int windYear;
    //message to show the user
	cout <<"You choose option 2: finding Average wind speed" <<endl;
	cout << "Enter Year To Display Average Wind Speed of Each Month: ";
    cin >> windYear;
    cout << endl;
	cout <<"Here are the Average wind speed for available month of "<<windYear<<endl; // output message
	cout <<endl;
	int Yearcount=0;


	for(record = myMap.begin();record!=myMap.end();record++)
    {
		if (record->first==windYear) // checking the 
		{ 
			Yearcount++;
			for (int i = 1; i <= 12; i++)	//loop to check to have data for all month
			{
				float totalWindSpeed = 0;
				int counter = 0;
				// loop to go through every line of the data
				for (int j = 0; j < record->second.size(); j++)
				{
					if (record->second.at(j).d.getMonth() == i)// go over next step only when the month is equal to data
					{
						counter++;
						totalWindSpeed = totalWindSpeed +record->second.at(j).speed; // calcualating total windspeed
					}
				}
		
				double AvgWindSpeed = (double)totalWindSpeed/(double)counter ; // calculating the average wind speed
				if (totalWindSpeed !=0) // print out the total wind speed if total wind speed is not zero
				{
					cout <<SwitchMonthStatement(i) << ": " <<AvgWindSpeed <<" km/h"<< endl; // print out the avg wind speed
				}
				else
				{
					cout <<"No available data for this month "<<SwitchMonthStatement(i)<<endl; // error message
				}
			}
		}
	}
	if (Yearcount <=0)
	{
		cout <<"Sorry: NO data avilable for the year of "<< windYear<<endl;
	}
}



void Program::TotalSolarRadiation(map<int, Vector<WindLogType> >myMap) // method to get the total solar radiation
{
	int InputYear;
    cout << "Enter year to display Total Solar Radiation: ";
    cin >> InputYear;
    cout << endl;
    int Yearcount =0;
	cout <<"Here are the Total solar radiation for available month of "<<InputYear<<endl;
	for(record = myMap.begin();record!=myMap.end();record++) // reading through all reacord 
    {
		if (record->first==InputYear)
		{
			Yearcount++;
			for (int i = 1; i <= 12; i++) // loop through month 1 to 12
			{
				float totalSolarRadiation = 0;
				for (int j = 0; j < record->second.size(); j++) // loop through every line
				{
					if (record->second.at(j).d.getMonth() == i)
					{
						if(record->second.at(j).SolarRadiation >= 100) // to take only solar radiation which are greater than or equal to 100
						{
							totalSolarRadiation = totalSolarRadiation + record->second.at(j).SolarRadiation ; // calculating total solar radiation
						}
					}
				}
			
				if(totalSolarRadiation !=0 && Yearcount>0) // print the total solar radiation only it has available data
				{
					double total = double(totalSolarRadiation * 0.167) / 1000; // convert the Wh to kWh
					cout << SwitchMonthStatement(i) << " :" << total <<" kWh/m2"<< endl;
				}
				else // if there is data in solar radiation 
				{
					cout <<"No available data for "<<SwitchMonthStatement(i)<<endl;
				}
			}
		}
	}

	if (Yearcount <=0)
	{
		cout <<"Sorry: NO data avilable for the year of "<< InputYear<<endl;
	}
}



void Program::printAvgWindSpeed_TotalSR_toCSV(map<int, Vector<WindLogType> >myMap) // function to printout into the 
{
	ofstream output("WindandSolar.csv"); // output the windspeed and total solar radiation data into the csv
	int InputYear;
	//showing the message
	cout <<"You choose Option 4: Print out the data into csv"<<endl;
	cout << "Enter Year to output the data into csv: ";
	cin >> InputYear;
    cout << endl;
	output<<"Year"<<endl;
	output <<InputYear<<endl;
	output <<"Month"<<","<<"Wind Speed" <<","<<"Solar Radiation" <<endl;

	for(record = myMap.begin();record!=myMap.end();record++) // to go through every record
    {
		if (record->first==InputYear)
		{
			for (int i = 1; i <= 12; i++) // looping every month
			{
				int totalWindSpeed = 0;
				float totalSolarRadiation = 0;
				int count = 0;
				for (int j = 0; j < record->second.size(); j++) // looping every line of the file
				{
					if (record->second.at(j).d.getMonth() == i) // if condition to go through when the month is equal to record month data
					{
						totalWindSpeed= totalWindSpeed + record->second.at(j).speed; // get the total windspeed
						count++;
					}
					if (record->second.at(j).d.getMonth() == i)
					{
						if(record->second.at(j).SolarRadiation >= 100) // only process when the solar radiation is greater than 100
						{
							totalSolarRadiation = totalSolarRadiation + record->second.at(j).SolarRadiation ;// get the total solar radiation
						}
					}
				}
				double avgWindSpeed = (double)totalWindSpeed/(double)count;// finding the avg windspeed
				double total = double(totalSolarRadiation * 0.167) / 1000; // converting into the kWh

				if(totalWindSpeed !=0)
				{
					output  << SwitchMonthStatement(i)  << ", " << avgWindSpeed <<", "<<total<< endl; //print out to the output csv
				}
			}
		}
	}
	cout <<"CSV file is generated names WindandSolar.csv. Please check it in the location folder"<<endl;
}



void Program::MaxSolarRadiation(map<int, Vector<WindLogType> >myMap) //function to find the max solar radiation
{
	string Date;
	float MaxSR = 0;
	int day, month, year;
	int dayinputcheck = 0, SRtime = 0,Srmin = 0;// initialising into 0
	cout <<"Enter the day in dd/mm/yyyy: "<<endl; // output message
	cin >> Date;

	string dd = Date.substr(0,2); // getting the string into 2 place
	string mm = Date.substr(3,5); // getting the string into 2 place
	string yy = Date.substr(6,9); // getting the string into 2 place
	map <int, Vector<WindLogType> >::iterator record; // creating the iterator
	day = atof(dd.c_str()); // converting string to int
	month = atof(mm.c_str());// converting string to int
	year = atof(yy.c_str());// converting string to int

	
	 for(record = myMap.begin();record!=myMap.end();record++)
    {
		if (record->first==year )
		{
			for(int i=0; i <record->second.size();i++)
			{
				if( day == record->second.at(i).d.getDay()&& month==record->second.at(i).d.getMonth()) // valdiation check to pass when the condition is success
				{
					dayinputcheck++;
					if (record->second.at(i).SolarRadiation > MaxSR) // getting the highest wind speed
					{
						MaxSR = record->second.at(i).SolarRadiation; // get the max solar radiation
						SRtime=record->second.at(i).t.getHours();
						Srmin =record->second.at(i).t.getMins();
					}	
				}
			}	
		}
	 }
	 
	 // output when the condtion is true
	 
	if(MaxSR !=0 && dayinputcheck>0) // print out the screen only when the data is available
	{
		cout <<"Date: "<<day<<"/"<<month<<"/"<<year<<endl; // output message
		cout <<"Max Solar radiation for the day is: "<<MaxSR <<" W/m2"<<endl; //output message
		cout <<"Time" <<endl;//output message
		cout <<SRtime<<":"<<Srmin<<endl;
			
	}
	else if (MaxSR!=0 && dayinputcheck <=0) // print out the screen only when the day is available
	{
		cout <<"Sorry: invalid input for dd/mm/yyyy"<<endl; //error message 
	}
	else
	{
		cout<<"Sorry there is no available data" <<endl; //error message

	}
}



string Program::SwitchMonthStatement(int inputyear) // method to covert the int month to string name
{
	switch(inputyear)
	{
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:
		return "Invalid month";
	}
}




void Program:: TestProgramForAllMethod (map<int, Vector<WindLogType> >myMap) //test program
{
	
	WindLogType T2;

// testing date class
    cout <<"Date class" <<endl;
	date d;										cout << "Expected 0/0/0 to print after invoking constructor               : "; d.print();cout<<endl;
	date d2(1,1,2011);							cout << "Expected 1/1/2011 to print after invoking constructor parameter  : "; d2.print(); cout<<endl;
	d.setDay(12);								cout <<"Expected Day  = 12 to print out after putting 12 in setDay()      : "<<d.getDay()<<endl;
	d.setMonth(3);								cout <<"Expected Month= 3 to print out after putting 3 in setMonth()      : "<<d.getMonth()<<endl;
	d.setYear(2016);							cout <<"Expected Year = 2016 to print out after putting 2014 in setYear() : "<<d.getYear()<<endl;
	d.setDate(14,4,2015);						cout <<"Expected to print 14/4/2015 after giving values in print()method  : "; d.print();cout<<endl;cout<<endl;
// testing time class
    cout <<"Time class" <<endl;
	time t;										cout << "Expected 0/0/0 to print after invoking constructor               : "; t.print(); cout<<endl;
	time t2(12,12);								cout << "Expected 12/12 to print after invoking constructor parameter     : "; t2.print(); cout<<endl;
	t.setHours(10);								cout <<"Expected Hour = 10 to print out after putting 10 in setHours()    : "<<t.getHours()<<endl;
	t.setMins(40);								cout <<"Expected Mins = 40 to print out after putting 40 in setMins()     : "<<t.getMins()<<endl;
	t.setTime(1,15);							cout <<"Expected to print 1:15 after giving values in print()method       : "; t.print();cout<<endl;cout<<endl;

// testing vector
	cout <<"Testing Vector" <<endl;
	
	Vector<int>test1;

	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);							cout<<"Expected result to print is 1,2,3 to use after push_back :" ; test1.print(); cout <<endl;

	test1.pop_back();							cout<<"Expected result to print is 1,2 to use after the pop_back :" ; test1.print(); cout <<endl;

												cout <<"Expected result to print out size is 2 after the size() : "<< test1.size(); cout <<endl;

	cout <<"Expected result to print the data inside the array is 1 2 after the print() method :  "; test1.print();cout <<endl;
    cout <<"Expected result to get return value 1 after testing isFull() method ;  " <<test1.isFull(); cout <<endl;
    cout <<"Expected result to get return value 1 after testing isEmpty() method : " <<test1.isEmpty(); cout <<endl;
    cout <<endl;



   // testing the program
	cout <<"Testing the Program" <<endl;
	cout <<endl;
	Program p;
	cout <<"Testing the run method inside the program"<<endl<<endl;
	p.run(); cout <<endl;


	cout <<"Testing the menu method inside the program"<<endl<<endl;
	p.menu(myMap);cout <<endl<<endl;


	cout <<"Testing the AvgWindSpeed method inside the program"<<endl<<endl;
	p.AvgWindSpeed(myMap);
	cout <<endl<<endl;


	cout <<"Testing the maxWindSpeed method inside the program"<<endl<<endl;
	p.maxWindSpeed (myMap);
	cout <<endl<<endl;


	cout <<"Testing the TotalSolarRadiation method inside the program"<<endl<<endl;
	p.TotalSolarRadiation(myMap);
	cout <<endl<<endl;


	cout <<"Testing the printAvgWindSpeed_TotalSR_toCSV method inside the program"<<endl<<endl;
	p.printAvgWindSpeed_TotalSR_toCSV(myMap); cout <<endl;


	cout <<"Expected to get January after the switchMonthStatement(1): " <<SwitchMonthStatement(1)<<endl;

	//testing bst
	cout <<"Testing BST"<<endl;
	BST<int> BSTdata;

	BSTdata.insert(12);
	BSTdata.insert(1);
	BSTdata.insert(35);
	BSTdata.insert(10);
	BSTdata.insert(5);

	cout <<" testing In order traversal method"<<endl;
	cout <<"In Order Traversal:"; BSTdata.inorderTraversal();
	cout <<endl;
	cout <<endl;

	cout <<" testing pre order traversal method "<<endl;
	cout <<"Pre Order Traversal:"; BSTdata.preorderTraversal();
	cout <<endl;
	cout <<endl;

	cout <<" testing post order traversal method "<<endl;
	cout <<"Post Order Traversal:"; BSTdata.preorderTraversal();
	cout <<endl;
	cout <<endl;

	ofstream outputFile;
	outputFile.open("bstTesting.txt");
	BSTdata.print(outputFile);

	cout <<"Testing the search method" <<endl;
	cout <<"Searching no 10"<<endl;
	
	if(BSTdata.search(10))
	{
		cout <<"true" <<endl;
	}
	else
	{
		cout <<"false" <<endl;
	}

	cout <<endl;
	cout <<"true will be return as for the expected result" <<endl;
}




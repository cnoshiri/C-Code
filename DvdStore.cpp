
//: DvdStore.cpp

/* 
 Title: DVD Store
 Date: April 4, 2017
 Author: Chinenye Noshiri
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Write a program to manage DVD rental in a “video” rental store. Create an abstract data type that 
	represents a DVD in this store. Consider all the data and operations that may be necessary for the 
	DVD type to work well within a rental management system. Include a print() member function that 
	displays all the information about the DVD. Test your data type by creating an array of 10 DVD instances 
	and filling them using information read from a test input file that you create. Display the DVD information

 Compile (assuming Cygwin is running): $ g++ DvdStore.cpp DVD.cpp -o dvdstore
 Execution (assuming Cygwin is running): ./dvdstore.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: DVD Class - used to create an instance of a dvd found in a store
 		  Customer class - used to create a customer profile, store the customer
 		  and rent a dvd to this customer. 

 Variables:
 Global variables
 	response - used to read the response typed by the user. 
 	arrOfDvds - used to create an array of dvds
	string value[4] - used to hold each token read from the input file. Token are separated by a comma delimiter
	in - used to open the file TMA2Question1.txt from the directory
	line - used to read each line in the file
	counter - this gets incremented every time a line is read and is used to set the serial number of each dvd item in the list
	fname - used to read the first name of the customer
	lname - used to read the last name of the customer
	addr - used to read the address of the customer
	id - used to read the customer id so that the customer profile can be printed 
Scope related variables
	serialNumber - used to hold the serialNumber of the dvd
	tokenizer - used to split each line based on the comma delimiter
	cusId - used to hold the int variable after the customer id was converted to an int
	dvdFound - indicates the whether the dvd was found or not (true = found, false = not found)
	cusFound - indicates the whether the customer was found or not (true = found, false = not found)
*/

/*
 TEST PLAN
 
 Normal case:
 	>Reading file and loading data..... 
	>-------Welcome to the DVD online store--------
 	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>rent
	>Enter the dvd serial number to rent: 2	
	>Enter the customer id to rent the dvd to: 1
	>The Passion of Christ has now been rented out to: chi nosh
	>Would you like to do continue?['Y' to continue]:

	
Normal case 2
	>Reading file and loading data..... 
	>-------Welcome to the DVD online store--------
	
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>print dvds
	
	>DVD store has: 10 Dvds in stock
	>Serial Number: 1, Video Name: From dusk to dawn, Year Produced:  1996, Genre:  Thriller, Length:  1hr48min
	>Serial Number: 2, Video Name: The Passion of Christ, Year Produced:  2004, Genre:  Drama, Length:  2hr7min
	>Serial Number: 3, Video Name: Finding Nemo, Year Produced:  2003, Genre:  Adventure/Comedy, Length:  1hr40min
	>Serial Number: 4, Video Name: Sister Act, Year Produced:  1992, Genre:  Comedy, Length:  1hr40min
	>Serial Number: 5, Video Name: Harry Porter and the Sorcerer's Stone, Year Produced:  2001, Genre:  Family/Adventure, Length:  2hr32min
	>Serial Number: 6, Video Name: Harry Porter and the Goblet of Fire, Year Produced:  2005, Genre:  Family/Adventure, Length:  2hr32min
	>Serial Number: 7, Video Name: Harry Porter and the Deathly Hallows: Part 1, Year Produced:  2010, Genre:  Family/Adventure, Length:  2hr32min
	>Serial Number: 8, Video Name: Harry Porter and the Sorcerer's Stone, Year Produced:  2010, Genre:  Family/Adventure, Length:  2hr32min
	>Serial Number: 9, Video Name: Charlie And the chocolate Factory, Year Produced:  2005, Genre:  Family/Adventure, Length:  1hr55min
	>Serial Number: 10, Video Name: Sucker Punch, Year Produced:  2011, Genre:  Thriller, Length:  1hr50min
	>done printing......

Normal case 3: ( a new customer profile was created)
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>create customer
	>Enter the first name: chi	
	>Enter the last name: nosh	
	>Enter the address: 123 spruce street
	>The following customer was added: chi nosh 123 spruce street


 Bad Data case 1 (a command that is not recognised is entered)
 	>Reading file and loading data.....
	>-------Welcome to the DVD online store--------

	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>nothing
	>Command entered not recognised
	>Would you like to do continue?[Y/N]

 
 Bad Data case 2 (when the <algorithm> library is not included)
 	>$ g++ TMA2Question1.cpp DVD.cpp -o q1
	>TMA2Question1.cpp: In function ‘int main()’:
	>TMA2Question1.cpp:225:38: error: ‘atoi’ was not declared in this scope
    >int value = atoi(response.c_str());
                                      ^
	>TMA2Question1.cpp:244:41: error: ‘atoi’ was not declared in this scope
    >int value = atoi(serialNumber.c_str());
                                         ^
	>TMA2Question1.cpp:276:42: error: ‘atoi’ was not declared in this scope
    > int value = atoi(serialNumber.c_str());

 
 Bad Data case 3 (When the file could not be opened - file name is invalid)
 	>There was a problem opening the file.
	>Program completed...
 
 Bad Data case 4 (when the following line of code 'arrOfDvds.erase(arrOfDvds.begin() + posOfObject);'
 				 is missing from the 'delete' if-statment)
 	[the dvd is not deleted from the vector]

Bad Data case 5 (when the 'DVD.h' header file is not included)
	Compile error occurs
	>TMA2Question1.cpp: In function ‘int main()’:
	>TMA2Question1.cpp:139:9: error: ‘DVD’ was not declared in this scope
  	>	vector<DVD>arrOfDvds;
        ^
	>TMA2Question1.cpp:139:12: error: template argument 1 is invalid
  	>	vector<DVD>arrOfDvds;
        ^
Bad Data case 6 (renting a dvd when there the customer profile does not exist)
	A message is printed that customer id entered is invalid
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by name
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>print all
	>No customer profiles to print
	>Would you like to do continue?['Y' to continue]:
	>y
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>rent
	>Enter the dvd serial number to rent: 6

	>Enter the customer id to rent the dvd to: 39

	>The customer id entered is invalid
	
	>Would you like to do continue?['Y' to continue]:
	>y
	
Bad Data case 7 (when the dvd serial number is not an int)	
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>rent
	>Enter the dvd serial number to rent: fg
	>
	>The dvd serial number entered is invalid
	>
	>The customer id entered is invalid
	>Would you like to do continue?['Y' to continue]:
	>y

Bad Data case 8 (when the customer id to print was not found )	
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>print customer
	>Enter the id of the customer to print: 2
	>Customer ID is invalid. No customer printed
	>Would you like to do continue?['Y' to continue]:
	>y

Bad Data case 7 (when the dvd serial number is not valid)	
	>Enter 'add' to add a new movie
	>Enter 'del' to delete a movie by dvd serial number
	>Enter 'print dvds' to print all movies in the store
	>Enter 'print all' to print all the customer profiles
	>Enter 'create customer' to create a new customer profile
	>Enter 'print customer' to print a specific customer profile
	>Enter 'rent' to rent a dvd
	>Enter 'return' to return a dvd:
	>rent
	>Enter the dvd serial number to rent: 40
	>
	>The dvd serial number entered is invalid
	>
	>The customer id entered is invalid
	>Would you like to do continue?['Y' to continue]:
	>y

 Discussion:
		The program allows the user to rent out a dvd, add, delete, and print the details of the list of dvds in stock. 
		It also allows the user to print the customer profile and print the customer by the customer id. The 
		program gives the user the option to continue all these actions until when the user chooses to exit
 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include "DVD.h"
using namespace std;

class Customer{
	public:
		//@Purpose: constructor to create a new customer
		//@Param: first name, last name, address and customer id
		//@return: none
		Customer(string fname, string lname, string addr, int id)
		{
			firstName = fname;
			lastName = lname;
			address = addr;
			customerID = id;
		}
		
		//@Purpose: Prints the profile of the customer and also prints all
		//			the dvds the customer has rented
		//@Param: none
		//@return: none
		void print(){
			cout << "Customer ID: " << customerID << "\nFirst Name: " << firstName << "\nLast Name: " << lastName << "\nAddress: " << address;
			//print all the dvds the customer is renting
			if( rentedDvds.size() == 0)
			{
				cout << "\nCustomer has no dvd rented\n";
			}
			else
			{
				cout << "\n\nDvds rented to this customer" << endl;
				cout << "-----------------------------------";
				//iterate through the array of dvds
				for(int i=0; i < rentedDvds.size(); i++)
				{
					rentedDvds[i].print();
				}
				
				cout << endl;
			}
			
		}
		
		//@Purpose: getter that returns the concatenated first and last name of the customer
		//@Param: none
		//@return: full name of customer
		string getName()
		{
			return firstName + " " + lastName;
		}
		
		//@Purpose: Adds a dvd to the collection of dvds rented by the customer
		//@Param: newdvd to add to the vector
		//@return: none
		void AddDvdToRent(DVD newdvd)
		{
			rentedDvds.push_back(newdvd);
		}
		
		//@Purpose: remove the dvd
		//@Param: the serial number of the dvd to delete
		//@return: none
		void removeDvd(int value)
		{
			cout << "size of collections" << rentedDvds.size();
			for(int i=0; i < rentedDvds.size(); i++)
			{
				//check if the serial number matches
				if(rentedDvds[i].getSerialNumber() == value)
				{
					cout << "Dvd is being removed\n";
					rentedDvds.erase(rentedDvds.begin() + i);
					cout << "Dvd has been removed from the customer profile\n";
					break;
				}
			}
		}
		
		//@Purpose: returns the ID of the customer
		//@Param: none
		//@return: customer id
		int getID()
		{
			return customerID;
		}
		
	private:
		vector<DVD> rentedDvds; //holds the collection of dvds the customer has rented
		string firstName;
		string lastName;
		string address;
		int customerID;
};
int main() 
{
	string response; 
	vector<DVD>arrOfDvds; 
	vector <Customer> customers;
	string value[4];
	ifstream in("TMA2Question1.txt"); //name of file to read dvd items from 
	int counter = 0; //will be used as the array index
	string line;
	//used to hold customer information
	string fname;
	string lname;
	string addr;
	string id;
	
	//First read all the dvd's using the text file in the directory
	
	//checks to see if the file is valid
	if (!in.is_open())
        cout << "There was a problem opening the file." << endl;
	else{
			cout << "Reading file and loading data..... ";
			while(getline(in, line)) 
			{   
				counter++;
				// cache the line then get the tokens from it
			  	std::istringstream tokenizer(line);		        
				std::getline(tokenizer, value[0], ','); 
				std::getline(tokenizer, value[1], ',');
				std::getline(tokenizer, value[2], ','); 
				std::getline(tokenizer, value[3]);      
				if(tokenizer) {
			    	arrOfDvds.push_back(DVD(value[0], value[1], value[2], value[3], counter));
				} 
			}
		cout << "\n-------Welcome to the DVD online store--------\n";
	 
		//do while loop execution for managing the DVD store
		do
		{
			//Show to the user the possible commands
			cout << "\nEnter 'add' to add a new movie\n" 
			"Enter 'del' to delete a movie by dvd serial number\n" 
			 "Enter 'print dvds' to print all movies in the store\n"
			 "Enter 'print all' to print all the customer profiles\n"
			 "Enter 'create customer' to create a new customer profile\n"
			 "Enter 'print customer' to print a specific customer profile\n"
			 "Enter 'rent' to rent a dvd\n"
			 "Enter 'return' to return a dvd: \n";
			 
			 getline(cin, response); //read the user's responses
			 
			 //executes print command and prints all dvds in stock
			if(response == "print dvds")
			{
				cout << "\nDVD store has: " << arrOfDvds.size()  << " Dvds in stock"<< endl;
				for(int i=0; i < arrOfDvds.size(); i++)
				{
					arrOfDvds[i].print();
				}
				cout << "done printing......";
			}
			
			//allows the user to print a specific customer
			else if(response == "print customer")
			{
				cout << "Enter the id of the customer to print: ";
				getline(cin, id);
				bool found = false;
				int cusID = atoi(id.c_str());
				
				//iterate through the vector and check if the customer id can be matched
				for(int i=0; i < customers.size() && !found; i++)
				{
					//check if customer id matches
					if(customers[i].getID() == cusID)
					{
						customers[i].print();
						found = true;
					}
						
				}
				
				//if it was never found, print a message letting the user know the customer does not exist
				if(!found)
					cout << "Customer ID is invalid. No customer printed";
			}
			
			//used to print all the customer profiles on file
			else if(response == "print all")
			{
				//check if there are any profiles to print
				if(customers.size() == 0)
				{
					cout << "No customer profiles to print\n";
				}
				
				//iterate through all the profiles and print each customer
				else
				{
					for(int i= 0; i < customers.size(); i++)
					{
						customers[i].print();						
					}
					cout << "done printing......";
				}
				
			}
			
			//used to create a new customer
			else if(response == "create customer")
			{
				cout << "Enter the first name: ";
				getline(cin, fname);
				cout << "\nEnter the last name: ";
				getline(cin, lname);
				cout << "\nEnter the address: ";
				getline(cin, addr);
				Customer newCus(fname, lname, addr, customers.size()+1);
				customers.push_back(newCus);
				cout << "\nThe following customer was added: " << fname << " " << lname << " " << addr << endl;	
			}
			
			//executes add command
			else if(response == "add")
			{ 
				cout << "\nEnter the following information in one line separated by a comma i.e [dvd name], [year produced], [genre], [video length]: ";
				getline(cin, response);
				
				//get all tokens from the user's input and create a new dvd object
				std::istringstream tokenizer(response);		        
				std::getline(tokenizer, value[0], ','); // then get the tokens from it
				std::getline(tokenizer, value[1], ',');
				std::getline(tokenizer, value[2], ','); 
				std::getline(tokenizer, value[3]);      // last token: get the remainder
		
				if(tokenizer) {
					//return the last serialNumber
					int lastSerialNum = arrOfDvds[arrOfDvds.size()-1].getSerialNumber();
					
					//increment the last serialNumber by 1 to create a new serialNumber
					lastSerialNum++;
					
					//save the serial number in the vector
			    	arrOfDvds.push_back(DVD(value[0], value[1], value[2], value[3], lastSerialNum));
			    	cout << "\n Thank you. The following DVD was added to the store : \n";
					arrOfDvds[arrOfDvds.size()-1].print(); //print the last object that was saved
				}
				
			}
			
			//execute delete command
			else if(response == "del")
			{
				int posOfObject = 0;
				bool found = false;
				cout << "\n Enter the dvd serial number to delete: ";
				getline(cin, response);
				//search for the matching dvd 
				for(int i = 0; i < arrOfDvds.size() & !found; i++)
				{
					int value = atoi(response.c_str());
					if(arrOfDvds[i].getSerialNumber() == value)
					{
						posOfObject = i;
						found = true;
					}	
				}
				
				//ask if the user wants to remove the dvd
				cout << "Are you sure you want to delete? [Y to continue]: ";
				getline(cin, response); //read the user's confirmation response
				if(response == "y" || response == "Y")
				{
					//remove the dvd from the list
					arrOfDvds.erase(arrOfDvds.begin() + posOfObject);
					cout << "\nThe dvd has been deleted";
				}
				else
					cout << "No delete was performed";
					
			}
			
			//execute rent command
			else if(response == "rent")
			{
				string serialNumber;
				cout << "Enter the dvd serial number to rent: ";
				getline(cin, serialNumber);
				int value = atoi(serialNumber.c_str());
				bool dvdFound = false;//used to check if the dvd was found in the collection at all
				bool cusFound = false;//used to check if the customer was found in the collection at all
				//iterate through the list of dvds and mark the dvd as rented if serial number matches
				for(int i = 0; i < arrOfDvds.size() && !dvdFound; i++)
				{
					//check if the dvd rent status has been set to true
					if((arrOfDvds[i].getSerialNumber() == value) && (arrOfDvds[i].getRentStatus() == true))
					{
						dvdFound = true; //this indicates the dvd was found in the collection
						cusFound = true;// set this to true so the program does not print the message that the customer was not found
						cout << "\nDvd has already been rented";
						break;
					}
					
					//set the rent status to true and add the customer number to the dvd profile
					else if((arrOfDvds[i].getSerialNumber() == value) && (arrOfDvds[i].getRentStatus() == false))
					{
						dvdFound = true;//this indicates the dvd was found in the collection
						cout << "\nEnter the customer id to rent the dvd to: ";
						getline(cin, id);
						int cusId = atoi(id.c_str()); //convert string to int
						
						//add the rented dvd to the customer's profile
						for(int j = 0; j < customers.size(); j++)
						{
							//if the customer id matches, rent out the dvd to this customer
							if(customers[j].getID() == cusId)
							{
								cusFound = true;//this indicates the customer was found in the collection
								customers[j].AddDvdToRent(arrOfDvds[i]); //add the dvd to the customer's dvd rent collection
								
								//set the dvd rent status to true
								arrOfDvds[i].setDvdStatus(true);
								//set the customer id the dvd has been rented to
								arrOfDvds[i].setCustomer(cusId);
								//show the dvd that was rented
								cout << arrOfDvds[i].getDvdName() << " has now been rented out to: " << customers[j].getName(); 
								break;
							}
								
						}
						
						
						break;
					}	
					
				}
				
				//print appropriate messages for whether the dvd or customer was found on the screen
				if(!dvdFound)
					cout << "\nThe dvd serial number entered is invalid\n";
				if(!cusFound)
					cout << "\nThe customer id entered is invalid\n";
				
			}
			
			//execute return command
			else if(response == "return")
			{
				string serialNumber;
				cout << "Enter the serial Number of dvd to return: ";
				getline(cin, serialNumber);
				
				//iterate through the list, find the dvd and set the rent status to false
				for(int i = 0; i < arrOfDvds.size(); i++)
				{
					//convert the dvd stock # 
					int value = atoi(serialNumber.c_str());
					//check if number entered matches the list of dvds
					if(arrOfDvds[i].getSerialNumber() == value)
					{
						arrOfDvds[i].print();
						cout << "\n[The above DVD will be returned]\n";
						//set the rent status to false
						arrOfDvds[i].setDvdStatus(false);
						
						//iterate through all the customer list
						for(int j=0; j<customers.size(); j++)
						{
							//remove the dvd from the customer profile
							if(customers[j].getID() == arrOfDvds[i].getCustomerId())
							{
								cout << "in customers for loop - found it";
								//remove the dvd from the vector - pass the serial number of the dvd to remove
								customers[j].removeDvd(value);	
								break;							
							}
						}
						
						//set the customer id to -1 indicating customer has been removed from the dvd data
						arrOfDvds[i].setCustomer(-1); 
					}
				}
			}
			
			//when the command is not found 
			else{
				cout << "\nCommand entered not recognised";
			}
			
			cout << "\nWould you like to do continue?['Y' to continue]: \n";
			getline(cin, response); //read the next reponse by the user
		}while(response == "Y" || response == "y");
	}
	
	
	cout << "Program completed...";
	return 0;
}



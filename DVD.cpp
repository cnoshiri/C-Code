#include "DVD.h"
DVD::DVD(){
}
DVD::~DVD(){
}
DVD::DVD(string vid, string gen, string yr, string vidL, int serialNum){
	videoName = vid;
	yearProduced = yr;
	genre = gen;
	videoLength = vidL;	
	serialNumber = serialNum;
	rented = false;
}

//@Purpose: return the serial number
//@Param: none
//@return: none
int DVD::getSerialNumber()
{
	return serialNumber;
}

//@Purpose: return the customer id
//@Param: none
//@return: none
int DVD::getCustomerId()
{
	return customerId;
}

//@Purpose: return the rent status
//@Param: none
//@return: none
bool DVD::getRentStatus()
{
	return rented;
}

//@Purpose: get the dvd name
//@Param: none
//@return: video name
string DVD::getDvdName()
{
	return videoName;
}

//@Purpose: set the dvd status and save the customer id
//@Param: true|false
//@return: none
void DVD::setDvdStatus(bool value)
{
	rented = value;
}

//@Purpose: set the the customer id
//@Param: int value
//@return: none
void DVD::setCustomer(int value)
{
	customerId = value;
}

//@Purpose: get the dvd name
//@Param: none
//@return: none
void DVD::print()
{
	cout << "\nDvd stock#: " << serialNumber << "\nVideo Name: " << videoName << "\nYear Produced: " 
	<< yearProduced 
	<< "\nGenre: " 
	<< genre << "\nLength: " << videoLength;
	
	if(rented == true)
	{
		cout << "\nRented to customer id: " << customerId << "\n";
	}
		
	else
		cout << "\nRent status: not rented\n";
}

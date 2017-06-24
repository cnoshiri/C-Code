
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class DVD{
	private:
		string videoName;
		string yearProduced;
		string genre;
		string videoLength;
		int serialNumber;
		bool rented;
		int customerId;
	public:
		int getSerialNumber();
		void rentOutDvd();
		bool getRentStatus();
		string getDvdName();
		void  setDvdStatus(bool value);
		void setCustomer(int value);
		int getCustomerId();
		DVD();
		~DVD();
		DVD(string vid, string yr, string gen, string vidL, int serialNum);
		//prints the information of the DVD
		void print();
};


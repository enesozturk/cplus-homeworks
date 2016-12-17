#pragma once
#include "date.h"
#include <string>
#include <time.h>

using namespace std;

class Customer{
public:
	Customer(); //Constructor
	void saveCustomer(); //save customer to a text file
	void readCustomer(); //read customer from a text file
	void removeCustomer(string tr); //remove selected line from text file

	void setName(string name); //set customer name
	void setSurname(string surname); //set customer surname
	void setTelNo(string telno); //set customer telephone number
	void setTrNo(string trno); //set customer TR number
	void setDate(Date date); //set customer bridth date

	void listCustomers(); //print list of customers function
	void addCustomer(); //add a customer and display function
	void deleteCustomer(); //delete customer from txt file

	string getName(); //get functions
	string getSurname();
	string getTrNo(); 
	string getTelNo();
	Date getDate();

	string generateTrNo(); //generate random TR number
	string generateTelNo(); //generate random Tel number
private:
	string cName;
	string cSurname;
	string cTrNo;
	string cTelNo;
	string BrithDate;
	Date randDate[800]; //There are 40 name and 20 surname, so we have 800 different combinations.
	int nameIndex, surnameIndex, dateIndex;
};
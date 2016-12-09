#pragma once
#include <string>
#include <time.h>

using namespace std;

class Customer{
public:
	Customer();
	void save();

	void setName(string name);
	void setTelNo(string telno);
	void setSurname(string surname);
	void setDate(string date);
	void setTrNo(string trno);

	void listCustomers();
	void addCustomer();
	void deleteCustomer(int trno);
	void listCustomerMenu(int tcno2);

	string getTrNo();
	string getTelNo();
	string getName();
	string getSurname();
	//Date getDate();

	
	string generateTrNo();
	string generateTelNo();
private:
	string cName;
	string cSurname;
	string cTrNo;
	string cTelNo;
	//Date cBrithDay;
};
#pragma once 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	string date;
public:
	Date();

	void setDate(string d);

	string getDate();

};
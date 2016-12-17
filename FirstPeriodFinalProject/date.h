#pragma once 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date
{
private:
	int day; //decralations
	int month;
	int year;
	string date;
public:
	Date();

	string getDate(); //returns string date value
};
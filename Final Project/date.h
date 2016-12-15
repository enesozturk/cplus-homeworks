#pragma once 
#include <string>

using namespace std;

class Date{
private:
	string date,day,mount,year;
public:
	Date();
	void bringDate();
	void generateDate();
	void getDate();
};
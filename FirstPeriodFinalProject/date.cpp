#include "date.h"
#include <iostream>

using namespace std;

Date::Date(){
	day = rand() % (30 - 1 + 1) + 1;
	month = rand() % (12 - 1 + 1) + 1;
	year = rand() % (2016 - 1950 + 1) + 1950;
	date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
string Date::getDate()
{
	return date;
}
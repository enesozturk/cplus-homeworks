#include "date.h"
#include <time.h>
#include <iostream>

using namespace std;


Date::Date(){

}

void Date::generateDate(){
	srand(time(NULL));
	day = '1' + rand() % 30;
	mount = '1' + rand() % 11;
	year = '50' + rand() % 1950;
	date = day + "/" + mount + "/" + year;
	cout << date;
}

void Date::getDate(){

}



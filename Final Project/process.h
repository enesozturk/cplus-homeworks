#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <Windows.h>
#include <time.h>

using namespace std;
class Process
{
public:
	Process(); //cunstructor

	void bringProductCode(); //bring product code

	void bringTrNo(); //bring TR number

	void bringProcessCode(); //bring process code

	void controlTR(string tr);
	void saveProcess(); //save process to txt file
	void readProcesses(); //read processes from txt file
	void removeProcess(string c); //remove selected line from txt file

	void listProcesses(); //list maden processes
	void deleteProcess();

	string generateProcessCode(); //generate ramdom process code

private:
	string  cProcessCode; //variables declarations
	string	cProductCode;
	string  cCustomerTrNo;

};
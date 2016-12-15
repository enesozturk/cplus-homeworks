#include "process.h"
#include "product.h"
#include "control.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//function descriptions has been explained in header files
using namespace std;

char STRAIGHTLINEPR = 186;
Control controlPr;

Process::Process(){

}

string Process::generateProcessCode(){
	srand(time(NULL));
	string cProcessCode = "";
	for (int i = 0; i < 4; i++){
		cProcessCode += '1' + rand() % 9;
	}
	return cProcessCode;
}
void Process::bringProductCode(){
	cout << "Enter Product Code: ";
	cin >> cProductCode;
}
void Process::bringTrNo(){
	cout << "Enter TR No: ";
	cin >> cCustomerTrNo;
	controlTR(cCustomerTrNo);
}

void Process::controlTR(string tr){
	fstream control;
	control.open("Customers.txt", fstream::in | fstream::out | fstream::app);
	if (control.is_open() == true){
		if (control >> tr){
			cout << "TR number has been found." << endl;
		}
		else{
			cout << "TR number couldn't find!" << endl;
		}
	}
	control.close();
}
void Process::saveProcess(){
	fstream save;

	save.open("Processes.txt", fstream::in | fstream::out | fstream::app);

	if (save.is_open() == true){
		save << generateProcessCode() << " " << cProductCode << " " << cCustomerTrNo << endl;
	}

	save.close();
}
void Process::readProcesses(){
	fstream read;
	read.open("Processes.txt", fstream::in);
	if (read.is_open() == true){
		string processCode, productCode, customerTrNo;
		string LinePr;
		while (read >> processCode >> productCode >> customerTrNo){
			LinePr = processCode + " " + productCode + " " + customerTrNo;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEPR;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << std::left << setw(40) << LinePr;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEPR << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	read.close();
}
void Process::removeProcess(string transcode){
	fstream processes, tempPr;

	processes.open("Processes.txt", fstream::in | fstream::out | fstream::app);
	tempPr.open("tempPr.txt", fstream::in | fstream::out | fstream::app);

	if (processes.is_open() == true){
		string TransCode, productCodeP, TrnoP;
		while (processes >> TransCode >> productCodeP >> TrnoP){
			if (TransCode != transcode){
				tempPr << TransCode << " " << productCodeP << " " << TrnoP << endl;
			}
		}
	}
	processes.close();
	tempPr.close();
	remove("Processes.txt");
	rename("tempPr.txt", "Processes.txt");
	system("cls");
	listProcesses();
	controlPr.askToContinue();
}

void Process::listProcesses(){
	controlPr.printCeiling(40);
	controlPr.printIntermediate(40, " Processes");
	controlPr.printIntermediate(40, " Trans Code - Product Code - Customer TR");
	controlPr.printSeparatrix(40);
	readProcesses();
	controlPr.printBottom(40);
}
void Process::deleteProcess(){
	listProcesses();
	cout << "Enter Trans code to delete process: ";
	string prCode;
	cin >> prCode;
	removeProcess(prCode);
}

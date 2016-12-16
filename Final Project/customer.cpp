#include "customer.h"
#include "control.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

//function descriptions has been explained in header files
using namespace std;

char STRAIGHTLINEC = 186;
string nameList[] = { "Ahmet", "Osman", "Ali", "Mehmet", "Veli", "Sarp", "Emrah", "Eser", "Erbil", "Oguz", "Can", "Murat", "Sinan", "Mert", "Mete", "Sait", "Ervah", "Cihat", "Orhan", "Fatih", "Ahu", "Binnur", "Bilge", "Candan", "Cahide", "Demet", "Deste", "Gizem", "Ece", "Elanur", "Fatma", "Fidan", "Gamze", "Hale", "Hilal", "Irmak", "Jale", "Kader", "Kamile", "Lale" };
string surnameList[] = { "KANDEMIR", "ORHON", "VURAL", "YAVUZ", "UZ", "ERDEM", "DEDE", "UYANIK", "ASLAN", "ERKURAN", "ER", "DAL", "KARAKUM", "YILMAZ", "TAHTACI", "KAYA", "ERGE", "ONUK", "TOPAL", "BEDER" };

Control controlC;

Customer::Customer(){
}

void Customer::addCustomer(){
	srand(time(NULL));
	//Date cDate;

	int nameIndex = rand() % 40;
	int surnameIndex = rand() % 20;

	cName = nameList[nameIndex];
	cSurname = surnameList[surnameIndex];

	cTrNo = generateTrNo();
	cTelNo = generateTelNo();
	BrithDate = randDate[nameIndex].getDate();

	controlC.printCeiling(20);
	controlC.printIntermediate(20, " Added Customer");
	controlC.printSeparatrix(20);
	controlC.printIntermediate(20, " Name: " + getName());
	controlC.printIntermediate(20, " Surname: " + getSurname());
	controlC.printIntermediate(20, " Tel No: " + getTelNo());
	controlC.printIntermediate(20, " T.R No: " + getTrNo());
	controlC.printIntermediate(20, " Date: " + BrithDate);
	controlC.printBottom(20);
	saveCustomer();
	
}
void Customer::deleteCustomer(){
	listCustomers();
	cout << "tr:";
	string tr;
	cin >> tr;
	removeCustomer(tr);
}
void Customer::listCustomers(){
	controlC.printCeiling(40);
	controlC.printIntermediate(40, " Customers");
	controlC.printSeparatrix(40);
	readCustomer();
	controlC.printBottom(40);
}

void Customer::saveCustomer(){
	fstream save;

	save.open("Customers.txt", fstream::in | fstream::out | fstream::app);

	if (save.is_open() == true){
		save << getName() << " " << getSurname() << " " << getTrNo() << " " << getTelNo() << " " << BrithDate << endl;
	}
	
	save.close();
}
void Customer::readCustomer(){
	fstream read;
	read.open("Customers.txt", fstream::in);
	if (read.is_open() == true){
		string customerName, customerSurname, customerTrNo, customerTelNo;
		string LineC;
		while (read >> customerName >> customerSurname >> customerTrNo >> customerTelNo >> BrithDate){
			LineC = customerName + " " + customerSurname + " " + customerTrNo + " " + customerTelNo + " " + BrithDate;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEC;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << std::left << setw(40) << LineC;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEC << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		
	}
	read.close();
}
void Customer::removeCustomer(string tr){
	fstream temp, customers;

	customers.open("Customers.txt", fstream::in | fstream::out | fstream::app);
	temp.open("temp.txt", fstream::in | fstream::out | fstream::app);

	if (customers.is_open() == true){
		string customerName, customerSurname, customerTrNo, customerTelNo;
		string satir;
		while (customers >> customerName >> customerSurname >> customerTrNo >> customerTelNo >> BrithDate){
			if (customerTrNo != tr){
				temp << customerName << " " << customerSurname << " " << customerTrNo << " " << customerTelNo << BrithDate << endl;
			}
		}
	}
	customers.close();
	temp.close();
	remove("Customers.txt");
	rename("temp.txt", "Customers.txt");
	system("cls");
	listCustomers();
}

void Customer::setName(string name){
	cName = name;
}
void Customer::setSurname(string surname){
	cSurname = surname;
}
void Customer::setTelNo(string telno){
	cTelNo = telno;
}
void Customer::setTrNo(string trno){
	cTrNo = trno;
}

string Customer::getName(){
	return cName;
}
string Customer::getSurname(){
	return cSurname;
}
string Customer::getTelNo(){
	return cTelNo;
}
string Customer::getTrNo(){
	return cTrNo;
}
Date Customer::getDate(){
	return cDate;
}

string Customer::generateTrNo(){
	string trNo = "";
	for (int i = 0; i < 4; i++){
		trNo += '1' + rand() % 9;
	}
	return trNo;
}
string Customer::generateTelNo(){
	string telNo = "";
	for (int i = 0; i < 10; i++){
		telNo += '0' + rand() % 10;
	}
	return telNo;
}
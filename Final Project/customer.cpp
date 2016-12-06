#include "customer.h"
#include <fstream>

using namespace std;

string isimlerListesi[] = { "Ahmet", "Osman", "Ali", "Mehmet", "Veli", "Sarp", "Emrah", "Eser", "Erbil", "Oguz", "Can", "Murat", "Sinan", "Mert", "Mete", "Sait", "Ervah", "Cihat", "Orhan", "Fatih", "Ahu", "Binnur", "Bilge", "Candan", "Cahide", "Demet", "Deste", "Gizem", "Ece", "Elanur", "Fatma", "Fidan", "Gamze", "Hale", "Hilal", "Irmak", "Jale", "Kader", "Kamile", "Lale" };
string soyisimlerListesi[] = { "KANDEMIR", "ORHON", "VURAL", "YAVUZ", "UZ", "ERDEM", "DEDE", "UYANIK", "ASLAN", "ERKURAN", "ER", "DAL", "KARAKUM", "YILMAZ", "TAHTACI", "KAYA", "ERGE", "ONUK", "TOPAL", "BEDER" };


Customer::Customer(){
	srand(time(NULL));

	int nameIndex = rand() % 40;
	int surnameIndex = rand() % 20;

	cName = isimlerListesi[nameIndex];
	cSurname = soyisimlerListesi[surnameIndex];

	cTrNo = generateTrNo();
	cTelNo = generateTelNo();
}

void Customer::save(){
	fstream save;

	save.open("Customers.txt", fstream::in | fstream::out | fstream::app);

	if (save.is_open() == true){
		save << getName() << " " << getSurname() << " " << getTrNo() << " " << getTelNo() << endl;
	}

	save.close();
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
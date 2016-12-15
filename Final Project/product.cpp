#include "product.h"
#include "control.h"
#include "fstream"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <Windows.h>
#include <time.h>

//function descriptions has been explained in header files
using namespace std;
char STRAIGHTLINEP = 186;

string productList[] = { "VideoCart", "SoundCart", "Proccessor", "Keyboard", "Mouse", "Monitor", "Ram", "Harddisk", "LoudSpeaker", "SSDDisk", "Notebook", "Case", "FlashDisk", "Tablet", "MobilePhone", "Earphones", "Printer", "Scanner", "OptikScanner", "TvCart" };
string  priceList[20] = { "560", "50", "500", "80", "30", "400", "120", "260", "250", "460", "1500", "100", "30", "700", "1200", "50", "350", "360", "200", "130" };

Control controlP;

Product::Product(){
	
}

void Product::saveProduct(){
	fstream save; //create variable as type of 'fstream' to save changes

	save.open("Products.txt", fstream::in | fstream::out | fstream::app); //create txt file 

	if (save.is_open() == true){ //if txt file is open
		save << getPName() << " " << getPCode() << " " << getPrice() << "TL" << endl;
	}

	save.close(); //close txt file
}
void Product::readProduct(){
	fstream read; //create variable as type of 'fstream' to read changes

	read.open("Products.txt", fstream::in);

	if (read.is_open() == true){
		string productName, productCode, productPrice;
		string LineP;
		while (read >> productName >> productCode >> productPrice){ //if current line is not at end of the file
			LineP = productName + " " + productCode + " " + productPrice;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEP;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << std::left << setw(40) << LineP;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << STRAIGHTLINEP << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	read.close();
}
void Product::removeProduct(string pcode){
	fstream products, tempP;

	products.open("Products.txt", fstream::in | fstream::out | fstream::app);
	tempP.open("tempP.txt", fstream::in | fstream::out | fstream::app);

	if (products.is_open() == true){
		string productName, productCode, Price;
		string satir;
		while (products >> productName >> productCode >> Price){
			if (productCode != pcode){
				tempP << productName << " " << productCode << " " << Price << endl;
			}
		}
	}
	products.close();
	tempP.close();
	remove("Products.txt");
	rename("tempP.txt", "Products.txt");
	system("cls");
	listProducts();
}

void Product::addProduct(){
	srand(time(NULL));
	int product_index = rand() % 20;

	cPName = productList[product_index];
	cPrice = priceList[product_index];
	cPCode = generateCode();

	controlP.printCeiling(20);
	controlP.printIntermediate(20, " Added Customer");
	controlP.printSeparatrix(20);
	controlP.printIntermediate(20, " Name: " + getPName());
	controlP.printIntermediate(20, " Code: " + getPCode());
	controlP.printIntermediate(20, " Price: " + getPrice() + "TL");
	controlP.printBottom(20);
	saveProduct();
}
void Product::listProducts(){
	controlP.printCeiling(40);
	controlP.printIntermediate(40, " Products");
	controlP.printSeparatrix(40);
	readProduct();
	controlP.printBottom(40);
}
void Product::deleteProduct(){
	listProducts();
	cout << "Enter Product code to delete: ";
	string pc;
	cin >> pc;
	removeProduct(pc);
}

void Product::setPName(string pName){
	cPName = pName;
}
void Product::setPCode(string pCode){
	cPCode = pCode;
}
void Product::setPrice(int pPrice){
	cPrice = pPrice;
}

string Product::getPCode(){
	return cPCode;
}
string Product::getPName(){
	return cPName;
}
string Product::getPrice(){
	return cPrice;
}

string Product::generateCode(){
	string pCode = "";
	for (int i = 0; i < 4; i++){
		pCode += '1' + rand() % 9;
	}
	return pCode;
}
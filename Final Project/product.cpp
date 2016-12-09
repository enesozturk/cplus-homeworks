#include "product.h"
#include <iostream>
#include "fstream"
#include "control.h"
#include <time.h>

using namespace std;
string productList[] = { "Video Cart", "Sound Cart", "Proccessor", "Keyboard", "Mouse", "Monitor", "Ram", "Harddisk", "Loud Speaker", "SSD Disk", "Notebook", "Case", "Flash Disk", "Tablet", "Mobile Phone", "Earphones", "Printer", "Scanner", "Optik Scanner", "Tv Cart" };
int  priceList[20] = { 560, 50, 500, 80, 30, 400, 120, 260, 250, 460, 1500, 100, 30, 700, 1200, 50, 350, 360, 200, 130 };

Kontrol controlP;

Product::Product(){
	
}
void Product::save(){
	fstream save;

	save.open("Products.txt", fstream::in | fstream::out | fstream::app);

	if (save.is_open() == true){
		save << getPName() << " " << getPCode() << " " << getPrice() << "TL" << endl;
	}

	save.close();
}

void Product::addProduct(){
	srand(time(NULL));
	int product_index = rand() % 20;

	cPName = productList[product_index];
	cPrice = priceList[product_index];
	cPCode = generateCode();

	controlP.tavanCiz(20);
	controlP.araCiz(20, " Added Customer");
	controlP.ayracCiz(20);
	controlP.araCiz(20, " Name: " + getPName());
	controlP.araCiz(20, " Code: " + getPCode());
	controlP.araCiz(20, " Price: " + getPrice());
	controlP.zeminCiz(20);
	save();
}
void Product::deleteProduct(int no){

}
void Product::listProducts(){
	controlP.tavanCiz(40);
	controlP.araCiz(40, " Products");
	controlP.ayracCiz(40);
	controlP.araCiz(40, getPName() + " " + getPCode());
	controlP.zeminCiz(40);
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
int Product::getPrice(){
	return cPrice;
}

string Product::generateCode(){
	string pCode = "";
	for (int i = 0; i < 4; i++){
		pCode += '1' + rand() % 9;
	}
	return pCode;
}
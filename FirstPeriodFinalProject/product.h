#pragma once
#include<string>
using namespace std;

class Product
{
public:
	Product(); //constructor

	void saveProduct(); //save product to txt file
	void readProduct(); //read product from txt file 
	void removeProduct(string pcode); //remove product from txt file

	string	getPName(); //get functions
	string	getPCode();
	string	getPrice();

	void listProducts(); //print list of products to screen
	void addProduct();  //add product and display it
	void deleteProduct(); //delete product from txt file

	void setPName(string pName); //set functions
	void setPCode(string pCode);

	void setPrice(int price);

	string generateCode(); //generate random product code
private:
	string cPCode; //variables decralations
	string cPName;
	string cPrice;
};

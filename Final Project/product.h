#pragma once
#include<string>
using namespace std;

class Product
{
public:
	Product();

	void	save();

	string	getPName();
	string	getPCode();
	int		getPrice();

	void listProducts();
	void addProduct();
	void deleteProduct(int productCode);

	void	setPName(string pName);
	void	setPCode(string pCode);

	void	setPrice(int price);

	string	generateCode();
private:

	string	cPCode;
	string	cPName;
	int		cPrice;
};

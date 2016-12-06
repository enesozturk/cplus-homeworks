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

	void	setPName(string pName);
	void	setPCode(string pCode);

	void	setPrice(int price);

	string	generateCode();
private:

	string	cPCode;
	string	cPName;
	int		cPrice;
};

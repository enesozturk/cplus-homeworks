#include "control.h"
#include "process.h"
#include "product.h"
#include "customer.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

char DUZCIZGI = 205;
char SOLUSTKOSE = 201;
char SAGUSTKOSE = 187;
char DIKEYCIZGI = 186;
char ASAGIAYRAC = 203;
char SOLALTKOSE = 200;
char SAGALTKOSE = 188;
char YUKARIAYRAC = 202;
char YATAYSAGAAYRAC = 204; //
char YATAYSOLAAYRAC = 185;

Product p2;
Islem pr2;
Customer c2;

enum RENKLER
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
void renkAta(int yazirenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void karakterCikar(char karakter, RENKLER renk)
{
	renkAta(renk);
	cout << karakter;
	renkAta(WHITE);
}

void Kontrol::tavanCiz(int genislik)
{
	cout << SOLUSTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGUSTKOSE;

	cout << endl;

}
void Kontrol::zeminCiz(int genislik)
{
	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
}
void Kontrol::araCiz(int genislik, string yazi)
{
	cout << DIKEYCIZGI;

	cout << std::left << setw(genislik) << yazi;

	cout << DIKEYCIZGI;
	cout << endl;
}
void Kontrol::ayracCiz(int genislik)
{
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
}
int Kontrol::anaMenuCiz(int a)
{
	tavanCiz(a);
	araCiz(a, " Main Control Panel");
	ayracCiz(a);
	araCiz(a, " 1.Customer Panel");
	araCiz(a, " 2.Admin Panel");
	araCiz(a, " 3.Exit");
	zeminCiz(a);
	return 0;
}

void Kontrol::musteriMenuCiz()
{
	c2.listCustomers();
	tavanCiz(20);
	araCiz(20, " Customer Panel");
	ayracCiz(20);
	araCiz(20, " 1.Buy Product");
	araCiz(20, " 2.List Processes");
	araCiz(20, " 3.Delete Process");
	araCiz(20, " 4.Back");
	zeminCiz(20);
	int mSecim;
	cout << "Secim: ";
	cin >> mSecim;
	switch (mSecim)
	{
	case 1:
		int uCode;
		p2.listProducts();
		cout << "Urun kodu girin: ";
		cin >> uCode;
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

void Kontrol::yoneticiMenuCiz()
{
	tavanCiz(20);
	araCiz(20, " Admin Panel");
	ayracCiz(20);
	araCiz(20, " 1.Add Customer");
	araCiz(20, " 2.List Customers");
	araCiz(20, " 3.Delete Customer");
	araCiz(20, " 4.Add Product");
	araCiz(20, " 5.List Products");
	araCiz(20, " 6.Delete Products");
	araCiz(20, " 7.Back");
	zeminCiz(20);
	int yoneticiSecim;
	cout << "Secim: ";
	cin >> yoneticiSecim;
	switch (yoneticiSecim)
	{
	case 1:
		c2.addCustomer();
		break;
	case 2:
		c2.listCustomers();
		break;
	case 3:
		// musteri silinecek
		break;
	case 4:
		p2.addProduct();
		break; 
	case 5:
		p2.listProducts();
		break;
	case 6:
		//urun silinecek
		break;
	default:
		break;
	}
}

#include "control.h"
#include "product.h"
#include "process.h"
#include "customer.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

//function descriptions has been explained in header files
using namespace std;

char STRAIGHTLINE = 205;
char LEFTTOPCORNER = 201;
char RIGHTTOPCORNER = 187;
char VERTICALLINE = 186;
char DOWNSEPARATRIX = 203;
char LEFTBOTTOMCORNER = 200;
char RIGHTBOTTOMCORNER = 188;
char UPSEPARATRIX = 202;
char HORIZONTALRIGHTSEP = 204; 
char HORIZONTALLEFTSEP = 185;

Product productC;
Process processC;
Customer customerC;

enum COLORS
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

//Assinging color for table lines
void assignColor(int textColor)
{
	int backgroundColor = 0;

	int lastColor;

	lastColor = (16 * backgroundColor) + textColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
}
void printCharacter(char character, COLORS color)
{
	assignColor(color);
	cout << character;
	assignColor(WHITE);

}

//Printing lines to make table
void Control::printCeiling(int w)
{
	printCharacter(LEFTTOPCORNER,LIGHTBLUE);

	for (int i = 0; i < w; i++)
		printCharacter(STRAIGHTLINE, LIGHTBLUE);

	printCharacter(RIGHTTOPCORNER, LIGHTBLUE);

	cout << endl;

}
void Control::printIntermediate(int w, string text)
{
	printCharacter(VERTICALLINE, LIGHTBLUE);
		
	cout << std::left << setw(w) << text;

	printCharacter(VERTICALLINE, LIGHTBLUE);
	cout << endl;
}
void Control::printIntermediate(int w)
{
	printCharacter(VERTICALLINE, LIGHTBLUE);

	cout << std::left;
	customerC.readCustomer();
	printCharacter(VERTICALLINE, LIGHTBLUE);

	cout << endl;
}
void Control::printSeparatrix(int w)
{
	printCharacter(HORIZONTALRIGHTSEP, LIGHTBLUE);

	for (int i = 0; i < w; i++)
		printCharacter(STRAIGHTLINE, LIGHTBLUE);

	printCharacter(HORIZONTALLEFTSEP, LIGHTBLUE);

	cout << endl;
}
void Control::printBottom(int w)
{
	printCharacter(LEFTBOTTOMCORNER, LIGHTBLUE);

	for (int i = 0; i < w; i++)
		printCharacter(STRAIGHTLINE, LIGHTBLUE);

	printCharacter(RIGHTBOTTOMCORNER, LIGHTBLUE);

	cout << endl;
}

//When program is finish, ask user to continue or not
void Control::askToContinue(){
	cout << "Do you want to return main menu? (Y/N): ";
	char YN;
	cin >> YN;
	if (YN == 'y' || YN == 'Y'){
		system("cls");
		printMainMenu();
	}
} 

int Control::printMainMenu()
{
	int mainMenuSelection;
	printCeiling(20);
	printIntermediate(20, " Main Control Panel");
	printSeparatrix(20);
	printIntermediate(20, " 1.Customer Panel");
	printIntermediate(20, " 2.Admin Panel");
	printIntermediate(20, " 3.Exit");
	printBottom(20);
	cout << "Selection: ";
	cin >> mainMenuSelection;
	switch (mainMenuSelection) //user selection with switch-case loop to choose process
	{
	case 1:
		printCustomerMenu();
		break;
	case 2:
		printAdminMenu();
		break;
	case 3:
		break;
	default:
		cout << "It's different than the selections!" << endl;
		askToContinue();
		break;
	}
	return 0;
}
void Control::printCustomerMenu()
{
	customerC.listCustomers();
	processC.bringTrNo();
	printCeiling(20);
	printIntermediate(20, " Customer Panel");
	printSeparatrix(20);
	printIntermediate(20, " 1.Buy Product");
	printIntermediate(20, " 2.List Processes");
	printIntermediate(20, " 3.Delete Process");
	printIntermediate(20, " 4.Back");
	printBottom(20);
	int customerMenuSelection;
	cout << "Selection: ";
	cin >> customerMenuSelection;
	switch (customerMenuSelection) //user selection with switch-case loop to choose process
	{
	case 1:
		productC.listProducts();
		processC.bringProductCode();
		processC.saveProcess();
		cout << "Saved.." << endl;
		askToContinue();
		break;
	case 2:
		processC.listProcesses();
		askToContinue();
		break;
	case 3:
		processC.deleteProcess();
		break;
	case 4:
		system("cls");
		printMainMenu();
		break;
	default:
		break;
	}
}
void Control::printAdminMenu()
{
	printCeiling(20);
	printIntermediate(20, " Admin Panel");
	printSeparatrix(20);
	printIntermediate(20, " 1.Add Customer");
	printIntermediate(20, " 2.List Customers");
	printIntermediate(20, " 3.Delete Customer");
	printIntermediate(20, " 4.Add Product");
	printIntermediate(20, " 5.List Products");
	printIntermediate(20, " 6.Delete Products");
	printIntermediate(20, " 7.Back");
	printBottom(20);
	int adminMenuSelection;
	cout << "Selection: ";
	cin >> adminMenuSelection;
	switch (adminMenuSelection) //user selection with switch-case loop to choose process
	{
	case 1:
		customerC.addCustomer();
		askToContinue();
		break;
	case 2:
		customerC.listCustomers();
		askToContinue();
		break;
	case 3:
		customerC.deleteCustomer();
		askToContinue();
		break;
	case 4:
		productC.addProduct();
		askToContinue();
		break; 
	case 5:
		productC.listProducts();
		askToContinue();
		break;
	case 6:
		productC.deleteProduct();
		askToContinue();
		break;
	case 7:
		system("cls");
		printMainMenu();
		break;
	default:
		break;
	}
}
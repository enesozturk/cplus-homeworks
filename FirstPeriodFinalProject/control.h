#pragma once
#include <string>

using namespace std;

class Control
{
public:

	void printCeiling(int width); //function that prints ceiling of box
	void printBottom(int width); //function that prints bottom lines of box
	void printIntermediate(int width, string text); //function that prints intermediate lines of box
	void printIntermediate(int width); //overrided function
	void printSeparatrix(int width); //function that prints separatrixes of box

	void askToContinue(); //ask user to continue or not

	int  printMainMenu(); //print main menu function

	void printCustomerMenu(); //print customer menu function

	void printAdminMenu(); //print admin menu function

};
//An animation with C++,we will build a array with given character and array length then a moving character will go to end of the array one by one then head back to start point and head back again and so on. 
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
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
void assingColor(int fontColor) //define a color from COLORS type to chosen character
{
	int bacgColor = 0;

	int lastColor;

	lastColor = (16 * bacgColor) + fontColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
}
void giveCharacter(char character, COLORS renk) //print the 'karakter' parameter chosen by user and define the chosen color
{
	assingColor(renk);
	cout << character;
	assingColor(WHITE);
}

int main()
{
	
	int index = 1; // index is out moving character
	char charArray[100];
	int characterNumber=0;

	char mycharacter;
	cout << "Enter the character(1-100).................:";
	cin >> mycharacter;
	
	int lengthOfArray;
	do{
		cout << "Length of the Array(1-100)................:";
		cin >> lengthOfArray;
	} while (lengthOfArray < 1 || lengthOfArray > 100); //if length of the array is less than 1 or greater than 100, ask him again

	int speedUser, speedProgram;
	do{
		cout << "Speed of the Animation(1-10).............:"; //if speed of the animation is less than 1 or greater than 10, ask him again
		cin >> speedUser;
	} while (speedUser < 1 || speedUser > 11);

	speedProgram = speedUser * 100;

	for (int j = 0; j < lengthOfArray; j++){ //fill all the chosen array indexes by chosen character
		charArray[j] = mycharacter;
	}

	for (int i = 0; i < lengthOfArray; i++){
		charArray[i] = mycharacter;
	}
	
	while (true)
	{
		system("cls");

		for (int i = 0; i<lengthOfArray; i++) //execute the codes that in the for loop from i=1 to i<=lengthOfArray
		{
			if (index == i){ //if index is equal to 'i'
				charArray[i] = '>';
				giveCharacter(charArray[index], YELLOW);
				charArray[i] = mycharacter;
			}
				
			else{ //otherwise execute this code
				giveCharacter(charArray[i], BLUE);
			}
				
		}
		
		index++;

		if (index == lengthOfArray){ //if index is equal to lengthOfArray, that mean if index is in the end of the array.
			
			while (index >= 1){ //if index is greater than 
				system("cls");

				for (int i = 0; i < lengthOfArray; i++) //execute the codes below that from i=1 to i=lengthOfArray.
				{
					if(index == i){ //if index equal to 'i' variable
						charArray[i] = '<';
						giveCharacter(charArray[index], YELLOW);
						charArray[i] = mycharacter;
					}
					else //otherwise
						giveCharacter(charArray[i], BLUE);
				}
				index--;
				_sleep(speedProgram);
			}
		}
		_sleep(speedProgram);
	}
}

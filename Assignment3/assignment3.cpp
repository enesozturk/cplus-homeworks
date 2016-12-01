#include <iostream>
#include <cstdlib>
#include <time.h>
#include<string>
#include<Windows.h>
#define MAX 100

using namespace std;

enum COLORS { //Some special colors
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14
};
const char SOLIDLINE = 205;  //Define special ASCII characters to print a cell box
const char LEFTTOPCORNER = 201;
const char RIGHTTOPCORNER = 187;
const char VERTICALLINE = 186;
const char DOWNSEPARATRIX = 203;
const char LEFTBOTTOMCORNER = 200;
const char RIGHTBOTTOMCORNER = 188;
const char UPSEPARATRIX = 202;

class Cell{  //Class that contain properties for all cells created.
public:
	char character;
	int color;
	int number;
	Cell(){ //Constuctor will be executed for every object that created from this class.
		character = (rand() % 26) + 65;
		number = rand() % 9;
		color = (rand() % 6) + 9;
	}
};

class Array{ //Class that contains events that add or remove cell from the array.
private:
	int numberOfCells;
	Cell cells[MAX];
	Cell randC;
public:
	int index;
	Array(){ //When the Array class object created, this constuctor will be executed.
		numberOfCells = 0;
	}
	void addCell(){
		numberOfCells++;
		index = rand() % (numberOfCells);
		for (int i = MAX; i > index; i--){ //Shifting array to add new value to chosen index;
			cells[i] = cells[i - 1];
		}
		cells[index] = randC; //Add random values to shifted place.
	}
	void removeCell(){
		if (numberOfCells == 0){ //If number of cells equal to zero, print this.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "There is no cell.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else{ //Otherwise curtail the array

			index = rand() % (numberOfCells);
			for (int j = index; j < numberOfCells; j++){ //Add all the objects on chosen index to remove it
				cells[j] = cells[j + 1];
			}
			numberOfCells--;
		}
	}
	void print(){
		if (numberOfCells == 1){ //If numberOfCells equal to 1 print only one box
			cout << LEFTTOPCORNER << SOLIDLINE << SOLIDLINE << SOLIDLINE << RIGHTTOPCORNER << endl;
			cout << VERTICALLINE << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[0].color);
			cout << cells[0].number;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " " << VERTICALLINE << endl;
			cout << VERTICALLINE << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[0].color);
			cout << cells[0].character;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " " << VERTICALLINE << endl;
			cout << LEFTBOTTOMCORNER << SOLIDLINE << SOLIDLINE << SOLIDLINE << RIGHTBOTTOMCORNER << endl;;
		}if (numberOfCells == 0){ //If number of cells is equal to zero, print this.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "There is nothing to show you!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		if (numberOfCells>1){ //Otherwise do these.
			for (int i = 0; i < numberOfCells; i++){ // Print first line of array of objects.
				if (i == 0){
					cout << LEFTTOPCORNER << SOLIDLINE << SOLIDLINE << SOLIDLINE;
				}
				if (i>0 && i<numberOfCells - 1){
					cout << DOWNSEPARATRIX << SOLIDLINE << SOLIDLINE << SOLIDLINE;
				}
				if (i == numberOfCells - 1){
					cout << DOWNSEPARATRIX << SOLIDLINE << SOLIDLINE << SOLIDLINE << RIGHTTOPCORNER;
				}
			}
			cout << endl;
			for (int i = 0; i < numberOfCells; i++){ //Print second line of the array.
				if (i == 0){
					cout << VERTICALLINE << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[i].color);
					cout << cells[i].number;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << " " << VERTICALLINE;
				}
				else{
					cout << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[i].color);
					cout << cells[i].number;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << " " << VERTICALLINE;
				}
			}
			cout << endl;
			for (int i = 0; i < numberOfCells; i++){ //Print third line of the array.
				if (i == 0){
					cout << VERTICALLINE << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[i].color);
					cout << cells[i].character;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << " " << VERTICALLINE;
				}
				else{
					cout << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cells[i].color);
					cout << cells[i].character;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << " " << VERTICALLINE;
				}
			}
			cout << endl;
			for (int i = 0; i < numberOfCells; i++){ //Print last line of array.
				if (i == 0){
					cout << LEFTBOTTOMCORNER << SOLIDLINE << SOLIDLINE << SOLIDLINE << UPSEPARATRIX;
				}
				if (i>0 && i<numberOfCells - 1){
					cout << SOLIDLINE << SOLIDLINE << SOLIDLINE << UPSEPARATRIX;
				}
				if (i == numberOfCells - 1){
					cout << SOLIDLINE << SOLIDLINE << SOLIDLINE << RIGHTBOTTOMCORNER << endl;
				}
			}
		}
	}
};


int main(){
	srand(time(NULL));
	int choise;
	Array a1;

	do{ //Do these commands, if while query is true do them again.
		cout << "1.Add Cell" << endl;
		cout << "2.Remove Cell" << endl;
		cout << "3.Exit" << endl;
		cout << "Choise:";
		cin >> choise;

		switch (choise){ //User will make a choise to add or remove a cell from array
		case 1:
			cout << "Chosen Index:";
			a1.addCell();
			cout << a1.index << endl;
			a1.print();
			break;
		case 2:
			a1.removeCell();
			cout << "Chosen Index: ";
			cout << a1.index << endl;
			a1.print();
			break;
		case 3:
			system("pause");
			return 0;
			break;
		default: cout << "Your choise is different than 1,2 or 3. Try again:";
		}
	} while (true); //Query is true to make it infinite.

	return 0;
}



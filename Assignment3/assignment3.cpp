/****************************************************************************
** SAKARYA ÜNIVERSITESI
** BILGISAYAR VE BILISIM BILIMLERI FAKÜLTESI
** BILGISAYAR MÜHENDISLIGI BÖLÜMÜ
** PROGRAMLAMAYA GIRISI DERSI
**
** ÖGRENCI ADI......:Enes Öztürk
** ÖGRENCI NUMARASI.:G151210022
** DERS GRUBU…………………:B Grubu
****************************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include<string>
#include<Windows.h>
#define MAX 100

using namespace std;

enum COLORS {
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14
};
const char SOLIDLINE = 205;
const char LEFTTOPCORNER = 201;
const char RIGHTTOPCORNER = 187;
const char VERTICALLINE = 186;
const char DOWNSEPARATRIX = 203;
const char LEFTBOTTOMCORNER = 200;
const char RIGHTBOTTOMCORNER = 188;
const char UPSEPARATRIX = 202;

class Cell{  //Class that contain properties for all cells created;
public:
	char character;
	int color;
	int number;
	Cell(){
		character = rand() % (90 - 65 + 1) + 65;
		number = rand() % 9;
		color = rand() % (14 - 9 + 1) + 9;
	}
};

class Array{ //Class that contains events that add or remove cell from the array 
private:
	int numberOfCells;
	Cell cells[MAX];
	Cell x;
public:
	int index;
	Array(){
		numberOfCells = 0;
	}
	void addCell(){
		numberOfCells++;
		index = rand() % (numberOfCells);
		for (int i = MAX; i > index; i--){ //Shifting array to add new value to chosen index;
			cells[i] = cells[i - 1];
		}
		cells[index] = x;
	}
	void removeCell(){
		
		index = rand() % (numberOfCells);
		for (int j = index; j < MAX; j++){ //Add all the objects on chosen index to remove it
			cells[j] = cells[j + 1];
		}
		numberOfCells--;
		
	}
	void print(){
		if(numberOfCells==1){ //if numberOfCells equal to 1 print only one box
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
		}
		else{ //otherwise do these
			for (int i = 0; i < numberOfCells; i++){ // print first line of array of objects
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
			for (int i = 0; i < numberOfCells; i++){ //second line
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
			for (int i = 0; i < numberOfCells; i++){ //third line
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
			for (int i = 0; i < numberOfCells; i++){ //last line of array
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
	
	do{
		cout << "1.Add Cell" << endl;
		cout << "2.Remove Cell" << endl;
		cout << "3.Exit" << endl;
		cout << "Choise:";
		cin >> choise;
		
		
		switch (choise){ //User will make a choise to add or remove a cell from array
		case 1:
			cout << "Added Cell. Chosen Index:";
			a1.addCell();
			cout  << a1.index << endl;
			a1.print();
			break;
		case 2:
			cout << "Cell deleted in ";
			a1.removeCell();
			cout << a1.index <<". index." << endl;
			a1.print();
			break;
		case 3:
			break;
		default: cout << "Your choise is different than 1,2 or 3. Try again:";
		}
	} while (true); //infinite loop

	return 0;
}



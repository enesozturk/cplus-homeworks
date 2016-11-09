//We will build two rectangle with given width and height values. In second rectangle width will be height and height will be width.
#include <iostream>

using namespace std;

int main(){
	int width, height;

	cout << "Width....(1-20): ";
	cin >> width;
	cout << "Height...(1-20): ";
	cin >> height;
	
	while(width<0 || width>20 || height<0 || height>20){
		cout << "Your width and height values must be in 1-50!" << endl;
		cout << "Width....(1-20): ";
		cin >> width;
		cout << "Height...(1-20): ";
		cin >> height;
	}
	
	for (int i = 1; i <= width; i++){ //Write asteriks' from 1 to value of width.
		cout << "* ";

		if (i == width){ //If variable 'i' equal to width value, run events below.
			cout << endl;

			for (int j = 2; j < height; j++){ //Write asteriks' from 2 to value of height, and run events below.
				cout << "* ";

				for (int k = 2; k < width; k++){ //Write a space from 2 to value of width.
					cout << "  ";
				}

				cout << "* " << endl;
			}
			for (int l = 0; l < width; l++){ //Write lastly asteriks' from 0 to value of width.
				cout << "* ";
			}
		}
	}
	cout << endl << endl;
	for (int i = 1; i <= height; i++){ //Write asteriks' from 1 to value of height.
		cout << "* ";

		if (i == height){ //If variable 'i' equal to height value, run events below.
			cout << endl;

			for (int j = 2; j < width; j++){ //Write asteriks' from 2 to value of width, and run events below.
				cout << "* ";

				for (int k = 2; k < height; k++){ //Write a space from 2 to value of height.
					cout << "  ";
				}

				cout << "* " << endl;
			}
			for (int l = 0; l < height; l++){ //Write lastly asteriks' from 0 to value of height.
				cout << "* ";
			}
		}
	}

	

	cout << endl;
	system("pause");
	return 0;
}
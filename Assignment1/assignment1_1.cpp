//We will find odd numbers from a given number from the left to right.
#include <iostream>

using namespace std;

int main(){

	int number;
	int divisor = 10;
	int quotient, remainder;

	cout << "Enter a number => ";
	cin >> number;

	while (number > divisor){ //If the number (division) is larger than divisor, multiply divisor with 10.
		divisor *= 10;
	}
	
	cout << "Odd numbers => ";
	while (number > 0){ //When number is greater than 0. It means go all the way until the number is 0.

		quotient = number / divisor;
		remainder = number % divisor;
		number = remainder;

		if (quotient % 2 != 0){ //If the module according to claim 2 of the number is not equal to 0.
			cout << quotient << " ";
		}

		divisor = divisor / 10;
	}

	system("pause");
	return 0;
}
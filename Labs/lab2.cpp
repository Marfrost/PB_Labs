#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

int Lab2() {
	//Варіант 20


	double an;
	cout << "Enter a3: ";
	cin >> an;
	
	double r = an / sqrt(3.0);

	for (int i = 3; i < 48; i *= 2) {
		an = sqrt(2 * pow(r, 2) - 2 * r * sqrt(pow(r, 2) - pow(an, 2) / 4));
	}

	cout << "48-gon side lenght: " << an << endl;
	return 0;
}
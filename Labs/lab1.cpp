#include "stdio.h"
#include <iostream>
#include <conio.h>

using namespace std;

int Lab1() {

	double x, y;

	cout << "Enter X: ";
	cin >> x;

	if (x < 0) {
		y = 0;
	}
	else if (x <= 2) {
		y = x*x + 5;
	}
	else {
		y = 1.0 / (x*x + 5);
	}


	cout << "F(x)= " << y << endl;

	cout << "Enter X: ";
	cin >> x;
	cout << "Enter Y: ";
	cin >> y;

	if (x >= -1 && y>-1 && x <= 1 && y <= 1) {
		cout << "Point ( " << x << " ; " << y << " ) is inside the area" << endl;
	}
	else {
		cout << "Point ( " << x << " ; " << y << " ) is outside the area" << endl;
	}

	_getch();

	return 0;
}



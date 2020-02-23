#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

int Lab1() {
	
	/*Вариант 13
	*		{0			,x<0
	* f(x)=	{x^2+5		,0<=x<=2
	*		{1/(x^2 +5)	,x>2
	*/
	double x, y;

	cout << "Task 1"<<endl;
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
	/*
	*
	*Квадрат, центр в (0,0), грани по x=+-1 y=+-1
	*
	*/
	cout << "Task 2" << endl;
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

	return 0;
}



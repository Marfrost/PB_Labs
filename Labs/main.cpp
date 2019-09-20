#include <iostream>
#include "stdio.h"
#include <conio.h>

#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

using namespace std;

int main() {

	int no=0;
	cout << "Enter lab no: ";
	cin >> no;
	
	switch (no)
	{
		case 1: Lab1(); break;
		case 2: Lab2(); break;
		case 3: Lab3(); break;
		default: {
			cout << "Missing lab with no " << no;
		}
		break;
	}



	_getch();
	return 0;
}
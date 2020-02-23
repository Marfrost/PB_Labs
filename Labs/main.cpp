#include <iostream>
#include "stdio.h"
#include <conio.h>

#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"

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
		case 4: Lab4(); break;
		case 5: Lab5(); break;
		default: {
			cout << "Missing lab with no " << no;
		}
		break;
	}


	cout << endl << "Press any key to exit..." << endl;
	_getch();
	return 0;
}
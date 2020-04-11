#include <iostream>
#include "stdio.h"
#include <conio.h>

#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"
#include "lab8.h"
#include "lab9.h"
#include "lab10.h"

using namespace std;

int main() {


	int semester = 0, lab = 1;
	cout << "Enter semester: ";
	cin >> semester;

	if (semester < 1 || semester >2) {
		cout << "Invalid semester number. Values 1 and 2 are available.";
	}

	cout << "Enter lab no: ";
	cin >> lab;
	


	switch ((semester-1)*5 + lab)
	{
		case 1: Lab1(); break;
		case 2: Lab2(); break;
		case 3: Lab3(); break;
		case 4: Lab4(); break;
		case 5: Lab5(); break;
		case 6: Lab6(); break;
		case 7: Lab7(); break;
		case 8: Lab8(); break;
		case 9: Lab9(); break;
		defalt: {
			cout << "Missing lab with no " << lab << " for semester " << semester;
		}
		break;
	}


	cout << endl << "Press any key to exit..." << endl;
	_getch();
	return 0;
}
#include <iostream>
#include "stdio.h"
#include <conio.h>

#include "lab1.h"

using namespace std;

int main() {

	int no=0;
	cout << "Enter lab no: ";
	cin >> no;
	
	switch (no)
	{
		case 1: return Lab1();
		default: {
			cout << "Missing lab with no " << no;
		}
		break;
	}



	_getch();
	return 0;
}
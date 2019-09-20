#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

int Lab3() {
	//Вариант 20

	int n=1;
	cout << "Enter n: ";
	cin >> n;

	double *numbers=new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter array[" << i << "]: ";
		cin >> numbers[i];
	}

	double sum = 0;
	double min = numbers[0];
	int minI = 0;
	for (int i = 0; i < n; i++)
	{
		sum += abs(numbers[i]);
		if (numbers[i] < min) {
			min = numbers[i];
			minI = i;
		}
	}

	double avg = sum / n;

	cout << "1) Abs values average: " << avg<<endl;
	cout << "2) Array`s max last index: " << minI<<endl;

	cout << "3)"<<endl<<"[" << endl;

	for (int i = 0; i < n; i++) {
		if (numbers[i] < 0) {
			cout << "\t" << numbers[i]<<endl;
			continue;
		}

		if (numbers[i] > 0) {
			for (int j = i + 1; j < n; j++) {
				if (numbers[j] >= 0) {
					continue;
				}

				double temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				break;
			}
		}
		else {

			int j = i + 1;
			for ( j = i + 1; j < n; j++) {
				if (numbers[j] <0) {
					numbers[i] = numbers[j];
					numbers[j] = 0;

					break;
				}
			}
			if (j == n) {
				for (j = i + 1; j < n; j++) {
					if (numbers[j] > 0) {
						numbers[i] = numbers[j];
						numbers[j] = 0;

						break;
					}
				}
			}
		}

		cout << "\t" << numbers[i]<<endl;

	}

	cout << "]" << endl;


	return 0;
}
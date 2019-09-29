#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;


int countRepeats(int* arr, int length) {
	int max = 0;
	int repeats;
	for (int i = 0; i < length; i++) {
		repeats = 1;

		for (int j = i + 1; j < length; j++) {
			if (arr[i] == arr[j]) {
				repeats++;
			}
		}

		if (repeats > max) {
			max = repeats;
		}
	}

	return max;
}

int getIndexOfMin(int* arr, int length,  int start ) {
	int min = arr[0];
	for (int i = start; i < length; i++) {

		if (arr[i] < min) {
			min = arr[i];
			continue;
		}

	}
	return min;
}

int Lab4() {

	int** matrix;    
	int m, n;

	cout << "matrix[m][n]" << endl;
	cout << "m= ";
	cin >> m; 
	
	cout << "n= ";
	cin >> n;

	if (n <= 0 || m <= 0) {
		cout << "Dimensions must be positive" << endl;
		return 0;
	}

	matrix = new int* [m];    
	for (int i = 0; i < m; i++) {   
		matrix[i] = new int[n];    
		for (int j = 0; j < n; j++) {
			cout << "matrix[" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}

	cout << "Source matrix:" << endl;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	int* maxRepeats = new int[m];

	for (int i = 0; i < m; i++) {
		maxRepeats[i] = countRepeats(matrix[i], n);
	}
	
	int minIn=-1;
	int temp;
	//swap columns
	for (int i = 0; i < m; i++) {
		minIn = getIndexOfMin(maxRepeats, m, i);

		for (int j = 0; j < n; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[minIn][j];
			matrix[minIn][j] = temp;
		}
	}


	cout << "Transformed matrix:" << endl;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}


	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}




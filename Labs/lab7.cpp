#include <iostream>;
using namespace std;

void sortMatrix(int** matrix, int n);

void sortArray(int* array, int n);

void swap(int* a, int* b);

int findLastPositiveRow(int** matrix, int n);


int Lab7() {
	//Рижков ПЗ-19-1, варіант 20
	int n;
	cout << "Enter n: ";
	cin >> n;
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "matrix[" << i << "][" << j << "]= ";
			cin >> matrix[i][j];
		}
	}
	 
	sortMatrix(matrix, n);

	cout << "Modified matrix: " << endl;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}


	cout << "Last positive row: " << findLastPositiveRow(matrix, n);

	return 0;
}

void sortMatrix(int** matrix, int n) {
	int* inLineMatrix = (int*)malloc(n * n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inLineMatrix[i * n + j] = matrix[i][j];

		}
	}


	sortArray(inLineMatrix, n * n);


	for (int d = 0; d < n; d++) {

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (inLineMatrix[d] == matrix[i][j]) {
					if (i + j != n - 1 || i > d) {
						swap(matrix[i][j], matrix[d][n - 1 - d]);
					}

				}
			}
		}
	}



}

int findMin(int** matrix, int n) {
	
	int min = INT16_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i -1; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
	}

	return min;


}

void sortArray(int* array, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--)
		{
			if (array[j] < array[j - 1]) {
				//swap
				swap(array[j], array[j - 1]);

			}
		}
	}
}
int findLastPositiveRow(int** matrix, int n) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
		{
			int a = *(*(matrix+i)+j);
			if (a < 0) {
				break;
			}

			if (j == n - 1) {
				return i;
			}
		}
	}

	return -1;
}

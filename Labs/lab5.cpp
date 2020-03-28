#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;


int* GetArray(int count, char* name) {
	int* array = (int*)malloc(count*sizeof(int));
	cout << name << endl;
	for (int i = 0; i < count; i++)
	{
		cout << name << "[" << i << "]: ";
		cin >> array[i];
	}

	return array;
}

int DotProduct(int* vector1, int* vector2, int l) {


	int sum = 0;
	for (int i = 0; i < l; i++)
	{
		sum += (vector1[i]) * (vector2[i]);

	}

	return sum;
	
}

int GetMin(int* vector, int l) {

	int min = vector[0];

	for (int i = 1; i < l; i++)
	{
		if (min > vector[i]) {
			min = vector[i];
		}
	}


	return min;
}

int* GetMinAndMaxIndexes(int* array, int l) {
	int* results=new int[2];

	int min = array[0], max = array[0], minI =0, maxI = 0;

	for (int i = 0; i < l; i++)
	{
		if (array[i] <= min) {
			min = array[i];
			minI = i;
		}
		if (array[i] >= max) {
			max = array[i];
			maxI = i;
		}
	}

	results[0] = minI;
	results[1] = maxI;

	return results;

}

int Lab5() {

	int m;

	cout << "Enter size of v1, v2, v3: ";
	cin >> m  ;

	int* arrays[] = { GetArray(m, "v1"), GetArray(m, "v2"),GetArray(m, "v3") };

	int minValues[] = { 
		GetMin(arrays[0], m),
		GetMin(arrays[1], m),
		GetMin(arrays[2], m)
	};

	int* vectorIndexes = GetMinAndMaxIndexes(minValues, 3);

	int product = DotProduct(arrays[vectorIndexes[0]], arrays[vectorIndexes[1]], m);

	for (int i = 0; i < 3; i++)
	{
		cout << "Min of v" << (i + 1) << ": " << minValues[i]<<endl;
	}

	cout << "Min of min value vector: v" << ((vectorIndexes[0]) + 1)<<endl;
	cout << "Max of min value vector: v" << (vectorIndexes[1] + 1)<<endl;

	cout << "Vectors dot product: " << product;

	delete[] arrays[0];
	delete[] arrays[1];
	delete[] arrays[2];
	delete[] vectorIndexes;


	return 0;
}
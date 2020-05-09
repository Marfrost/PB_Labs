/*
* Рижков В. Варіант 20
* У автопарку кожному водію на зміну видають певну кількість бензину.
* Протягом місяця кожен водій фіксував свої ПІБ, кілометраж, кількість витраченого бензину і суму виручки. 
* Визначити водіїв, які здали максимальну виручку і кількість невитраченого бензину. 
* Початкові дані і результати представити в наочному вигляді, із заголовками.
*/

#include <iostream>;
#include <fstream>;
#include <string>
using namespace std;


struct DriverReport {
	char* name="";
	int distance=0;
	int fuelConsumed=0;
	int profit=0;

	bool parse(char* in) {
		// Establish string and get the first token:
		char* nextToken;

		char* raw[4];
		raw[0] = strtok_s(in, ";", &nextToken);

		int i = 0;
		while (++i < 4 && (raw[i] = strtok_s(NULL, ";", &nextToken), true));
		if (i != 4) {
			return false;
		}

		this->name = raw[0];
		this->distance = stoi(raw[1]);
		this->fuelConsumed = stoi(raw[2]);
		this->profit = stoi(raw[3]);

		return true;
	}

};


int Lab9() {

	ifstream file;
	file.open(".\\..\\Labs\\2 Sem Lab 4 Data.txt");
	if (!file.is_open()) {
		cout << "File wasn't opened";
		return 0;
	}
	char* s=new char[1000];
	char* maxProfitName=new char[1000];
	char* minFuelName= new char[1000];
	
	int maxProfit=0, minFuel=INT16_MAX;
	cout << "Driver`s name	Distance, km	Fuel consumed, l	Money got,$" << endl;
	while (!file.eof() && file.getline(s, 1000)) {


		DriverReport report;
		if (!report.parse(s)) {
			cout << "Invalid data at line:" << endl << s << endl;
			continue;
		};
		printf("%-25s\t%4d\t%4d\t%4d\n", report.name, report.distance, report.fuelConsumed, report.profit);

		if (report.fuelConsumed < minFuel) {
			minFuel = report.fuelConsumed;
			strcpy_s(minFuelName, 1000, report.name);
		}
		if (report.profit > maxProfit) {
			maxProfit = report.profit;
			strcpy_s(maxProfitName, 1000, report.name);
		}
	}
	cout<<"Driver`s name	minimum fuel consumed, l"<<endl;
	printf("%-25s\t%4d", minFuelName, minFuel);

	cout << endl<< "Driver`s name	Money got,$" << endl;
	printf("%-25s\t%4d", maxProfitName, maxProfit);

	file.close();


	return 0;
}



#include <iostream>;
#include <math.h>

using namespace std;

double funcA(double x) {
	return x * tan(x) - 1.0 / 3.0;
}

double dfA(double x) {
	double c = cos(x);
	return tan(x) + x / (c * c);
}
double funcB(double x) {
	return sin(x*x)- 0.5;
}

double dfB(double x) {
	return cos(x * x) * 2*x;
}


double solve(double left, double right, double eps, int iterationLimit, double (*function)(double), double (*derivative)(double), int& iterNo) {

	iterNo = 0;
	double x0 = left, xr0=right;
	double x1 = x0 - function(x0) / derivative(x0), xr1=xr0-function(xr0)/derivative(xr0);
	while ( (++iterNo < iterationLimit)) {
		if (fabs(x1 - x0) > eps) {
			x1;			
		}
		else if (fabs(xr1 - xr0) < eps) {
			return xr1;
		}
		x0 = x1;
		x1 = x0 - function(x0) / derivative(x0);

		xr0 = xr1;
		xr1 = xr0 - function(xr0) / derivative(xr0);
	}
	return  x1 - x0 > xr1 - xr0 ? xr1: x1;

}

int Lab6() {
	int f = 0;
	cout << "Select function(1 or 2): ";
	cin >> f;

	double left, right;
	cout << "Left edge of interval= ";
	cin >> left;
	cout << "Right edge of interval= ";
	cin >> right;

	if (left > right) {
		left = left + right;
		right = left - right;
		left = left - right;
	}

	cout << "Searching on [" << left << " ; " << right << "]" << endl;

	double eps=1e-4;
	//cout << "Eps= ";
	//cin >> eps;

	cout << "Eps= " << eps<<endl;

	int maxIter;
	cout << "Max iterations= ";
	cin >> maxIter;

	int iterations = 0;

	double x = solve(left, right, eps, maxIter, (f==2)?funcB:funcA, (f==2)?dfB:dfA, iterations);

	cout << "Found solution x=" << x<<endl;

	cout << "f(x)=" << round(((f == 2) ? funcB(x) : funcA(x))*1e4)/1e4 << endl;

	cout << "Total iterations: " << iterations<<endl;
	return 0;
}


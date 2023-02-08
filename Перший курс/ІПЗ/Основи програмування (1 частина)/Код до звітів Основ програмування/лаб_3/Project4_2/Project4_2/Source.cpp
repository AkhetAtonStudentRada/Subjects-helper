#include <iostream>

using namespace std;

double multiply(double a, double b, double c) {
	return a * b * c;
}

int main() {
	double a, b, c;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << multiply(a, b, c);
	return 0;
}
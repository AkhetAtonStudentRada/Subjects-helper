#include <iostream>
using namespace std;


int even(double x_1, double x_2) {
	int x = ceil(x_1);
	for (x; x <= x_2; x++) {
		if ((x % 2) == 0) {
			cout << x << " ";
		}
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double x_1, x_2;
	cout << "введите начало диапазона "; cin >> x_1;
	cout << "введите конец диапазона "; cin >> x_2;
	even(x_1, x_2);
	return 0;
}
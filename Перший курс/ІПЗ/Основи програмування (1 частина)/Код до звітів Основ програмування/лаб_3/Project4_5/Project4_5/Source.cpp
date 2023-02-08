#include <iostream>

using namespace std;

int factorial(int n) {
	int y = 0;
	if (n == 0) {
		y = 1;
	} else
	if (n < 0) {
		cout << "data must be n >= 0 ";
	} else
	if (n > 0) {
		y = 1;
		for (int i = 1; i <= n; i++) {
			y *= i;
		}
	}
	return y;
}


int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите основание искомого факториала: "; cin >> n;
	cout << factorial(n);
	
	return 0;
}
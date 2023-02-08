#include <iostream>

using namespace std;

double input_x_2() {
	double x_2;
	cout << "x_2 : " << endl;
	cin >> x_2;
	return x_2;
}

double input_step() {
	double step;
	cout << "step : " << endl;
	cin >> step;
	return step;
}

int y(double x_1, int n)
{
	double step = input_step();
	double x_2 = input_x_2();
	if ((n < 1) || (step <= 0) || (x_1 > x_2)) { 
		cout << "data must be ((n >= 1) || (step > 0) || (x_1 <= x_2))" << endl;
		return y(x_1, n);
	}
		while (x_1 <= x_2) {
			if (x_1 <= 0) {
				double y = 0; int i = 0;
				if (x_1 != 0) {
					for (i; i <= (n - 1); i++) {
						int j = 0;
						for (j; j <= (n - 1); j++) {
							y += 1 / (x_1 - i + x_1 * j);
						}
					}
					cout << "(x ; y) : " << x_1 << " ; " << y << endl;
				}
				else {
					cout << "division by zero (x) " << x_1 << endl;
				}
			}
			else {
				double y = 1; int i = 1;
				for (i; i <= n; i++) {
					y *= (1 / x_1 - 1 / i);
				}
				cout << "(x ; y) : " << "(" << x_1 << " ; " << y << ")" << endl;
			}
			x_1 += step;
		}
		return 0;
}


int main() {
	double x_1; int n;
	cout << "x_1 : "; cin >> x_1;
	cout << "n : "; cin >> n;
	y(x_1, n);
	return 0;
}
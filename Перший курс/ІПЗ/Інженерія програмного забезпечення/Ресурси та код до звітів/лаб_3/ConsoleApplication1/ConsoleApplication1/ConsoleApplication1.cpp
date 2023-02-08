#include <iostream>
#include <fstream>

using namespace std;



void checkValidInput(double x_1, double x_2, double step, int n) {
	if (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');

		throw "Incorrect input";
	}
	else if ((n < 1) || (step <= 0) || (x_1 > x_2)) {
		throw "input correct data";
	}
}

double y_1(double x_1, int n) {

	double y = 0; int i = 0;
	if (x_1 != 0) {
		for (i; i <= (n - 1); i++) {
			int j = 0;
			for (j; j <= (n - 1); j++) {
				y += 1 / (x_1 - i + x_1 * j);
			}
		}
		return y;
	}
	else {
		cout << "division by zero (x) " << x_1 << endl;
		
	}
}


double y_2(double x_1, int n) {

	double y = 1; int i = 1;
	for (i; i <= n; i++) {
		y *= (1 / x_1 - 1 / i);
	}
	return y;
}


double calculate(double x_1, double x_2, double step, int n)
{
	double y;
	while (x_1 <= x_2) {
		if (x_1 <= 0) {
			y = y_1(x_1, n);
		}
		else {
			y = y_2(x_1, n);

		}
		return y;
		x_1 += step;
	}
}


int main() {

	setlocale(LC_ALL, "");
	bool outp_file;

tryAgain:
	try {
		double x_1;
		cout << "x_1 : ";
		cin >> x_1;

		double x_2;
		cout << "x_2 : ";
		cin >> x_2;


		double step;
		cout << "step : ";
		cin >> step;

		int n;
		cout << "n : ";
		cin >> n;
		checkValidInput(x_1, x_2, step, n);

		cout << "Вывод результата в файл?\n" << "любое число - да\n" << "0 - нет\n";
		cin >> outp_file;
		ofstream outf("result.txt");


		for (; x_1 <= x_2; x_1 += step) {
			if (outp_file == false)
				cout << "x = " << x_1 << " " << "y = " << calculate(x_1, x_2, step, n) << endl;
			else {
				outf << "x = " << x_1 << " " << "y = " << calculate(x_1, x_2, step, n) << endl;
				cout << "x = " << x_1 << " " << "y = " << calculate(x_1, x_2, step, n) << endl;
			}
		}
	}
	catch (...) {
		cout << "data must be ((n >= 1) || (step > 0) || (x_1 <= x_2))" << endl;
		goto tryAgain;
	}
	return 0;
}
#include "func.h"

double y_1(double x_1, double x_2, int n, double step) {
	while(x_1 <= x_2){
	double y = 0;
	if (x_1 < 0) {
	for (int i = 0; i <= (n - 1); i++) {
			int j = 0;
			for (j; j <= (n - 1); j++) {
					y += 1 / (x_1 - i + x_1 * j);
			}
		}
		return y;
	}
	else {
		double y = 0;
		cout << "division by zero (x) \t" << x_1 << endl;
		return y;
	}

	x_1 += step;
}  
}


double y_2(double x_1, double x_2, int n, double step) {
	while (x_1 <= x_2) {
		if (x_1 != 0) {
			double y = 1;
			for (int i = 1; i <= n; i++) {
				y *= (1 / x_1 - 1 / i);
			}
			return y;
		}
		else {
			double y = 0;
			cout << "division by zero (x)\t " << x_1 << endl;
			return y;
		}
		x_1 += step;
	}
}


bool checkValidInput(double x_1, double x_2, int n, double step)
{
	if ((n < 1) || (step <= 0) || (x_1 > x_2)) {
		cout << "data must be ((n >= 1) || (step > 0) || (x_1 <= x_2))" << endl;
		return true;
	}
	else {
		return false;
	}
}



	
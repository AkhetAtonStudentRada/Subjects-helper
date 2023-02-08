#include "def.h"

double mathFunc1(double x_1) {
	return x_1 * x_1 - 2 * x_1 + 4;
}

double mathFunc2(double x_1) {
	return 8 * x_1 * x_1 * x_1 + 1;
}


double var27(double x_1, double x_2, double step,sqrt2der func) {
	double max = x_1;
	for (x_1; x_1 <= x_2; x_1 += step)
	{
		if (((func(x_1 + 0.0000001)) - 2 * func(x_1) + (func(x_1 - 0.0000001))) / (0.0000001 * 0.0000001) == 0) {
			if (x_1 > max) {
				max = x_1;
			}
		}
	}
	return max;
}

bool checkValidInput(double x_1, double x_2, double step)
{
	if ((step <= 0) || (x_1 > x_2)) {
		cout << "data must be ((step > 0) || (x_1 <= x_2))" << endl;
		return true;
	}
	else {
		return false;
	}
}
#include <cmath>
#include "task.h"
	
double tasks::var27(double x_1, double x_2, double step) {
	double max = x_1;
	for (x_1; x_1 <= x_2; x_1 += step)
	{
		cout << "curret x = " << x_1 << "\t" << Proizv(x_1) << "\n";
		if (Proizv(x_1) == 0) {
			if (x_1 > max) {
				max = x_1;
			}
		}
	}
	return max;
}	


// производная второго порядка (формула)
double tasks::Proizv(double x_1) {
	const double eps = 0.0000001;
	double proizv;
	proizv = ((mathFunc(x_1 + eps)) - 2 * mathFunc(x_1) + (mathFunc(x_1 - eps))) / (eps * eps);
	return proizv;
}

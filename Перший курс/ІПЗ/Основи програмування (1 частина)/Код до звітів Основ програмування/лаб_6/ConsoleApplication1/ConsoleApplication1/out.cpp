#include "out.h"
#include "func.h"
using namespace std;
int n;
void output(double x_1, double x_2, double step, double (* func)(double, double, int, double)) {
for (x_1; x_1 <= x_2; x_1 += step) {
		
		cout << "x = " << x_1 << " " << "y = " << func(x_1, x_2, n, step) << endl;
	}
cout << endl << endl;
}
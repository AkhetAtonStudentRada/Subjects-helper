#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x_1, x_2, n, step; 
tryagain:
	cout << "x_1, x_2, n, step : " << endl;
	cin >> x_1 >> x_2 >> n >> step;
	if ((n < 1) || (step <= 0) || (x_1 > x_2)) {
		goto tryagain; 
	}
	else {
		while (x_1 <= x_2) {
			if (x_1 <= 0) {
				double y = 0, i = 0;
				if (x_1 != 0) {
					for (i; i <= (n - 1); i++) {
						double j = 0;
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
				double i = 1, y = 1;
				for (i; i <= n; i++) {
					y *= (1 / x_1 - 1 / i);
				}
				cout << "(x ; y) : " << "(" << x_1 << " ; " << y << ")" << endl;
			}
			x_1 += step;
		}
	}
	return 0;
}
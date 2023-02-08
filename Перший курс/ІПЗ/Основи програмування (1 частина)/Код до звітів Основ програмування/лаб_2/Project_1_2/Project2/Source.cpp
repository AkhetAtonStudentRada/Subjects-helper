#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, n, k;
tryagain: 
	cout << "x, n, k: " << endl;
	cin >> x >> n >> k;
	if (n <= 0 || k > n) {
		goto tryagain;
	}
	else {
		double i = 1, y = 0;
		for (i; i <= n; i++) {
			if (i != k) {
				if ((x + 2 * i) == 0) {
					cout << "error" << endl;
					break;
				}
				else {
					y = y + i / (x + 2 * i);
				}
			}
		}
		cout << y << endl;
	}
	return 0; 
}

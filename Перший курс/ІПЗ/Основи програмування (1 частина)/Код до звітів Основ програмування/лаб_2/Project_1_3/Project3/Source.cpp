#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, n, y = 1;
	int i = 1;
	cout << " x, n : " << endl;
	cin >> x >> n;
	for (i; i <= 2 * n; i++) {
		if ((i % 2) == 0) {
			y = y * (x - i);
		}
		else {
			y = y * (x + i);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(12);
	cout << y << endl;
	
	return 0;
}
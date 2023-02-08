#include <iostream>

using namespace std;

int product(int i, int n, double x, int y) {
	y *= (x + i);
	i++;
	if (i <= n) {
		product(i, n, x, y);
	}
	else cout << "y = " << y << endl;
	return y;
}

int main () {
	int i = 1; double x; int n; int y = 1; 

	cout << "input x = "; cin >> x;
	cout << "input n = "; cin >> n;
	if (n > 0) {
		cout << product(i, n, x, y);
	}
	else {
		cout << "data must be n > 0";
	}
	return 0;
}
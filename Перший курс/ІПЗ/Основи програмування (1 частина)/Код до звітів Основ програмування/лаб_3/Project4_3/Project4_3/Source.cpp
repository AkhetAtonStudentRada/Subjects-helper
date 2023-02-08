#include <iostream>

using namespace std;

double multiply(int n) {
	if (n > 1) {
	int y = 1, a = 1;
	for (int i = 1; i <= n; i++) {
		y *= a;
		a += 2;
	}
	return y;
	}
	else
		cout << "data must be n > 0";
}

int main() {
	int n;
	cout << "input n = "; cin >> n;
	if (n > 1) {
		cout << "y = " << multiply(n);
	}
	else
		cout << "data must be n > 0";
	return 0;
}
#include <iostream>

using namespace std;

int main() {
	const int n = 8;
	double a[n];
	double x;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i] < a[i + 1]) {
				x = a[i + 1];
				a[i + 1] = a[i];
				a[i] = x;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
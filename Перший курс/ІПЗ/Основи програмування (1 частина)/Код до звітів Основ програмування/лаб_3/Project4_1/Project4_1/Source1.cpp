#include <iostream>

using namespace std;

int signum(double x) {
	int y;
	if (x > 0) {
		y = 1;
		return y;
	};
	if (x < 0) {
		y = -1;
		return y;
	};
	if (x == 0) {
		y = 0;
		return y;
	};

}

int main() {
	double x;
	cout << "x = ";
	cin >> x;
	cout << "signum(x) = " << signum(x) << endl;
	return main();
}
#include <iostream>

using namespace std;

int main()
{
	double x; int y;
	cout << "x = ";
	cin >> x;
	if (x < 0) {
		y = -1;
		cout << "y = " << y << endl;
	}
	else {
		if (x > 0) {
			y = 1;
			cout << "y = " << y << endl;
		}
		else {
			y = 0;
			cout << "y = " << y << endl;
		}

		}
	return 0;
	}
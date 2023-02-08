#include <iostream>

using namespace std;

int main()
{
	double x; int y;
	cout << "x = ";
	cin >> x;
	y = x > 0 ? 1 : x < 0 ? -1 : 0;
	cout << "y = " << y << endl;
	return 0;
}
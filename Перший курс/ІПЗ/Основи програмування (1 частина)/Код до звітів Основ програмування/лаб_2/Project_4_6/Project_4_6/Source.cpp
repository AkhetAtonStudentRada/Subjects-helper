#include <iostream>

using namespace std;

int main()
{
	int n, y;
	cout << "n : "; cin >> n;
	switch (n) {
	case 0:		cout << "y = " << 2; break;
	case 1:		cout << "y = " << 4; break;
	case 2:		cout << "y = " << 5; break;
	case 3:		cout << "y = " << 3; break;
	case 4:		cout << "y = " << 1; break;
	default:	cout << "y = " << 0; break;
	}
	return 0;
}
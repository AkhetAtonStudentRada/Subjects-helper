#include <iostream>
using namespace std;

struct num {
	double aObj, bObj;
	num(double a, double b)
		:aObj(a), bObj(b)
	{
	}
};


double multy(num& pare) {
	return pare.aObj * pare.bObj;
}

int main()
{
	setlocale(LC_ALL, "");
	double a, b;
	cout << "введите два числа: ";
	cin >> a >> b;
	num pare_1(a, b);
	cout << "произведение: " << multy(pare_1);
	return 0;
}

#include <iostream>
#include "additional.h"
using namespace std;

void signum(double x)
{
	if (x == 0)
	{
		cout << "y = " << 0 << endl;
	}
	if (x > 0)
	{
		cout << "y = " << 1 << endl;
	}
	if (x < 0)
	{
		cout << "y = " << -1 << endl;
	}
}


double multy_3x(double z, double x, double c)
{
	return z * x * c;
}

double multiply_uneven(int n) {
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

double ePowX(double x)
{
	double z = 1, y = 0, i = 1;

	while (z > 0.00000000000000001)
	{
		y += z;
		z *= x / i;
		i++;
	}
	return round(y * 10000) / 10000;
}



int factorial(int n) {
	int y = 0;
	if (n == 0) {
		y = 1;
	}
	else
		if (n < 0) {
			cout << "data must be n >= 0 ";
		}
		else
			if (n > 0) {
				y = 1;
				for (int i = 1; i <= n; i++) {
					y *= i;
				}
			}
	return y;
}



double even(double x_1, double x_2) {
	if (x_1 <= x_2) {
		int x = ceil(x_1);
		for (x; x <= x_2; x++) {
			if ((x % 2) == 0) {
				return x;
			}
		}
	}
}



double multiply_even(int n) {
	if (n > 1) {
		int y = 1, a = 2;
		for (int i = 1; i <= n; i++) {
			y *= a;
			a += 2;
		}
		return y;
	}
	else
		cout << "data must be n > 0";
}




int gcd(int a, int b) {
	while (a > 0 && b > 0) {

		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	return a + b;
}
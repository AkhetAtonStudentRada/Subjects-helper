#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double eps, i, y;
	i = 1;
	y = 0;
	cout << "eps : " << endl;
	cin >> eps;
	while (1 / (pow(2, i)) >= eps) {
		y += 1 / (pow(2, i));
		i++;
	}
	cout << "y = " << y << endl;
	return main();
}
#include "stdio.h"
#include <math.h> 
#include <iostream> 


struct xyzP {
	double x_1, y_1, z_1;
public:
	xyzP(double x, double y, double z)
		:x_1(x), y_1(y), z_1(z)
	{
	}
};

double lenght(xyzP& first, xyzP& second) {
	return sqrt((second.x_1 - first.x_1)*(second.x_1 - first.x_1) + (second.y_1 - first.y_1)*(second.y_1 - first.y_1) + (second.z_1 - first.z_1)*(second.z_1 - first.z_1));
}

int main() {
	setlocale(LC_ALL, "");
	double x, y, z, x1, y1, z1;
	scanf_s("%lf %lf %lf %lf %lf %lf", &x, &y, &z, &x1, &y1, &z1);
	xyzP frst(x, y, z);
	xyzP scnd(x1, y1, z1);

	printf("%lf", lenght(frst, scnd));
	return 0;
}

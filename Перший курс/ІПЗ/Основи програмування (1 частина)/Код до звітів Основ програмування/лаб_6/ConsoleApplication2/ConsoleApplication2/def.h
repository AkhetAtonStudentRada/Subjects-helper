#include <iostream>
using namespace std;

typedef double (*sqrt2der)(double);

double mathFunc1(double x_1);

double mathFunc2(double x_1);

double var27(double x_1, double x_2, double step, sqrt2der func);

bool checkValidInput(double x_1, double x_2, double step);

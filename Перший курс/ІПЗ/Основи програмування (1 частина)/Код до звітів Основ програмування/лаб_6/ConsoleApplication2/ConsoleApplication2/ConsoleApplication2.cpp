#include <iostream>
#include <cmath>
#include "def.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "");

    double x_1, x_2, step;
    do {
        cout << "Введите x_1, x_2, step: ";
        cin >> x_1 >> x_2 >> step;

    } while (checkValidInput(x_1, x_2, step));



    cout << "max_1 = \t" << var27(x_1, x_2, step, mathFunc1) << endl;
    cout << "max_2 = \t" << var27(x_1, x_2, step, mathFunc2);

}


#include <iostream>
#include <fstream>
#include "func.h"
#include "out.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    double x_1, x_2, step;
    do {
        cout << "Введите x_1, x_2, n, step: ";
        cin >> x_1 >> x_2 >> n >> step;
    } while (checkValidInput(x_1, x_2, n, step));


    output(x_1, x_2, step, y_1);
    
    output(x_1, x_2, step, y_2);
    return 0;
 
}
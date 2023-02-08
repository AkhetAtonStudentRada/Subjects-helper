#include <iostream>
#include "task.h"
using namespace std;

class taskFunc : public tasks{
public:
    virtual double mathFunc(double x_1) override{
        return x_1 * x_1 - 2 * x_1 + 4;
    }
};

class taskFunc1 : public tasks{
public:
    virtual double mathFunc(double x_1) override{
        return x_1 * x_1 * x_1 - 5 * x_1 * x_1 + 4 * x_1 + 16 ;
    }
};

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");

    taskFunc a;
    taskFunc1 b;
    int q = -111, w = 11, e = 5;
    cout << "f(x) = x^2 - 2x + 4 \n \n";
    cout << "x_1 = " << q << "\t" << "x_2 = " << w << "\t" << "step = " << e << "\n \n";
    cout << "result = " << a.var27(q, w, e) << "\n \n \n";
    
    cout << "f(x) = x^3 - 5x^2 + 4x + 16 \n \n";
    cout << "x_1 = " << q << "\t" << "x_2 = " << w << "\t" << "step = " << e << "\n \n";
    cout << "result = " << b.var27(q, w, e) << "\n";
    system("pause");    

    return 0;
}
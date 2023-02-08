#include <iostream>
#include <cmath>
using namespace std;




int sq_eq(double a, double b, double c, double &x_1, double &x_2)
{
    if (a != 0) {
        double d = pow(b, 2) - 4 * a * c;
        if (d >= 0) {
            if (d > 0) {
                x_1 = (-b + sqrt(d)) / (2 * a);
                x_2 = (-b - sqrt(d)) / (2 * a);
                return 2;
            }
            else {
                x_1 = -b / (2 * a);
                return 1;
            }
        }
        else {
           // cout << "no roots" << endl;
            return 0;
        }
    }
    else {
        if (b != 0) {
            x_1 = -c / b; 
            return 1;
        }
        else {
            if (c != 0) {
                // out << "no roots" << endl;
                return 0;
            }
            else {
               // cout << "any value" << endl;
                return -1;
            }
        }
    }
}

int main() {
    double x_1, x_2;
    setlocale(LC_ALL, "UKRAINIAN");
    double a, b, c; cin >> a >> b >> c;
    cout << endl;


    switch (sq_eq(a, b, c, x_1, x_2))
    {
    case -1: cout << "any value" << endl;   break;
    case 0: cout << "no roots" << endl;   break;
    case 1: cout << x_1;   break;
    case 2: cout << x_1 << "    " << x_2;      break;
    }


    return 0;
}
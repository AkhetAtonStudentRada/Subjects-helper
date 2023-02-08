#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");
    double a, b, c;

    cin >> a >> b >> c;
    if (a != 0) {
        double d = pow(b, 2) - 4 * a * c;
            if (d >= 0) {
                if (d > 0) {
                    cout << "x_1 = " << (-b + sqrt(d)) / (2 * a) << endl;
                    cout << "x_2 = " << (-b - sqrt(d)) / (2 * a) << endl;
                }
                else {
                    cout << "x_1 = x_2 = " << -b / (2 * a) << endl;
                }
            }
            else {
                cout << "no roots" << endl;
            }
    }
    else {
        if (b != 0) {
            cout << "x = " << -c / b;
        }
        else {
            if (c != 0) {
                cout << "no roots" << endl;
            }
            else {
                cout << "any value" << endl;
            }
        }
    }
    return main();
}
#include <iostream>
#include <cmath>
using namespace std;

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

int main()
{
    setlocale(LC_ALL, "ru");

    double x;

    cout << "¬ведите степень, в которую хотите возвести e: ";
    cin >> x;

    cout << "e ^ " << x << " = " << ePowX(x)<< endl;
}
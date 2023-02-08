#include <iostream>

using namespace std;

void main()
{
    const int n = 10;
    double arr[n];
    double sum = 0;
    cout << "input values in massive: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum += arr[i];
        }
    }
    cout << "sum = " << sum;
}
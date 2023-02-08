#include <iostream>

using namespace std;

void main()
{
    const int n = 3;
    const int m = 3;
    double arr[n][m];
    double mult = 1;
    
    cout << "input values in massive: " << endl;
    for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    for (int j = 0; j < m; j++)
    {
        double max = arr[j][1];
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] > max) {
                 max = arr[i][j];
            }
        }
        mult *= max;
    }
    cout << mult;
}
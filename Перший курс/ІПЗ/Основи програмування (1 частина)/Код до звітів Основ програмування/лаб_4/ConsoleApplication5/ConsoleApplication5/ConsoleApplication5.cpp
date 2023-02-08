#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    int n, m;
    cout << "введите кол-во строк и столбцов: " << endl;
    cin >> n >> m;
    cout << endl;
    double* arr_sum = new double[n];
    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] <= 0 && arr[i][j] % 2 != 0)
                arr[i][j] *= 2;
            if (arr[i][j] > 0)
                sum += log10(arr[i][j]);
        }
        arr_sum[i] = sum;
    }



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        if (arr_sum[i] == 0) {
            cout << "v stroke net polozhitel'nyh elementov" << endl;
        }
        else
        {
            cout << "sum = " << arr_sum[i] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    delete[] arr_sum;
    return 0;
}

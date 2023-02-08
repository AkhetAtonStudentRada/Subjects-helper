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
    double**  arr = new double*[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[m];
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
            sum += arr[i][j];
        }
        arr_sum[i] = sum;
    }



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout <<"sum = " << arr_sum[i] <<  endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    delete[] arr_sum;
    return 0;
}

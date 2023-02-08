#include <iostream>
#include <fstream>
using namespace std;

struct Link
{
    int data;
    Link* next;
};

    

int main()
{
    setlocale(LC_ALL, "ru");
    int m; 
    ifstream in("array.txt");
    ofstream out("output.txt");


    Link* first = 0;
    Link* last = 0;
    Link* link;
    int d;
    int count = 0;
    while (in >> d)
    {
        count++;
        link = new Link;
        link->data = d;
        link->next = 0;
        if (last == 0)
        {
            first = link;
        }
        else
        {
            last->next = link;
        }
        last = link;
    }

    int n;
    cout << "vvedite kolichestvo stobcov matricy: ";
    cin >> n;
    
    if (count % 2 != 0) {
        m = count / n + 1;
    }
    else {
        m = count / n;
    }

    double* arr_sum = new double[m];
    int** arr = new int* [m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    link = first;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (link != 0) {

                arr[i][j] = link->data;

                link = link->next;

            }

            else {

                arr[i][j] = 0;

            }
        }
    }
    
    

    for (int i = 0; i < m; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] <= 0 && arr[i][j] % 2 != 0)
                arr[i][j] *= 2;
            if (arr[i][j] > 0)
                sum += log10(arr[i][j]);
        }
        arr_sum[i] = sum;
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out << arr[i][j] << " ";
        }
        if (arr_sum[i] == 0) {
            out << "v stroke net polozhitel'nyh elementov" << endl;
        }
        else
        {
            out << "sum = " << arr_sum[i] << endl;
        }
    }

    // delete


    for (int i = 0; i < m; i++) 
    {
        delete[] arr[i];
    }

    delete[] arr;

    while (first)
    {
        link = first;
        first = first->next;
        delete link;
    }
    delete[] arr_sum;
    return 0;
}

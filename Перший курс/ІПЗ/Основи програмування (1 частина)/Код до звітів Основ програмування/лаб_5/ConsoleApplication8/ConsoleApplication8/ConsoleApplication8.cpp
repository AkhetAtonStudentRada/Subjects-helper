#include <iostream>
#include <fstream>
using namespace std;


int main()
{   
    setlocale(LC_ALL, "");
    ofstream out("output.txt");
    cout << "vvedite kolichestvo elementov: " << endl;
    double n;
    cin >> n;
    double* arr = new double[n];
    double sum = 0;
    cout << "vvedite massive: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0) {
            sum += arr[i];
            out << sum << "   ";
        }
    }
    delete [] arr;
    return 0;
}

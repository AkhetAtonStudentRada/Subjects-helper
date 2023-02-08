#include <iostream>

using namespace std;

int Get()
{
    while (true)
    {
        int num = 0;
        cout << "Уведiть кiлькiсть елементiв масиву: ";
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cout << "Error! Некоректний тип.\n";
        }
        if (num < 2 || num > 255)
        {
            cout << "Error! Уведiть коректну кiлькiсть.\n";
        }
        return num;
    }
}

void qsort(int* arr, int left, int right) // 5 2 3 19 2 -8 5 9
{
    int i = left, j = right;
    int temp, pivot = arr[left];
    cout << "pivot = " << pivot << endl;
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\t\n";
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            if (arr[j] == pivot&&j!=i)
                j--;
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            i++; j--;
        }

    };



    if (left < j)
    {
        cout << "Left:\n";
        qsort(arr, left, j);
    }
    if (i < right)
    {
        cout << "Right:\n";
        qsort(arr, i, right);
    }
}

void Print(int* arr, int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Add(int* arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << (i + 1) << " число: ";
        cin >> arr[i];
        if (cin.fail())
        {
            cin.clear();
            cout << "Error! Некоректний тип.\n";
            i--;
        }
    }
}

int Search(int* N_arr, int N, int key)
{
    int left = 0;
    int right = N - 1;
    while (true)
    {
        int mid = (left + right) / 2;
        if (key < N_arr[mid])
            right = mid - 1;
        else if (key > N_arr[mid])
            left = mid + 1;
        else
            return mid;

        if (left > right)
            return -1;
    }
}

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");
    int N = Get();
    int *N_arr = new int [N];
    Add(N_arr, N);

    cout << "Невiдсортований масив: ";
    Print(N_arr, N);
    qsort(N_arr, 0, N - 1);
    cout << "  Вiдсортований масив: ";
    Print(N_arr, N);

    int M = Get();
    int *M_arr= new int [M];
    Add(M_arr, M);

    for (int i = 0; i < M; i++)
    {
        cout << "Значення: " << M_arr[i] << "\n";
        int loc = Search(N_arr, N, M_arr[i]);
        if (loc == -1)
        {
            cout << "Не знайдено!\n";
        }
        else
        {
            cout << "Знайдено!\nМiсце: " << loc + 1 << "\n";
        }
    }
    delete[] N_arr;
    delete[] M_arr;
    return 0;
}
#include <iostream>
#include "example.h"
using namespace std;


// EX 3.1
double sumOfPowers(double x, int n)
{
    double sum = 0;
    double pow = 1;
    for (int i = 0; i < n; i++)
    {
        pow *= x;
        sum += pow;
    }
    return sum;
}


// EX 3.2
int add(int i)
{
    static int sum = 0;
    sum += i;
    return sum;
}



// EX 3.3
int read()
{
    int n;
    cout << "Input n:";
    cin >> n;
    return n;
}

int calc(int n)
{
    int y = 0;
    for (int i = 1; i <= n; i++)
    {
        y += i * i;
    }
    return y;
}

void write(int y)
{
    cout << "y = " << y;
}
//


int solve(double a, double b, double& x)
{
    if (a == 0)
    {
        if (b == 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    x = -b / a;
    return 1;
}





// функція введення даних з клавіатури, параметри передаються за посиланням
bool readData(double& from, double& to, double& step)
{
    cout << "Print start, end and step ";
    cin >> from >> to >> step;
    if (from >= to || step <= 0)
    {
        cerr << "Wrong data" << endl;
        return false;
    }
    return true;
}

// Функція, визначена в завданні
double y(double x)
{
    if (x < 0)
    {
        return sin(x);
    }
    else
    {
        return sqrt(x);
    }
}

// Виведення значень аргументів і функції на інтервалі з визначеним кроком
void printInALoop(double from, double to, double step)
{
    cout << "x\ty" << endl; // "шапка" таблиці
    for (double x = from; x <= to; x += step)
    {
        cout << x << "\t" << y(x) << endl;
    }
}


void ex_3_1() {
    int n; double x;
    cout << "input x, n:" << endl;
    cin >> x >> n;
    cout << sumOfPowers(x, n);
}

void ex_3_2() {
    int i;
    do
    {
        cin >> i;
        cout << add(i) << endl;
    } while (i);
}

void ex_3_3() {
    int n = read();
    int y = calc(n);
    write(y);
}

void ex_3_4() {
    double a, b, x;
    cin >> a >> b;
    int count = solve(a, b, x);
    switch (count)
    {
    case -1:
        cout << "infinity roots";
        break;
    case 0:
        cout << "No root";
        break;
    case 1:
        cout << "x=  " << x;
    }
    cout << endl;
}



int ex_3_5() {
    double from, to, step;
    if (readData(from, to, step))
    {
        printInALoop(from, to, step);
        return 0; // таблицю виведено
    }
    return -1; // помилка введення даних
}

#include <iostream>
using namespace std;
class summa {
public: 
    summa(int val)
    : term(val) {
        sum += term;
    }

    static int GetSum() {
        return sum;
    }

private: 
    static int sum;
    int term;
};

int summa::sum = 0;

int main()
{
    int a = 8;
    summa one(a);
    cout << "+" << a << " = " << one.GetSum() << "\n";
    a = 15;
    summa two(a);
    cout << "+" << a << " = " << two.GetSum() << "\n";
    a = 46;
    summa three(46);
    cout << "+" << a << " = " << three.GetSum() << "\n";

    system("pause");
    return 0;
}


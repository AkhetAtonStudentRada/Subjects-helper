#include <iostream>
#include <fstream>
using namespace std;

class fraction {

private: 
     int n;
     int d;
public:
    
    fraction(int n = 1, int d = 1) {
        this->n = n;
        this->d = d;
    }

    void simpl() {
        if (n != 0) {
            if (d != 0) {
                int nEmpty = n;
                int dEmpty = d;
                int remainder = dEmpty % nEmpty;
                while (remainder != 0) {
                    dEmpty = nEmpty;
                    nEmpty = remainder;
                    remainder = dEmpty % nEmpty;
                }
                int gcd = nEmpty;
                if (gcd != 0) {
                    if (gcd < 0) {
                        if (n < 0 && d < 0 || n > 0 && d < 0) {
                            n /= gcd; d /= gcd;
                        }
                        else if (n < 0 && d > 0) {
                            n /= -gcd; d /= -gcd;
                        }
                    }
                    else {
                            if (n < 0 && d > 0 || n > 0 && d > 0) {
                                n /= gcd; d /= gcd;
                            }
                            else if (n > 0 && d < 0) {
                                n /= -gcd; d /= -gcd;
                            }
                    }

                    }
                }
            }
        }


    friend fraction operator+ (fraction f1,  fraction f2) {
        fraction temp; 
        if ((f1.d == 0) || (f2.d == 0)) {
            temp.n = f1.n * f2.d + f1.d * f2.n;
            temp.d = 0;
        } 
        else
        {
            temp.n = f1.n * f2.d + f1.d * f2.n;
            temp.d = f1.d * f2.d;
            temp.simpl();
        }
        return temp;
    }


    friend fraction operator- (fraction f1,  fraction f2) {
        fraction temp;
        if ((f1.d == 0) || (f2.d == 0)) {
            temp.n = f1.n * f2.d + f1.d * f2.n;
            temp.d = 0;
        }
        else {
            temp.n = f1.n * f2.d - f1.d * f2.n;
            temp.d = f1.d * f2.d;
            temp.simpl();
        }
        return temp;
    }


    friend fraction operator* (fraction f1, fraction f2) {
        fraction temp;
        if ((f1.d == 0) || (f2.d == 0)) {
            temp.n = f1.n * f2.d + f1.d * f2.n;
            temp.d = 0;
        } else 
        {
        temp.n = f1.n * f2.n;
        temp.d = f1.d * f2.d;
        temp.simpl();
        }
        return temp;
    }


    friend fraction operator/ (fraction f1,  fraction f2)
    {
        fraction temp;
        if ((f1.d == 0) || (f2.d == 0)) {
            temp.n = f1.n * f2.d + f1.d * f2.n;
            temp.d = 0;
        }
        else {
            temp.n = f1.n * f2.d;
            temp.d = f1.d * f2.n;
            temp.simpl();
        }
        return temp;
    }


    friend istream& operator>>(istream&, fraction& frctn);
    friend ostream& operator<<(ostream& out, const fraction& frctn);

};

// input and output
ostream& operator<<(ostream& out, const fraction& frctn) {
    if (frctn.d == 0) {
        out << "zero division error" << "\n";
    }
    else if (frctn.n == 0) {
        out << 0 << "\n";
    } 
    else if (frctn.d == 1){
        out << frctn.n << "\n";
    }
    else {
        out << frctn.n << "/" << frctn.d << "\n";
    }
    return out;
}

istream& operator>>(istream& in, fraction& number)
{
    in >> number.n >> number.d;
    return in;
}

int main()
{

    setlocale(LC_ALL, "Ukrainian");
    fraction first;
    fraction second;

    cout << "введіть дані першого дрібу: " << "\n";
    cin >> first;
    first.simpl();
    cout << "перший дріб: " << first << "\n";

    cout << "введіть дані другого дрібу: " << "\n";
    cin >> second;
    second.simpl();
    cout << "другий дріб: " << second << "\n";


    cout << "сума: " << first + second << "\n";
    cout << "різниця: " << first - second << "\n";
    cout << "множення: " << first * second << "\n";
    cout << "ділення: " << first / second << "\n";

    system("pause");
    return 0;
}
#pragma once
#include <iostream>

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
                        if ((n < 0 && d < 0) || (n > 0 && d < 0)) {
                            n /= gcd; d /= gcd;
                        }
                        else if (n < 0 && d > 0) {
                            n /= -gcd; d /= -gcd;
                        }
                    }
                    else {
                        if ((n < 0 && d > 0) || (n > 0 && d > 0)) {
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


    friend fraction operator+ (fraction f1, fraction f2) {
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


    friend fraction operator- (fraction f1, fraction f2) {
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
        }
        else
        {
            temp.n = f1.n * f2.n;
            temp.d = f1.d * f2.d;
            temp.simpl();
        }
        return temp;
    }


    friend fraction operator/ (fraction f1, fraction f2)
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



    friend bool operator<(const fraction& frst, const fraction& scnd)
        {
            if ((frst.n / frst.d) < (scnd.n / scnd.d))
            {
                return true;
            } 
            else {
                return false;
            }
        }

    friend istream& operator>>(istream&, fraction& frctn);
    friend ostream& operator<<(ostream& out, const fraction& frctn);

};

// input and output
ostream& operator<<(ostream& out, const fraction& frctn) {
    
    if (frctn.d == 0) {
        out << "zero division error";
    }
    else if (frctn.n == 0) {
        out << 0;
    }
    else if (frctn.d == 1) {
        out << frctn.n;
    }
    else if (frctn.n == frctn.d) {
        out << 1;
    }
    else {
        out << frctn.n << "/" << frctn.d;
    }
    return out;
}

istream& operator>>(istream& in, fraction& number)
{
    in >> number.n;
    cout << "/ \n";
    in >> number.d;
    cout << "\n";
    return in;
}

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {

        if (a > b) {
           a %= b;
        }
        else {
        b %= a;
    }
}

    return a + b;
}

int main() {
	setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "мнд: " << gcd(a, b) << endl;
	return 0;
}

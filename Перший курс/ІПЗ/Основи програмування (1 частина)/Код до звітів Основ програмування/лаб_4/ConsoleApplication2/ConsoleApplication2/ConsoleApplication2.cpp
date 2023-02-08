#include <iostream>

using namespace std;
const int n = 8;

double max(double a[]) {
    double max = a[1];
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

double min(double a[]) {
    double min = a[1];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

int main() {
    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "max = " << max(a) << endl << "min = " << min(a) << endl;
    cout << "result = " << min(a) + max(a) << endl;
    return 0;
}

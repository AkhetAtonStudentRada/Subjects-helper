#include <iostream>

using namespace std;

void main() {

    const int c = 16;
    int arr[c];
    unsigned short int k = 1;
    int n = 1;
    while (true)
    {
        cin >> k;
        if (!k)
        {
            break;
        }
        for (int i = 0; i < c; i++)
        {
            arr[i] = (k >> 15);
            k <<= 1;
        }
        for (int i = 0; i < c; i++) {
            if (arr[i] == 0) {
                continue;
            }
            else {
                n = i;
                break;
            }
        }
        for (int j = 15; j >= n; j--) {
            cout << arr[j];
        }
        cout << endl;
    }
}
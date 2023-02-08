#include <iostream>

using namespace std;

void main() {


    int arr[16];
    unsigned short int k = 1;
    int n = 1;
    while (true)
    {
        cin >> k;
        if (!k)
        {
            break;
        }
        for (int i = 0; i < 16; i++)
        {
            arr[i] = (k >> 15);
            k <<= 1;
        }
        for (int i = 0; i < 16; i++) {
            if (arr[i] == 0) {
                continue;
            }
            else { 
                n = i; 
                break; }
        }
        for (n-1; n < 16; n++) {
            cout << arr[n];
        }
        cout << endl;
    }
}

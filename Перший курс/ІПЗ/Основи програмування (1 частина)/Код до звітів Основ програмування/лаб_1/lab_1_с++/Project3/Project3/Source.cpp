#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "UKRAINIAN");
    int n;
    int n_1 = 1;
    cout << "”ведiть число: " << endl;
    cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            n_1 = n_1 * i;
        }
        cout << "фактор≥ал: " << n_1 << endl;
    } 
    else
        if (n == 0) {
            cout << "фактор≥ал: " << 1 << endl;
        }
        else 
            cout << "у в≥д'Їмного числа не маЇ фактор≥алу" << endl;
    return 0;
}
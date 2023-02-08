#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "UKRAINIAN");
    int a;
    float av = 0;
    cout << "Уведiть вiciм значеннь: " << endl;
    for (int i = 1; i <= 8; i++) {
        cin >> a;
        av += a;
    }
    cout << "Середне арифметичне: " << av/8 << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "UKRAINIAN");
    int a;
    float av = 0;
    cout << "����i�� �ici� ��������: " << endl;
    for (int i = 1; i <= 8; i++) {
        cin >> a;
        av += a;
    }
    cout << "������� �����������: " << av/8 << endl;
    return 0;
}
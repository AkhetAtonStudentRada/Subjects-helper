#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "UKRAINIAN");
    int n;
    int n_1 = 1;
    cout << "����i�� �����: " << endl;
    cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            n_1 = n_1 * i;
        }
        cout << "��������: " << n_1 << endl;
    } 
    else
        if (n == 0) {
            cout << "��������: " << 1 << endl;
        }
        else 
            cout << "� ��'������ ����� �� �� ���������" << endl;
    return 0;
}
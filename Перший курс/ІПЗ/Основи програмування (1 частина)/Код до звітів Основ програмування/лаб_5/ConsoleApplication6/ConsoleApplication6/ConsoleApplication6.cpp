#include <iostream>
using namespace std;
int main()
{
    int a; int m = 1;
    setlocale(LC_ALL, "");
    while(true){
        cin >> a;
        if (a != 0) {
            m *= a;
        }
        else {
            cout << "произведение равно: " << m;
            break;
        }

    }
    return 0;
}
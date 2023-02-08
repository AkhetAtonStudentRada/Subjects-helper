#include <iostream>
#include <fstream>


using namespace std;
int main()
{   
    ifstream in("input.txt");
    int a; int m = 1;
    setlocale(LC_ALL, "");
    while (in >> a) {
        if (a != 0) {
            m *= a;
        }
    }

    cout << "произведение равно: " << m;
    return 0;
}
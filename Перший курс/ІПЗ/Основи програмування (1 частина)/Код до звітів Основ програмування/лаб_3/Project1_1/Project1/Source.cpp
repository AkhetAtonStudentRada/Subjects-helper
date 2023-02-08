#include <iostream>


using namespace std;


int main()
{
    static int max = INT_MIN; static int min = INT_MAX; int a; bool trigger;
    while (true)
    {
        cin >> a;
        if (a > max) {
            max = a;
            if (a < min) {
                min = a;
            }
        }
        else {
            if (a < min) {
                min = a;
            }
        }
        cout << "min = " << min << endl << "max = " << max << endl << endl;
        cout << "print (1) to continue" << endl;
        cout << "print (0) to exit" << endl;
        cin >> trigger;
        if (trigger == true) {
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}


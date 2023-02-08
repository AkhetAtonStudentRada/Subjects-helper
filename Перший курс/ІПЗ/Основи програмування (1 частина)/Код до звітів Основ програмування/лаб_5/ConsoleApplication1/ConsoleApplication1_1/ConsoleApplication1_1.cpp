#include <iostream>
#include <string>
using namespace std;


void polin(char* text, int size) {
    for (int i = 0; i < (size / 2); i++)
    {
        if (text[i] != text[size - i - 1])
        {
            cout << "Not polin" << endl;
            break;
        }
        if ((size / 2) - 1 == i)
            cout << "Polim !!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    char str[128];
    char str_2[128];

    cin.getline(str, 128);

    for (int i = 0; i < 128; i++)
    {
        int a = str[i];
        if ((a >= 65) && (a <= 90)) {
            str[i] += 32;
        }
    }
    
    int j = 0;

    for (int i = 0; i < 128; i++)
    {   
        if (str[i] != '\0') {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я')) {
                str_2[j] = str[i];
                j++;
            }
        }
        else break;
    }

    polin(str_2, j);
    return 0;
}
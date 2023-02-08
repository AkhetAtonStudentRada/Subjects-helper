#include <iostream>
#include <string>
using namespace std;

int main()
{   
    setlocale(LC_ALL, "");
    std::string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        int a = str[i];
        if ((a >= 65)&&(a <= 90)) {
            str[i] += 32;
        }
    }
    cout << str << endl;
    std:string str2;
    for (int i = 0; i < str.length(); i++)
    {
        int a = str[i];
        if ((a >= 97) && (a <= 122))
        {
            str2 = str2 + str[i];
        }
    }    
    cout << str2 << endl;
    for (int i = 0; i < (str2.length()/2); i++)
    {
        if (str2[i] != str2[str2.length() - i - 1])
        {
            cout << "Not polin" << endl;
            break;
        }
        if ((str2.length() / 2)-1 == i)
            cout << "Polim !!" << endl;
    }
    return 0;
}
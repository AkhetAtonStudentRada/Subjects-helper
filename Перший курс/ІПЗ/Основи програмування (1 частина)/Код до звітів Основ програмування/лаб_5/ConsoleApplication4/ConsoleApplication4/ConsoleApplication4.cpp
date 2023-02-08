#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	cout << "введите строку(двойной пробел - конец строки): ";
	const int n = 128;
	char str[n];
	cin.getline(str, n);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ') {
			str[i] = '_';
		}
		cout << str[i];
	}
	return 0;
}
#include <iostream>

using namespace std;


double qwe() {
	return 1;
}

double qwe(double x) {
	return x;
}
 
double qwe(double a, double b) {
	return a * b;
}


double zxc(double a = 1, double b = 1) {
	return a * b;
}

int main() {
	setlocale(LC_ALL, "Ukrainian");
	double x, a, b;
	cout << "какой аргумент вернуть? "; cin >> x;
	cout << "произведение каких аргументов вернуть? " << endl; cin >> a >> b; cout << endl;
	cout << qwe() << endl;
	cout << qwe(x) << endl;
	cout << qwe(a, b) << endl;


	cout << zxc() << endl;
	cout << zxc(x) << endl; 
	cout << zxc(a, b) << endl;
}
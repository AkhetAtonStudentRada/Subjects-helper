#include <iostream>
#include <cmath>

using namespace std;

int getbit(unsigned int v, int i)
{
	return (v >> i) & 0x1;
}

void NIST(long long int* arr, const int SIZE)
{
	int S=0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			S += 2 * getbit(arr[i], j) - 1;
		}
	}
	double Sobs = fabs(double(S)) / (SIZE*sqrt(8));
	double nist =1 - erfcf(Sobs/sqrt(2));
	cout << "NIST: " << nist << endl;
}

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	int N, a, c;
	unsigned long long int m;
	cout << "”ведiть кiлькiсть випадкових чисел: ";
	cin >> N;
	long long int* arr = new long long int[N] {};
	cout << "”ведiть коефiцiЇнт а: "; // 16807 12345 256 152 4294967296 56473829
	cin >> a;
	cout << "”ведiть коефiцiЇнт с: ";
	cin >> c;
	//cout << "”ведiть натуральне число m: ";
	//cin >> m;
	m = pow(2, 32);
	//cout << "”ведiть X1: ";
	//cin >> arr[0];
	 arr[0]=56473829;
	for (int i = 1; i < N; i++)
	{
		arr[i] = (a * arr[i - 1] + c) % m;
	}

	for (int i = 0; i < N; i++)
	{
		cout <<"X"<<i+1<<" = "<< arr[i]<<endl;
	}
	cout << endl;

	NIST(arr, N);


	delete[] arr;
}
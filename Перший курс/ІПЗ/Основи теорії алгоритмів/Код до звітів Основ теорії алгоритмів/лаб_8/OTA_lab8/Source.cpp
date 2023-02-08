#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL,"UKRAINIAN");
	int m, n;
	cout << "Уведiть розмiр прямокутного поля(m, n): ";
	cin >> m >> n;

	int** arr = new int* [m];
	int** mArr = new int* [m];
	char** cArr = new char* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
		mArr[i] = new int[n];
		cArr[i] = new char[n];
	}
	cout << "Уведiть значення клiтин прямокутного поля розмiром "<<m<< "x"<<n<<":\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			cArr[i][j] = '-';
		}
	}
	cout << "\nПрямокутне поле:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(8);
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	/*
	2 3 4 11 8
	10 7 8 1 2
	6 3 3 4 6
	4 5 9 6 7
	*/
	mArr[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		mArr[0][i] = mArr[0][i - 1] + arr[0][i];
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				mArr[i][j] = mArr[i - 1][j] + arr[i][j];
			mArr[i][j] = max(mArr[i][j - 1], mArr[i - 1][j]) + arr[i][j];
		}
	}
	

	int i=0, j=0;
	int temp;
	while (1)
	{
		cArr[i][j] = '*';
		if (i == m - 1 && j == n - 1)
		{
			break;
		}
		if (i == m - 1&&j!=n)
		{	
			j++;
			continue;
		}
		if (j == n - 1&&i!=m)
		{
			i++;
			continue;
		}

		if (i < (m - 1) && j < (n - 1))
		{
			temp = max(mArr[i][j + 1], mArr[i + 1][j]);

			if (temp == mArr[i][j + 1])
			{

				j++;

			}
			if (temp == mArr[i + 1][j])
			{

				i++;
			}
		}
				
	}

	cout << "Таблиця динамiчного программування:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(8);
			cout << mArr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Маршрут:\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(8);
			cout << cArr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Максимальна сума: " << mArr[m - 1][n - 1]<< endl;
	

	int** finale = new int* [2 * m-1 ];
	for (int i = 0; i < 2*m-1; i++)
	{
		finale[i] = new int[2 * n-1];
	}

	for (int i = 0; i < 2 * m - 1; i++)
	{
		for (int j = 0; j < 2*n-1; j++)
		{
			finale[i][j] = -1;
		}
	}

	for (int i = 0; i < m ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			finale[2 * i][2 * j] = mArr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(j<n-1)
				if(cArr[i][j]=='*'&&cArr[i][j+1]=='*')
					finale[2 * i][2 * j+1] = '*';
			if(i<m-1)
				if (cArr[i][j] == '*' && cArr[i+1][j] == '*')
					finale[2 * i+1][2 * j] = '*';
			/*if(j==n-1 && i != m-1)
				finale[2 * i + 1][2 * j] = '*';
			if(i==m-1 && j != n-1)
				finale[2 * i][2 * j + 1] = '*';*/
			if (i == m - 1 && j == n - 1)
				break;
		}
	}

	for (int i = 0; i < 2 * m-1; i++)
	{

		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout.width(8);
			if (finale[i][j] == '*')
			{
				cout << (char)finale[i][j];
				continue;
			}
			if (finale[i][j] == -1)
			{
				cout << '-';
				continue;
			}
			cout << to_string(finale[i][j]);
		}
		cout << endl;
	}
	return 0;
}
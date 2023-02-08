#include <iostream>
#include "matrix.h"
#include "fraction.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");
	try {
		int m, n, g, f;
		cout << "введіть розміри матриці m, n: \n";
		cin >> m >> n;
		matrix<int> intMatrix(m, n);

		cout << "введіть розміри матриці m, n: \n";
		cin >> g >> f;
		matrix<int> intMatrix1(g, f);
		cout << "введіть int матрицю A: \n";
		cin >> intMatrix;
		
		
		cout << "введіть int матрицю B: \n";
		cin >> intMatrix1;

		cout << "матриця int A\n" << intMatrix;
		cout << "матриця int B\n" << intMatrix1;

		try {
			cout << "сума: \n" << intMatrix + intMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}

		try {
			cout << "різниця: \n" << intMatrix - intMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}


		try {
			cout << "добуток: \n" << intMatrix * intMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n \n";
		}

		try {
		cout << "взяття по індексу  -> \t введіть індекси для матриці А: \n";
		int x, y;
		cin >> x >> y;
		if ((x < 1 || y < 1)||(x > n || y > m)) {
			throw Exception::badData();
		}
		else {
			cout << "результат в матриці А: " << intMatrix(x-1, y-1) << "\n";
		}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}




		try {
			cout << "взяття по індексу  -> \t введіть індекси для матриці B: \n";
			int k, l;
			cin >> k >> l;
			if ((k < 1 || l < 1) || (k > g || l > f)) {
				throw Exception::badData();
			}
			else {
				cout << "результат в матриці B: " << intMatrix1(k-1, l-1) << "\n";
			}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}

		cout << "\n Матриця А:\n";
		cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n" 
			<< individualTask(intMatrix) << "\n";
		cout << "мінімальне значення: \n" << findMin(intMatrix) << "\n";



		cout << "\n Матриця В:\n";
		cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n"
			<< individualTask(intMatrix1) << "\n";
		cout << "мінімальне значення: \n" << findMin(intMatrix1) << "\n";

		////==============================================================================
		cout << "введіть розміри матриці double C (m, n): \n";
		cin >> m >> n;
		matrix<double> doubleMatrix(m, n);
		cout << "введіть розміри матриці double D (m, n): \n";
		cin >> g >> f;
		matrix<double> doubleMatrix1(g, f);
		cout << "введіть double матрицю C: \n";
		cin >> doubleMatrix;

		cout << "введіть double матрицю D: \n";
		cin >> doubleMatrix1;

		cout << "матриця double C\n" << doubleMatrix;
		cout << "матриця double D\n" << doubleMatrix1;

		try {
			cout << "сума: \n" << doubleMatrix + doubleMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}

		try {
			cout << "різниця: \n" << doubleMatrix - doubleMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}


		try {
			cout << "добуток: \n" << doubleMatrix * doubleMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n \n";
		}

		try {
			cout << "взяття по індексу  -> \t введіть індекси для матриці C: \n";
			int x, y;
			cin >> x >> y;
			if ((x < 1 || y < 1) || (x > n || y > m)) {
				throw Exception::badData();
		}
			else {
				cout << "результат в матриці C: " << doubleMatrix(x - 1, y - 1) << "\n";
			}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}




		try {
			cout << "взяття по індексу  -> \t введіть індекси для матриці D: \n";
			int k, l;
			cin >> k >> l;
			if ((k < 1 || l < 1) || (k > g || l > f)) {
				throw Exception::badData();
			}
			else {
				cout << "результат в матриці D: " << doubleMatrix1(k - 1, l - 1) << "\n";
			}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}

		cout << "\n Матриця C:\n";
		/*cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n"
			<< individualTask(doubleMatrix) << "\n";*/
		cout << "мінімальне значення: \n" << findMin(doubleMatrix) << "\n";



		cout << "\n Матриця D:\n";
		/*cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n"
			<< individualTask(doubleMatrix1) << "\n";*/
		cout << "мінімальне значення: \n" << findMin(doubleMatrix1) << "\n";

		//================================================
		cout << "введіть розміри fraction матриці E (m, n): \n";
		cin >> m >> n;
		matrix<fraction> fractionMatrix(m, n);
		cout << "введіть розміри fraction матриці F(m, n): \n";
		cin >> g >> f;
		matrix<fraction> fractionMatrix1(g, f);
		cout << "введіть fraction матрицю E: \n";
		cin >> fractionMatrix;


		cout << "введіть fraction матрицю F: \n";
		cin >> fractionMatrix1;

		cout << "матриця fraction E\n" << fractionMatrix;
		cout << "матриця fraction F\n" << fractionMatrix1;

		try {
			cout << "сума: \n" << fractionMatrix + fractionMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}

		try {
			cout << "різниця: \n" << fractionMatrix - fractionMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n";
		}


		try {
			cout << "добуток: \n" << fractionMatrix * fractionMatrix1 << "\n \n";
		}
		catch (Exception::imposibleAction& ex) {
			cout << "Imposibile math action!\n \n";
		}

		try {
			cout << "взяття по індексу  -> \t введіть індекси для матриці E: \n";
			int x, y;
			cin >> x >> y;
			if ((x < 1 || y < 1) || (x > n || y > m)) {
				throw Exception::badData();
			}
			else {
				cout << "результат в матриці E: " << fractionMatrix(x - 1, y - 1) << "\n";
			}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}




		try {
			cout << "взяття по індексу  -> \t введіть індекси для матриці F: \n";
			int k, l;
			cin >> k >> l;
			if ((k < 1 || l < 1) || (k > g || l > f)) {
				throw Exception::badData();
			}
			else {
				cout << "результат в матриці F: " << fractionMatrix1(k - 1, l - 1) << "\n";
			}
		}
		catch (Exception::badData& ex) {
			cout << "Incorrect data!\n";
		}

		cout << "\n Матриця E:\n";
		/*cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n"
			<< individualTask(fractionMatrix) << "\n";*/
		cout << "мінімальне значення: \n" << findMin(fractionMatrix) << "\n";



		cout << "\n Матриця В:\n";
		/*cout << "ідивідуальне завдання 27 варіант(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n"
			<< individualTask(fractionMatrix1) << "\n";*/
		cout << "мінімальне значення: \n" << findMin(fractionMatrix1) << "\n";

	}
	catch (const char* ex) {
		cout << ex;
	}
	catch (Exception::badData& ex) {
		cout << "Incorrect data!\n";
	}
	
	system("pause");
	return 0;
}

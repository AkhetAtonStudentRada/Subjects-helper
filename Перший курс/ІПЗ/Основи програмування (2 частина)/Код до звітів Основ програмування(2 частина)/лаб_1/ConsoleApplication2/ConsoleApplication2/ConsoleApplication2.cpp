#include <fstream>
#include <iostream>
using namespace std;


class matrix
{
private:
    int Row, Col;
    int** Value;
public:

    
    class badData //класс проверки ввода
    {
        int bad_value;
    public:
        badData(int value) : bad_value(value) {}
        badData() {}
    };


    class imposibleAction  //класс невозможных действий
    {
        int bad_data;
    public:
        imposibleAction(int value) : bad_data(value) {}
        imposibleAction() {}
    };





    matrix(int, int);
    matrix(const matrix&);


    int GetRow();
    int GetCol();

    int& operator()(int, int);
    const int& operator()(int, int) const;
    int* operator[] (int index) {
        return this->Value[index];
    }

    friend istream& operator>>(istream& istr, matrix& m);
    friend ostream& operator<<(ostream& ostr, const matrix& m);
    friend matrix operator+(matrix& m1, matrix& m2);
    friend matrix operator-(matrix& m1, matrix& m2);
    friend matrix operator*(matrix& m1, matrix& m2);
    friend matrix operator*(matrix& m1, int& number);

    ~matrix();

};




matrix::matrix(int row, int col)
{
    Row = row;
    Col = col;
    Value = new int* [row];
    for (int i = 0; i < row; i++) Value[i] = new int[col];

}

matrix::matrix(const matrix& m) //копирующий конструктор 
    :Row(m.Row), Col(m.Col)
{
    Value = new int* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new int[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } 
}

int matrix::GetRow()
{
    return Row;
}

int matrix::GetCol()
{
    return Col;
}

istream& operator>>(istream& istr, matrix& m)
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
        {
            istr >> m.Value[i][j];
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const matrix& m)
{
    for (int i = 0; i < m.Row; i++)
    {
        for (int j = 0; j < m.Col; j++)
        {
            ostr << m.Value[i][j] << "\t";
        }
        ostr << "\n";
    }
    return ostr;
}

matrix operator+(matrix& m1, matrix& m2)
{
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
    {
        for (int j = 0; j < m1.GetCol(); j++)
        {
            temp(i, j) = m1(i, j) + m2(i, j);
        }
    }
    return temp;

}

matrix operator-(matrix& m1, matrix& m2)
{
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
    {
        for (int j = 0; j < m1.GetCol(); j++)
        {
            temp(i, j) = m1(i, j) - m2(i, j);
        }
    }
    return temp;
}

matrix operator*(matrix& m1, matrix& m2) {
    matrix temp(m1.GetRow(), m2.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
    {
        for (int j = 0; j < m2.GetCol(); j++) {
            temp(i, j) = 0;
            for (int cell = 0; cell < m2.GetRow(); cell++)
            {
                temp(i, j) += m1(i, cell) * m2(cell, j);
            }
        }
    }
    return temp;
}


matrix operator*(matrix& m1, int& number) {
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
    {
        for (int j = 0; j < m1.GetCol(); j++)
        {
            temp(i, j) = m1(i, j) * number;
        }
    }
    return temp;
}

int& matrix::operator()(int row, int col) {
    return Value[row][col];
}

const int& matrix::operator()(int row, int col) const {
    return Value[row][col];
}

matrix::~matrix()
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i];
    delete[] Value;
}

matrix var27(matrix& m1)
{
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
    {
        for (int j = 0; j < m1.GetCol(); j++)
        {
            if ((m1(i, j) < 0) && (m1(i, j) % 2 != 0))
            {
                temp(i, j) = m1(i, j) * 3;
            }
            else {
                temp(i, j) = m1(i, j);

            }
        }
    }
    return(temp);
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int m, n, q, w, mult, func; bool swtchr = true;
    try {
        cout << "введіть кількість рядків та стовбців матриці A \n"; cin >> q >> w;


        if ((q <= 0) or (w <= 0))
            throw matrix::badData();
        matrix a(q, w);


        cout << "введіть кількість рядків та стовбців матриці B \n"; cin >> m >> n;

        if ((m <= 0) or (n <= 0))
            throw matrix::badData();
        matrix b(m, n);

        cout << "заповніть матрицю A:\n";  cin >> a;
        cout << "заповніть матрицю B:\n";  cin >> b;


        while (swtchr)
        {
            cout << "Перша матрица: \n" << a << endl << "Друга матрица: \n" << b << "\n \n \n";


            cout << "індивідуальне завдання 27ого варіанту(Усі від'ємні елементи з непарними значеннями повинні бути збільшені в два рази): \n \n \n";
            cout << "матриця А \n" << var27(a);
            cout << "матриця B \n" << var27(b) << "\n \n \n";

            cout << "Що потрібно знайти?: \n" << "1. сумма \n" << "2. різниця \n" << "3. добуток матриць \n" << "4.добуток матриць на число\n"
                << "5. взяття по індексу\n" << "6. кінець програми\n";
            cin >> func;
            cout << endl;
            switch (func)
            {
            case 1:
                if (a.GetRow() == b.GetRow() and a.GetCol() == b.GetCol())
                {
                    cout << a + b << endl;
                }
                else
                {
                    cout << "Не можна знайти суму матриць із різним розміром \n";
                    throw matrix::imposibleAction();
                }
                break;
            case 2:
                if (a.GetRow() == b.GetRow() and a.GetCol() == b.GetCol()) {
                    cout << a - b << endl;
                }
                else
                {
                    cout << "Не можна знайти різницю матриць із різним розміром \n";
                    throw matrix::imposibleAction();
                }
                break;
            case 3:
                if (a.GetCol() == b.GetRow())
                {
                    cout << a * b << endl;
                }
                else
                {
                    cout << "Кількість стовбців першої матриці повинна має рівнятися кількості рядків другої \n";
                    throw matrix::imposibleAction();
                }
                break;
            case 4:
                cout << "введіть множник:\n";
                cin >> mult;
                cout << "множена матриця А: \n" << a * mult << "\n";
                cout << "множена матриця B: \n" << b * mult << "\n";
                break;
            case 5:
                cout << "введіть шукаємі індекси:\n";
                int z, x;
                cin >> z >> x;
                if ((z <= 0) or (x <= 0)) {
                    throw matrix::badData();
                }
                else
                {
                    if ((z > q) or (x > w)) {
                        throw matrix::badData();
                    }
                    else {
                        cout << "з матриці А: \n" << a(z - 1, x - 1) << "\n";
                    }
                    if ((z > m) or (x > n)) {
                        throw matrix::badData();
                    }
                    else {
                        cout << "з матриці B: \n" << b(z - 1, x - 1) << "\n";
                    }
                }
                break;
            case 6:
                return 0;
            default:
                throw matrix::badData();
            }
            cout << "Продовжити? \n 0.Ні \n 1.так \n";
            cin >> swtchr;
        }


        
    }
    catch (matrix::badData& data) {
        cout << "помилка вводу даних \n";
    }
    catch (matrix::imposibleAction& data) {
        cout << "помилка математичної операції \n";
    }

    system("pause");
    return 0;
}
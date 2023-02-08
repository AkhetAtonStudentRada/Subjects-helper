#pragma once
#include <iostream>

using namespace std;

class Exception {
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
};


    template <typename T> 
    class matrix
    {
        

    private:
        int Row, Col;
        T** Value = nullptr;


    public:

        matrix() { }
        matrix(int, int);
        matrix(const matrix&);


        int GetRow();
        int GetCol();

        T& operator()(int, int);
        const T& operator()(int, int) const;

        T* operator[] (int index) {
            return this->Value[index];
        }

        ~matrix();


        friend istream& operator>>(istream& in, matrix& m)
        {
            for (int i = 0; i < m.Row; i++)
            {
                for (int j = 0; j < m.Col; j++)
                {
                    in >> m.Value[i][j];
                }
            }
            return in;
        }

        friend ostream& operator<<(ostream& out, const matrix& m)
        {
            for (int i = 0; i < m.Row; i++)
            {
                for (int j = 0; j < m.Col; j++)
                {
                    out << m.Value[i][j] << "\t";
                }
                out << "\n";
            }
            return out;
        };
        template<typename T> friend matrix<T> operator+(const matrix<T>& m1, const matrix<T>& m2);
        template<typename T> friend matrix<T> operator-(const matrix<T>& m1, const matrix<T>& m2);
        template<typename T> friend matrix<T> operator*(const matrix<T>& m1, const matrix<T>& m2);
        template<typename T> friend matrix<T> operator*(const matrix<T>& m1, int& number);

    };


    template <typename T>
    matrix<T>::matrix(int row, int col)
    {
        if (row < 1) {
            throw Exception::badData(row);
        }
        if (col < 1) {
            throw Exception::badData(col);
        }
        else {
            Row = row;
            Col = col;
            Value = new T * [row];
            for (int i = 0; i < row; i++) Value[i] = new T[col];
        }
    }

    template <typename T> 
    matrix<T>::matrix(const matrix& m) //копирующий конструктор 
        :Row(m.Row), Col(m.Col)
    {
        Value = new T* [Row];
        for (int i = 0; i < Row; i++)  Value[i] = new T[Col];
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
                Value[i][j] = m.Value[i][j];
        }
    }

    template <typename T> int matrix<T>::GetRow()
    {
        return Row;
    }

    template <typename T> int matrix<T>::matrix::GetCol()
    {
        return Col;
    }

    


    template <typename T>
    matrix<T> operator+(matrix<T>& m1, matrix<T>& m2)
    {
        if (m1.GetRow() != m2.GetRow() || m1.GetCol() != m2.GetCol()) {
            throw Exception::imposibleAction();
        }
        else {
        matrix<T> temp(m1.GetRow(), m1.GetCol());
        for (int i = 0; i < m1.GetRow(); i++)
        {
            for (int j = 0; j < m1.GetCol(); j++)
            {
                temp(i, j) = m1(i, j) + m2(i, j);
            }
        }
        return temp;
    }
    }


    template <typename T>
    matrix<T> operator-(matrix<T>& m1, matrix<T>& m2)
    {
        if (m1.GetRow() != m2.GetRow() || m1.GetCol() != m2.GetCol()) {
            throw Exception::imposibleAction();
        }
        else {
            matrix<T> temp(m1.GetRow(), m1.GetCol());
            for (int i = 0; i < m1.GetRow(); i++)
            {
                for (int j = 0; j < m1.GetCol(); j++)
                {
                    temp(i, j) = m1(i, j) - m2(i, j);
                }
            }
            return temp;
        }
    }

    template <typename T>
    matrix<T> operator*(matrix<T>& m1, matrix<T>& m2)
    {
        if (m1.GetCol() != m2.GetRow()) {
            throw Exception::imposibleAction();
        }
        else {
            matrix<T> temp(m1.GetRow(), m2.GetCol());
            for (int i = 0; i < m1.GetRow(); i++)
            {
                for (int j = 0; j < m2.GetCol(); j++) {
                    temp(i, j) = 0;
                    for (int cell = 0; cell < m2.GetRow(); cell++)
                    {
                        temp(i, j) = temp(i, j) + m1(i, cell) * m2(cell, j);
                    }
                }
            }
            return temp;
        }
      
    }


    template <typename T>
    matrix<T> operator*(matrix<T>& m1, int& number)
    {
        matrix<T> temp(m1.GetRow(), m1.GetCol());
        for (int i = 0; i < m1.GetRow(); i++)
        {
            for (int j = 0; j < m1.GetCol(); j++)
            {
                temp(i, j) = m1(i, j) * number;
            }
        }
        return temp;
    }

    template <typename T>
    T& matrix<T>::operator()(int row, int col)
    {
        /*if (row < 1 && col < 1)
        {
            throw Exception::badData();
        }*/
        return Value[row][col];
    }

    template <typename T>
    const T& matrix<T>::operator()(int row, int col) const
    {   
        /*if (row < 1 && col < 1)
    {
        throw Exception::badData();
    }*/
        return Value[row][col];
    }

    template <typename T>
    matrix<T>::~matrix()
    {
        for (int i = 0; i < Row; i++)
            delete[] Value[i];
        delete[] Value;
    }

    template <typename T>
    matrix<T> individualTask(matrix<T>& m1)
     {
         matrix<T> temp(m1.GetRow(), m1.GetCol());
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

    template <typename T> 
    T findMin(matrix<T>& m) {
        T min;
        min = m(0, 0);
        for (int i = 0; i < m.GetRow(); i++)
        {
            for (int j = 0; j < m.GetCol(); j++)
            {
                if (m(i, j) < min) {
                    min = m(i, j);
                }
            }
        }
        return min;
    }

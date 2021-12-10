#include <iostream>
#include "main.h"

/* Создание двумерного массива, лежащего
 * в памяти так, что "строки независят от столбцов" */
template <typename T>
T** createInDependentTwoDimensionalMas(size_t n, size_t m)
{
    T** mas = new T*[n];
    for(size_t i = 0; i < n; i++)
    {
        mas[i] = new T[m];
    }
    return mas;
}

/* Создание двумерного массива, лежащего
 * в памяти "одной строкой" */
template <typename T>
T** createDependentTwoDimensionalMas(size_t n, size_t m)
{
    T* mas = new T[n * m]{0};
    T** masAdd = new T*[n];
    for(size_t i = 0, j = 0; i < n * m; i += m, j++)
    {
        masAdd[j] = &mas[i];
    }
    return masAdd;
}

/* Функция вывода двумерного массива */
template <typename T>
void printDimensionalMas(T** mas, size_t n, size_t m)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
            std::cout << mas[i][j] << " " << "\t";
        std::cout << std::endl;
    }
}

/* Функция удаления двумерного массива */
template <typename  T>
void deleteDimensionMas(T** mas, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        delete [] mas[i];
    delete [] mas;
}

/* Инициализация массива значением */
template <typename T>
void initializationByValue(T** mas, size_t n, size_t m, T value)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            mas[i][j] = value;
        }
    }
}

/* Умножение матрицы на число */
void multiplyingByNumber(int** mas, size_t n, size_t m, int number)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            mas[i][j] *= number;
        }
    }
}

/* Инициализация массива с 1 на главной диагонали
 * и 0 в остальных элементах */
void initializationByOneMainDiagonal(int** mas, size_t n, size_t m)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            i == j ? mas[i][j] = 1 : mas[i][j] = 0;
        }
    }
}

/* Создание транспонированного массива
 * (возращает "независимый массив")*/
template <typename T>
T** transposeIndependentArray(T** mas, size_t n, size_t m)
{
    T** res = createInDependentTwoDimensionalMas<T>(m, n);
    for(size_t i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res[i][j] = mas[j][i];
        }
    }
    return res;
}

/* Создание транспонированного массива
 * (возращает "зависимый массив")*/
template <typename T>
T** transposeDependentArray(T** mas, size_t n, size_t m)
{
    T** res = createDependentTwoDimensionalMas<T>(m, n);
    for(size_t i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res[i][j] = mas[j][i];
        }
    }
    return res;
}

/* поворот на 180 */
template <typename T>
T** turnArray180(T** mas, size_t n, size_t m)
{
    for(size_t i = 0; i < n / 2; i++)
    {
        for(size_t j; j < m; j++)
        {
            int tmp = mas[n - i - 1][j];
            mas[n - i - 1][j] = mas[i][j];
            mas[i][j] = tmp;
        }
    }
}

/*Создание матрицы, как результата умножения матрицы на число
 * (возращает зависимый массив)*/
int** multiplyingByNumberReturnDependent(int** mas, size_t n, size_t m, int number)
{
    int** res = createDependentTwoDimensionalMas<int>(n, m);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            res[i][j] = mas[i][j] * number;
        }
    }
    return res;
}

/*Создание матрицы, как результата умножения матрицы на число
 * (возращает независимый массив)*/
int** multiplyingByNumberReturnInDependent(int** mas, size_t n, size_t m, int number)
{
    int** res = createInDependentTwoDimensionalMas<int>(n, m);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            res[i][j] = mas[i][j] * number;
        }
    }
    return res;
}

/* Создание матрицы как результата сложения двух числовых матриц.
 * (возращает независимый массив)*/
int** sumMatrixIndependent(int** mas1, int** mas2, size_t n, size_t m)
{
    int** res = createInDependentTwoDimensionalMas<int>(n, m);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            res[i][j] = mas1[i][j] + mas2[i][j];
        }
    }
    return res;
}

/* Создание матрицы как результата сложения двух числовых матриц.
 * (возращает независимый массив)*/
int** sumMatrixDependent(int** mas1, int** mas2, size_t n, size_t m)
{
    int** res = createDependentTwoDimensionalMas<int>(n, m);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            res[i][j] = mas1[i][j] + mas2[i][j];
        }
    }
    return res;
}

/* Создание матрицы как результата умножения двух числовых матриц.
 * (возращает независимый массив)*/
int** mulMatrixIndependent(int** mas1, size_t n1, size_t m1, int** mas2, size_t n2, size_t m2)
{
    if (m1 != n1)
    {
        return nullptr;
    }
    int** res = createInDependentTwoDimensionalMas<int>(n1, m2);
    initializationByValue(res, n1, m2, 0);
    for(size_t i = 0; i < n1; i++)
    {
        for(size_t j = 0; j < m2; j++)
        {
            for(size_t l = 0; l < m1; l++)
            {
                res[i][j] += mas1[i][l] * mas2[l][j];
            }
        }
    }

    return res;
}

/* Создание матрицы как результата умножения двух числовых матриц.
 * (возращает зависимый массив)*/
int** mulMatrixDependent(int** mas1, size_t n1, size_t m1, int** mas2, size_t n2, size_t m2)
{
    if (m1 != n2)
    {
        return nullptr;
    }
    int** res = createDependentTwoDimensionalMas<int>(n1, m2);
    initializationByValue(res, n1, m2, 0);
    for(size_t i = 0; i < n1; i++)
    {
        for(size_t j = 0; j < m2; j++)
        {
            for(size_t l = 0; l < m1; l++)
            {
                res[i][j] += mas1[i][l] * mas2[l][j];
            }
        }
    }
    return res;
}

/*Обмен местами двух строк*/
template <typename T>
void swapRaw(T** mas, size_t n, size_t m, int raw1, int raw2)
{
    for(size_t i = 0; i < m; i++)
    {
        T tmp = mas[raw1][m];
        mas[raw1][m] = mas[raw2][m];
        mas[raw2][m] = tmp;
    }
}

/*Обмен местами двух столбцов*/
template <typename T>
void swapColumn(T** mas, size_t n, size_t m, int column1, int column2)
{
    for(size_t i = 0; i < m; i++)
    {
        T tmp = mas[i][column1];
        mas[i][column1] = mas[i][column2];
        mas[i][column2] = tmp;
    }
}
/* Получение доступа по ссылке к элементу 2-массива
 * с заданными значениями строки и столбца*/
template <typename T>
T& getElement(T** mas, size_t n, size_t m, size_t row, size_t column)
{
    if(row > n - 1 || column > m - 1)
    {
        return mas[0][0];
    }
    return mas[row][column];
}

/* алгоритм Гаусса приведения матрицы к диагональному виду */
void gauss(double** mas, size_t n, size_t m)
{

}

/* вычисление определителя квадратной матрицы */
double determinant(double** mas, size_t n)
{
    double res = 0;

    return res;
}

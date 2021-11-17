#include <iostream>
#include "main.h"

/* Создание двумерного массива, лежащего
 * в памяти так, что "строки независят от столбцов" */
template <typename T>
T** creatIndependentTwoDimensionalMas(size_t n, size_t m)
{
    T** mas = new T*[n];
    for(size_t i = 0; i < n; i++)
    {
        mas[i] = new int[m];
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
 * (возращает "независимы массив")*/
template <typename T>
T** transposeIndependentArray(T** mas, size_t n, size_t m)
{
    T** res = creatIndependentTwoDimensionalMas<T>(m, n);
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
 * (возращает "зависимы массив")*/
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

}







#ifndef TASKS_15_11_2021_MAIN_H
#define TASKS_15_11_2021_MAIN_H

/* Создание двумерного массива, лежащего
 * в памяти так, что "строки независят от столбцов" */
template <typename T>
T** createInDependentTwoDimensionalMas(size_t n, size_t m);

/* Создание двумерного массива, лежащего
 * в памяти "одной строкой" */
template <typename T>
T** createDependentTwoDimensionalMas(size_t n, size_t m);

/* Функция вывода двумерного массива */
template <typename T>
void printDimensionalMas(T** mas, size_t n, size_t m);

/* Функция удаления двумерного массива */
template <typename  T>
void deleteDimensionMas(T** mas, size_t n, size_t m);

/* Инициализация массива значением */
template <typename T>
void initializationByValue(T** mas, size_t n, size_t m, T value);

/* Умножение матрицы на число */
void multiplyingByNumber(int** mas, size_t n, size_t m, int number);

/* Инициализация массива с 1 на главной диагонали
 * и 0 в остальных элементах */
void initializationByOneMainDiagonal(int** mas, size_t n, size_t m);

/* Создание транспонированного массива
 * (возращает "независимы массив")*/
template <typename T>
T** transposeIndependentArray(T** mas, size_t n, size_t m);

/* Создание транспонированного массива
 * (возращает "зависимы массив")*/
template <typename T>
T** transposeDependentArray(T** mas, size_t n, size_t m);

/* поворот на 180 */
template <typename T>
T** turnArray180(T** mas, size_t n, size_t m);

/*Создание матрицы, как результата умножения матрицы на число
 * (возращает зависимый массив)*/
int** multiplyingByNumberReturnDependent(int** mas, size_t n, size_t m, int number);

/*Создание матрицы, как результата умножения матрицы на число
 * (возращает независимый массив)*/
int** multiplyingByNumberReturnInDependent(int** mas, size_t n, size_t m, int number);

/* Создание матрицы как результата сложения двух числовых матриц.
 * (возращает независимый массив)*/
int** sumMatrixIndependent(int** mas1, int** mas2, size_t n, size_t m);

/* Создание матрицы как результата сложения двух числовых матриц.
 * (возращает независимый массив)*/
int** sumMatrixDependent(int** mas1, int** mas2, size_t n, size_t m);

/* Создание матрицы как результата умножения двух числовых матриц.
 * (возращает независимый массив)*/
int** mulMatrixIndependent(int** mas1, size_t n1, size_t m1, int** mas2, size_t n2, size_t m2);

/* Создание матрицы как результата умножения двух числовых матриц.
 * (возращает зависимый массив)*/
int** mulMatrixDependent(int** mas1, size_t n1, size_t m1, int** mas2, size_t n12, size_t m2);

/*Обмен местами двух строк*/
template <typename T>
void swapRaw(T** mas, size_t n, size_t m, int raw1, int raw2);

/*Обмен местами двух столбцов*/
template <typename T>
void swapColumn(T** mas, size_t n, size_t m, int column1, int column2);

/* Получение доступа по ссылке к элементу 2-массива
 * с заданными значениями строки и столбца*/
template <typename T>
T& getElement(T** mas, size_t n, size_t m, size_t row, size_t column);

#endif

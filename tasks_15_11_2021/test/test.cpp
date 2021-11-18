#include <vector>
#include "../src/main.cpp"

//вывод результатов теста
void printTestEqFailed(const std::string& name)
{
    std::cout << "\033[31m" << name << " =======  TEST FAILED " <<"\033[m \n";
}
void printTestEqSuccessful(const std::string& name)
{
    std::cout << "\033[32m" << name << " =======  TEST SUCCESSFUL " <<"\033[m \n";
}


/* сравнение двумерных  массивов на равенство
 * плохое сравнение чисел с плавающей запятой*/
template <typename T>
bool assertEqMas(T** mas1, size_t n1, size_t m1, T** mas2, size_t n2, size_t m2)
{
    if (n1 != n2 or m1 != m2)
        return false;
    else
        for(size_t i = 0; i < n1; i++)
        {
            for(size_t j = 0; j < m1; j++)
            {
                if(mas1[i][j] != mas2[i][j])
                    return false;
            }
        }
    return true;
}

/* инициализация значением (тест зависимого массива int) */
bool initializationByValueTestOne()
{
    bool res;
    int** real = createDependentTwoDimensionalMas<int>(5, 4);
    initializationByValue(real, 5, 4, -89);
    int** test = new int*[5]{new int[4]{-89, -89, -89, -89}, new int[4]{-89,-89,-89,-89},
                             new int[4]{-89,-89,-89,-89}, new int[4]{-89,-89,-89,-89}, new int[4]{-89,-89,-89,-89}};

    res = assertEqMas<int>(test, 5, 4, real, 5, 4);

    if(res)
        printTestEqSuccessful(__func__);
    else
        printTestEqFailed(__func__);


    deleteDimensionMas(test, 5,4 );
    return res;
}

/* инициализация значением (тест независимого массива double) */
bool initializationByValueTestTwo()
{
    bool res;
    double** real = creatIndependentTwoDimensionalMas<double>(5, 4);
    initializationByValue(real, 5, 4, 9.43);
    auto** test = new double*[5]{new double[4]{9.43, 9.43, 9.43, 9.43},
                                   new double[4]{9.43, 9.43, 9.43, 9.43},
                                   new double[4]{9.43, 9.43, 9.43, 9.43},
                                   new double[4]{9.43, 9.43, 9.43, 9.43},
                                   new double[4]{9.43, 9.43, 9.43, 9.43}};

    res = assertEqMas<double>(test, 5, 4, real, 5, 4);

    if(res)
        printTestEqSuccessful(__func__);
    else
        printTestEqFailed(__func__);


    deleteDimensionMas(test, 5,4 );
    deleteDimensionMas(real, 5,4 );
    return res;
}

/* инициализация значением (тест независимого массива string) */
bool initializationByValueTestThree()
{
    bool res;
    std::string** real = creatIndependentTwoDimensionalMas<std::string>(5, 4);
    initializationByValue(real, 5, 4, std::string("hello"));
    auto** test = new std::string *[5]{new std::string [4]{"hello", "hello", "hello", "hello"},
                                       new std::string [4]{"hello", "hello", "hello", "hello"},
                                       new std::string [4]{"hello", "hello", "hello", "hello"},
                                       new std::string [4]{"hello", "hello", "hello", "hello"},
                                       new std::string [4]{"hello", "hello", "hello", "hello"}};

    res = assertEqMas<std::string>(test, 5, 4, real, 5, 4);

    if(res)
        printTestEqSuccessful(__func__);
    else
        printTestEqFailed(__func__);


    deleteDimensionMas(test, 5,4 );
    deleteDimensionMas(real, 5,4 );
    return res;
}

/* Умножение матрицы на число (тест независимого массива)*/
bool multiplyingByNumberTestOne()
{
    bool res;
    int** real = creatIndependentTwoDimensionalMas<int>(5, 4);
    initializationByValue(real, 5, 4, 9);

    int** test = creatIndependentTwoDimensionalMas<int>(5, 4);
    initializationByValue(test, 5, 4, 45);

    multiplyingByNumber(real, 5, 4, 5);

    res = assertEqMas<int>(test, 5, 4, real, 5, 4);

    if(res)
        printTestEqSuccessful(__func__);
    else
        printTestEqFailed(__func__);

    deleteDimensionMas(test, 5,4 );
    deleteDimensionMas(real, 5,4 );
    return res;
}

/* Инициализация массива с 1 на главной диагонали
 * и 0 в остальных элементах
 * (тест зависимого массива) */
bool initializationByOneMainDiagonalTestOne()
{
    bool res;
    int** real = createDependentTwoDimensionalMas<int>(5, 4);
    initializationByOneMainDiagonal(real, 5, 4);

    int** test = new int*[5]{new int[4]{1, 0, 0, 0}, new int[4]{0,1,0,0},
                             new int[4]{0,0,1,0}, new int[4]{0,0,0,1}, new int[4]{0,0,0,0}};

    res = assertEqMas<int>(test, 5, 4, real, 5, 4);

    if(res)
        printTestEqSuccessful(__func__);
    else
        printTestEqFailed(__func__);

    deleteDimensionMas(test, 5, 4);
    return res;
}




int main()
{
    std::vector<std::function<bool()>> func;

    func.emplace_back(initializationByValueTestOne);
    func.emplace_back(initializationByValueTestTwo);
    func.emplace_back(initializationByValueTestThree);

    func.emplace_back(multiplyingByNumberTestOne);

    func.emplace_back(initializationByOneMainDiagonalTestOne);

    for(auto & i : func)
        i();
    return 0;
}
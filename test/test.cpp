/* WARNING!!! WARNING!!! WARNING!!!
 *
 * Пока поведение определено только при следующей сборке:
 * 1) GNU Compiler Collection
 * 2) Unix system
 *
 * */

//ужасное сравнение double

#include "test.h"

//вывод результатов теста
void printTestEqFailed(const std::string& name)
{
    std::cout << "\033[31m" << name << " =======  TEST FAILED " <<"\033[m \n";
}
void printTestEqSuccessful(const std::string& name)
{
    std::cout << "\033[32m" << name << " =======  TEST SUCCESSFUL " <<"\033[m \n";
}


//сравнение на равенство строк и чисел
template <typename T>
bool eqTemplate(T value1, T value2, const std::string& name)
{
    if (value1 == value2)
    {
        printTestEqSuccessful(name);
        return true;
    }
    else
    {
        printTestEqFailed(name);
        return false;
    }
}
bool eq(const std::string& value1, const std::string& value2, const std::string& name)
{
    return eqTemplate<std::string>(value1, value2, name);
}
bool eq(double value1, double value2, const std::string& name)
{
    return eqTemplate<double>(value1, value2, name);
}


//сравнение на равенство одномерных массивов
template <typename T>
bool eqArrayTemplate(T* mas1, T* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2)
{
    if (sizeMas1 != sizeMas2)
    {
        printTestEqFailed(name);
        return false;
    }
    else
    {
        for(int i = 0; i < sizeMas1; i++)
        {
            if (mas1[i] != mas2[i])
            {
                printTestEqFailed(name);
                return false;
            }
        }
    }
    printTestEqSuccessful(name);
    return true;
}
bool eqArray(int* mas1, int* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2)
{
    return eqArrayTemplate(mas1, mas2, name, sizeMas1, sizeMas2);
}
bool eqArray(double* mas1, double* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2)
{
    return eqArrayTemplate<>(mas1, mas2, name, sizeMas1, sizeMas2);
}






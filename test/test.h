/* WARNING!!! WARNING!!! WARNING!!!
 *
 * Пока поведение определено только при следующей сборке:
 * 1) GNU Compiler Collection
 * 2) Unix system
 *
 * */

//ужасное сравнение double

#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <string>
#include <iostream>
#include <cmath>
#include <cfloat>

#define ASSERT_EQ(value1, value2) eq(value1, value2, __func__ )

#define ASSERT_EQ_ARRAY(value1, value2, size1, size2) eqArray(value1, value2, __func__, size1, size2)

#define TEST(name) void __attribute__((constructor)) name()

// Вывод результатов теста
void printTestEqFailed(const std::string& name);
void printTestEqSuccessful(const std::string& name);



//сравнение на равенство строк и чисел
template <typename T>
bool eqTemplate(T value1, T value2, const std::string& name);
bool eq(const std::string& value1, const std::string& value2, const std::string& name);
bool eq(double value1, double value2, const std::string& name);


//сравнение на равенство одномерных массивов
template <typename T>
bool eqArrayTemplate(T* mas1, T* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2);
bool eqArray(int* mas1, int* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2);
bool eqArray(double* mas1, double* mas2, const std::string& name, size_t sizeMas1, size_t sizeMas2);
#endif

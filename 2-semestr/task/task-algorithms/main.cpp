#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v)
{
    for (const auto &iter: v)
    {
        std::cout << iter;
    }
    std::cout << std::endl;
}

void permutationsDirectOrder(unsigned char number)
{
    std::vector<int> v;
    for (int i = 1; i <= number; v.push_back(i++));
    do
    {
        printVector(v);
    }while(std::next_permutation(v.begin(), v.end()));
}

void permutationsReverseOrder(unsigned char number)
{
    std::vector<int> v;
    for (int i = number; i >= 1; v.push_back(i--));
    do
    {
        printVector(v);
    }while(std::prev_permutation(v.begin(), v.end()));
}

int main()
{
    permutationsDirectOrder(3);
    std::cout << std::endl;
    permutationsDirectOrder(4);
    std::cout << std::endl;
    permutationsDirectOrder(7);
    std::cout << std::endl;

    permutationsReverseOrder(3);
    std::cout << std::endl;
    permutationsReverseOrder(4);
    std::cout << std::endl;
    permutationsReverseOrder(7);
    std::cout << std::endl;

    return 0;
}
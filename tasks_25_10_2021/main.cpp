#include <iostream>
#include <cstdlib>

void initializationMasZero(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = 0;
    }
}

void initializationMasRand(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = (rand() - RAND_MAX / 2) % 32767;
    }
}

//minimal elements, their indexes, arithmetic average
void taskOne()
{
    const int size = 10;
    int* mas = new int[size];
    initializationMasRand(mas, size);
    std::cout << "mas: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;


    int min = mas[0];
    for(int i = 0; i < size; i++)
    {
        if (mas[i] < min) min = mas[i];
    }
    std::cout << "min: " << min << std::endl;

    std::cout << "index min: ";
    for(int i = 0; i < size; i++)
    {
        if (mas[i] == min) std::cout << i << " ";
    }
    std::cout << std::endl;

    double arAv = 0;
    for (int i = 0; i < size; i++)
    {
        arAv += mas[i];
    }
    std::cout << "arithmetic average: " << arAv / size << std::endl;

    for (int i = 0; i < size; i++)
    {
        if (mas[i] < arAv / size) std::cout << mas[i] << " ";
    }
    for (int i = 0; i < size; i++)
    {
        if (mas[i] >= arAv / size) std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

//random hex
void taskTwo()
{
    int x = 0;
    char mas[16] = {'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    std::cout << "Enter digit number: " << std::endl;
    std::cin >> x;
    for (int i = 0; i < x; i++)
    {
        std::cout << mas[rand() % 16];
    }
    std::cout << std::endl;
}

int main()
{
    //taskOne();
    taskTwo();
    return 0;
}

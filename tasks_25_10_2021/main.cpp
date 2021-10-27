#include <iostream>
#include <cstdlib>
#include <random>

void initializationMasZero(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = 0;
    }
}

void initializationMasRand(int* mas, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(-32767, 32767);
    for (int i = 0; i < size; i++)
    {
        mas[i] = uid(gen);
    }
}

//minimal elements, their indexes, arithmetic average
void taskOne()
{
    const int size = 11;
    int* mas = new int[size];
    initializationMasRand(mas, size);
    std::cout << "mas: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < (int)size / 2; i++)
    {
        int j = size - i - 1;
        int x = mas[i];
        mas[i] = mas[j];
        mas[j] = x;
    }
    std::cout << "mas reverse: ";
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

//the most common element
void taskThree()
{
    const int size = 10;
    int mas[size] = {4,2,3,3,2,1,4,4,4,1};
    int count = 0;
    int resIndex = 0;
    for (int i : mas)
    {
        int x = 0;
        for (int j : mas)
        {
            if (i == j) x++;
        }
        if (x > count)
        {
            count = x;
            resIndex = i;
        }
    }
    std::cout << "the most common element " << resIndex << std::endl;
}

//pairs in ascending order
void taskFour()
{
    const int size = 10;
    int* mas1 = new int[size];
    int* mas2 = new int[size];
    int* res = new int[size * 2];
    initializationMasRand(mas1, size);
    initializationMasRand(mas2, size);
    initializationMasZero(res, size * 2);

    std::cout << "mas first: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "mas second: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0, j = 0; i < size; i++, j += 2)
    {
        if(mas1[i] < mas2[i])
        {
            res[j] = mas1[i];
            res[j + 1] = mas2[i];
        }
        else
        {
            res[j] = mas2[i];
            res[j + 1] = mas1[i];
        }
    }

    std::cout << "mas result: ";
    for (int i = 0; i < size * 2; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //taskOne();
    //taskTwo();
    //taskThree();
    taskFour();
    return 0;
}

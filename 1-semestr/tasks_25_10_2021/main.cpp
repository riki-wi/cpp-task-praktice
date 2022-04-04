#include <iostream>
#include <random>

int randInt()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(-32767, 32767);
    return uid(gen);
}

int* initializationMasZero(int size)
{
    int* mas = new int[size];
    for (int i = 0; i < size; i++)
    {
        mas[i] = 0;
    }
    return mas;
}

int* initializationMasRand(int size)
{
    int* mas = new int[size];
    for (int i = 0; i < size; i++)
    {
        mas[i] = randInt();
    }
    return mas;
}

int** initializationTwoDimensionalMasRand(int n, int m)
{
    int** mas = new int*[n];
    for (int i = 0; i < n; i++)
    {
        mas[i] = initializationMasRand(m);
    }
    return mas;
}

void deleteTwoDimensionalMas(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete [] mas[i];
    }
    delete mas;
}

int* masReverse(const int* mas, int size)
{
    int* res = initializationMasZero(size);
    for (int i = 0; i < size; i++)
    {
        res[i] = mas[size - i - 1];
    }
    return res;
}

void masPrint(const int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

//minimal elements, their indexes, arithmetic average
void taskOne()
{
    const int size = 11;
    int* mas = initializationMasRand(size);
    std::cout << "mas: ";
    masPrint(mas, size);

    int* reverse = masReverse(mas, size);
    std::cout << "mas reverse: ";
    masPrint(reverse, size);

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

    delete [] mas;
    delete [] reverse;
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
        std::cout << mas[abs(randInt() % 16)];
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
    masPrint(mas, size);
    std::cout << "the most common element " << resIndex << std::endl;
}

//pairs in ascending order
void taskFour()
{
    const int size = 10;
    int* mas1 = initializationMasRand(size);
    int* mas2 = initializationMasRand(size);
    int* res = initializationMasZero(size * 2);

    std::cout << "mas first: ";
    masPrint(mas1, size);

    std::cout << "mas second: ";
    masPrint(mas2, size);

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
    masPrint(res, size);

    delete [] mas1;
    delete [] mas2;
    delete [] res;
}

//two-dimensional array (transposition, reverse order of the lines)
void taskFive()
{
    const int size = 5;
    int **mas = initializationTwoDimensionalMasRand(size, size);
    std::cout << "mas: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        masPrint(mas[i], size);
    }


    int** reverse_line = new int *[size];
    for (int i = 0; i < size; i++)
    {
        reverse_line[i] = masReverse(mas[i], size);
    }
    std::cout << std::endl;
    std::cout << "mas revers line: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        masPrint(reverse_line[i], size);
    }


    int** transposition = new int*[size];
    for (int i = 0; i < size; i++)
    {
        transposition[i] = initializationMasZero(size);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            transposition[i][j] = mas[j][i];
        }
    }
    std::cout << std::endl;
    std::cout << "mas transposition: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        masPrint(transposition[i], size);
    }

    deleteTwoDimensionalMas(mas, size);
    deleteTwoDimensionalMas(transposition, size);
    deleteTwoDimensionalMas(reverse_line, size);
}

int main()
{
    std::cout << "task one: " << std::endl;
    taskOne();

    std::cout << std::endl << std::endl;
    std::cout << "task two: " << std::endl;
    taskTwo();

    std::cout << std::endl << std::endl;
    std::cout << "task three: " << std::endl;
    taskThree();

    std::cout << std::endl << std::endl;
    std::cout << "task four: " << std::endl;
    taskFour();

    std::cout << std::endl << std::endl;
    std::cout << "task five: " << std::endl;
    taskFive();
    return 0;
}

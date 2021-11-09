#include <iostream>

void printMas(const int* mas, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << *(mas + j + i * m) << " ";
        }
        std::cout << std::endl;
    }
}

void printMasAddress(int* mas, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << (mas + j + i * m) << " ";
        }
        std::cout << std::endl;
    }
}

// integral image task
void integralImage(int* mas, int n, int m)
{
    for(int i = 1; i < n; i++)
    {
        *(mas + i * n) += *(mas + (i - 1) * n);
    }
    for(int i = 1; i < m; i++)
    {
        *(mas + i) += *(mas + i - 1);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            *(mas+ j + i * m) += *(mas + j - 1 + i * m) +
                    *(mas + j + (i - 1) * m) - *(mas + j - 1 + (i - 1) * m);
        }
    }
}

//find in sort mas helper
int* findInSortMasHelper(int* mas, int f, int left, int right)
{
    int* res;
    if (left > right) return nullptr;
    int middle = left + (right - left) / 2;
    if (f < *(mas + middle))
    {
        return findInSortMasHelper(mas, f, left, middle);
    }
    else if (f > *(mas + middle))
    {
        return findInSortMasHelper(mas, f, middle, right);
    }
    else
    {
        res = (mas + middle);
        //std::cout << res << " ";
        return res;
    }
}

//find and sort mas task
int* findInSortMas(int* mas, int n, int m, int f)
{
    return findInSortMasHelper(mas, f, 0, m * n);
}


int* findInSortDiagonalMas(int* mas, int n, int m, int i, int j, int date)
{
    int* res = nullptr;
    for(int k = i, s = j; k < n, s < m; k++, s++)
    {
        if (*(mas + k * m + s) == date)
        {
            res = (mas + k * m + s);
            return res;
        }
        else if (*(mas + k * m + s) > date)
        {
            return findInSortDiagonalMas(mas, n, m, 0, s, date);
        }
    }
    return res;
}

// one and zero task
void oneAndZero(int* mas, int n, int m)
{

}

int main()
{
    //task one
    int mas[4][4] = {
            {4, 5, 2, 1},
            {0, 9, 3, 2},
            {5, 6, 8, 1},
            {2, 3, 0, 0},
    };
    std::cout << "original mas: " << std::endl;
    printMas(&mas[0][0], 4, 4);
    std::cout << std::endl;
    std::cout << "integral mas: " << std::endl;
    integralImage(&mas[0][0], 4, 4);
    printMas(&mas[0][0], 4, 4);
    std::cout << "===============";
    std::cout << std::endl;

    //task two
    int mas2[5][5] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };
    std::cout << "original mas: " << std::endl;
    printMas(&mas2[0][0], 5, 5);
    std::cout << std::endl;
    std::cout << "original mas address: " << std::endl;
    printMasAddress(&mas2[0][0], 5, 5);
    std::cout << std::endl;
    for(int i = 1; i <= 25; i++)
    {
        std::cout << "find in sort mas: " << i << " " << findInSortMas(&mas2[0][0], 5, 5, i) << " ";
        std::cout << "find in sort mas with diagonal:  " << i << " " << findInSortDiagonalMas(&mas2[0][0], 5, 5, 0, 0, i) << std::endl;
    }
    std::cout << "===============";
    std::cout << std::endl;
    std::cout << std::endl;

    //task three
    int mas3[4][5] = {
            {1, 0, 0, 1, 1},
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 1, 0, 0},
    };
    std::cout << "original mas: " << std::endl;
    printMas(&mas3[0][0], 4, 5);
    std::cout << std::endl;
    std::cout << "original mas address: " << std::endl;
    printMasAddress(&mas3[0][0], 4, 5);
    std::cout << std::endl;
    std::cout << "max one mas: " << std::endl;
    oneAndZero(&mas3[0][0], 4, 5);

    return 0;
}

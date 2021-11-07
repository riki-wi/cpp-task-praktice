#include <iostream>

void printMas(int* mas, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << mas[j + i * m] << " ";
        }
        std::cout << std::endl;
    }
}

// integral image task
void integralImage(int* mas, int n, int m)
{
    for(int i = 1; i < n; i++)
    {
        mas[i * n] += mas[(i - 1) * n];
    }
    for(int i = 1; i < m; i++)
    {
        mas[i] += mas[i - 1];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            mas[j + i * m] += mas[j - 1 + i * m] + mas[j + (i - 1) * m] - mas[j - 1 + (i - 1) * m];
        }
    }
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
    return 0;
}

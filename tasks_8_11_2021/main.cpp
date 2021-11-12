#include <iostream>

int** creatIndependentTwoDimensionalMas(int n, int m)
{
    int** mas = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mas[i] = new int[m]{0};
    }
    return mas;
}

int** createDependentTwoDimensionalMas(int n, int m)
{
    int* mas = new int[n * m]{0};
    int** masAdd = new int*[n];
    for(int i = 0, j = 0; i < n * m; i += m, j++)
    {
        masAdd[j] = &mas[i];
    }
    return masAdd;
}

void printDimensionalMas(int** mas, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            std::cout << mas[i][j] << " " << "\t";
        std::cout << std::endl;
    }
}

void deleteDimensionMas(int** mas, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete [] mas[i];
    delete [] mas;
}

//filling an array with a snake
void snake(int** mas, int n, int m)
{
    int date = 0;
    for(int i = 0, sign = 0; i < n; i++, sign++)
    {
        if(!(sign % 2))
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = date;
                date++;
            }
        else
            for(int j = m - 1; j >= 0; j--)
            {
                mas[i][j] = date;
                date++;
            }
    }

    printDimensionalMas(mas, n, m);
    deleteDimensionMas(mas, n, m);
}

//filling an array with diagonal a snake
void snakeDiagonal(int** mas, int n, int m)
{

}


//filling an array with diagonal a snake
void snakeCenter(int** mas, int n, int m)
{
    int date = 0;
    for(int i = 0, mJ = 0; i < m / 2; mJ++, i++)
    {
        for(int j = i; j < m - i; j++)
        {
            mas[i][j] = date;
            date++;
        }
        for(int j = mJ + 1; j < n - mJ; j++)
        {
            mas[j][m - mJ - 1] = date;
            date++;
        }
        for(int j = m - mJ - 2; j > mJ; j--)
        {
            mas[n - mJ - 1][j] = date;
            date++;
        }
        for(int j = n - 1 - mJ; j > mJ; j--)
        {
            mas[j][mJ] = date;
            date++;
        }
    }
    if((n == m) && (n % 2))
        mas[n / 2][m / 2] = date;
    printDimensionalMas(mas, n, m);
}


int main()
{
    int n;
    int m;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    std::cout << "Enter number of columns: ";
    std::cin >> m;

    snake(creatIndependentTwoDimensionalMas(n, m), n, m);

    std::cout << std::endl;
    std::cout << std::endl;
    snakeDiagonal(createDependentTwoDimensionalMas(n, m), n, m);

    std::cout << std::endl;
    std::cout << std::endl;
    snakeCenter(createDependentTwoDimensionalMas(n, m), n, m);
}

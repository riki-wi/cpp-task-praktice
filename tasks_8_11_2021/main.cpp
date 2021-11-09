#include <iostream>

int** creatIndependentTwoDimensionalMas(int n, int m)
{
    int** mas = new int*[m];
    for(int i = 0; i < n; i++)
    {
        mas[i] = new int[m];
    }
    return mas;
}

int** createDependentTwoDimensionalMas(int n, int m)
{
    int* mas = new int[n * m];
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


}

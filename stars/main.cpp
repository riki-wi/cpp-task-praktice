#include <iostream>


void right(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = n - i - 1; k > 0; k--)
        {
            std::cout << " ";
        }
        for(int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void left(int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void upsideDown(int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = n - i; j > 0; j--)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void center(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = (n - i); j > 0; j--)
        {
            std::cout << " ";
        }

        for (int k = 0; k < 2 * i - 1; k++ )
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = (n - i); j > 0; j--)
        {
            std::cout << " ";
        }

        for (int k = 0; k < 2 * i - 1; k++ )
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }
}

int main() {
    int n = 0;
    std :: cin >> n;
    left(n);
    std::cout << "==========" << std::endl;
    std::cout << "\n";

    upsideDown(n);
    std::cout << "==========" << std::endl;
    std::cout << "\n";

    right(n);
    std::cout << "==========" << std::endl;
    std::cout << "\n";

    center(n);
    std::cout << "==========" << std::endl;
    std::cout << "\n";

}
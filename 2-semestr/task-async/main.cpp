#include <iostream>
#include <future>
#include <cmath>

const int N = 1000000;
const int n = N+1;
double PI = 0;

int block_size(int threads)
{
    return n / threads + (n % threads ? 1 : 0);
}

void pi_block(int threads, int first_index)
{
    int bl_size = block_size(threads);
    for(int i = first_index; i < std::min(first_index + bl_size, n); i++)
    {
        PI += std::sqrt(12) * std::pow(-1, i) / ((2.0 * i + 1) * std::pow(3, i));
    }
}

void pi(int threads)
{
    int bl_size = block_size(threads);
    int first_index = 0;
    while(first_index < n)
    {
        std::future<void> f1 = std::async(pi_block, threads, first_index);
        first_index += bl_size;
        f1.get();
    }
}

//------------------------------------------------------------------------------------------------------


int main()
{
    pi(100);
    std::cout << std::fixed;
    std::cout.precision(16);
    std::cout << "pi = " << PI << std::endl;

    //---------------------------------------------



    return 0;
}
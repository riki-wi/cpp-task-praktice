#include <iostream>
#include <future>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>

const int N = 1000000;
const int n = N+1;

int block_size(int threads)
{
    return n / threads + (n % threads ? 1 : 0);
}

//------------------------------------------------------------------------------------------------------

double pi_block(int threads, int first_index)
{
    double pi = 0;
    int bl_size = block_size(threads);
    for(int i = first_index; i < std::min(first_index + bl_size, n); i++)
    {
        pi += std::sqrt(12) * std::pow(-1, i) / ((2.0 * i + 1) * std::pow(3, i));
    }
    return pi;
}

double pi(int threads)
{
    double p = 0;
    int bl_size = block_size(threads);
    int first_index = 0;
    while(first_index < n)
    {
        std::future<double> f1 = std::async(pi_block, threads, first_index);
        first_index += bl_size;
        p += f1.get();
    }
    return p;
}

//------------------------------------------------------------------------------------------------------

int block(int threads, int len)
{
    int temp = len / threads;
    int m = floor(temp / 16);
    return 16 * (m + (len % threads ? 1 : 0));
}

int mod_block(const std::string& str, int threads, int first_index)
{
    int len = static_cast<int>(str.length());
    int bl_size = block(threads, len);
    int r = 0;
    std::string temp = str.substr(first_index, std::min(first_index + bl_size, len - 1));
    for(auto &i : temp)
    {
        r = r * 10 + ((int)i - '0');
        i = static_cast<char>(std::floor((r / 17))) + '0';
        r %= 17;
    }
    return r;
}

long long mod(const std::string& str, int threads)
{
    long long mod = 0;
    std::vector<std::future<int>> fut(threads);
    int len = static_cast<int>(str.length());

    int bl_size = block(threads, len);
    std::string temp(str.rbegin(), str.rend());

    int first_index = 0;
    while(first_index < len)
    {
        auto v = std::async(mod_block, str, threads, first_index);
        fut.push_back(std::move(v));
        first_index += bl_size;
    }

    for(auto& j : fut)
    {
        mod += j.get();
    }

    return mod;
}

//------------------------------------------------------------------------------------------------------

void sum_block(int threads, int first_index)
{}


void sum(const std::string& str, int threads)
{
    int bl_size = block_size(threads);
    int first_index = 0;
    while(first_index < n)
    {
        std::future<void> f1 = std::async(sum_block, threads, first_index);
        first_index += bl_size;
        f1.get();
    }
}

//------------------------------------------------------------------------------------------------------

int Find(const std::string& what, const std::string& s, int a, int b)
{

}

int Find_thread(const std::string& what, const std::string& s, int threads, int first_index)
{

}

int MultiThreadFind(const std::string& what, const std::string& s, int threads)
{
    int count = 0;
    int bl_size = block_size(threads);
    int first_index = 0;
    while(first_index < n)
    {
        std::future<int> f1 = std::async(Find_thread, what, s, threads, first_index);
        first_index += bl_size;
        count += f1.get();
    }
    return count;
}

//------------------------------------------------------------------------------------------------------

int main()
{
    std::cout << std::fixed;
    std::cout.precision(16);
    std::cout << "pi = " << pi(100) << std::endl;

    //---------------------------------------------

    std::cout << mod("99999999999999999999999999999999", 2);



    return 0;
}
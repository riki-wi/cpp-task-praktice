#include <iostream>
#include <future>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>


const int N = 1000000;
const int n = N + 1;

int block_size(int threads)
{
    return n / threads + (n % threads ? 1 : 0);
}

double pi_block(int threads, int first_index)
{
    double pi = 0;
    int bl_size = block_size(threads);
    for (int i = first_index; i < std::min(first_index + bl_size, n); i++)
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
    while (first_index < n)
    {
        std::future<double> f1 = std::async(pi_block, threads, first_index);
        first_index += bl_size;
        p += f1.get();
    }
    return p;
}

//------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------

int sum_block(const std::string &str, int a, int b)
{
    int sum = 0;
    std::string tmp = str.substr(a, b);
    std::stringstream st;
    int x = 0;
    st << tmp;
    while (st >> x)
    {
        sum = sum + x;
    }
    return sum;
}


long long sum(const std::string &str, int threads)
{
    long long s = 0;
    std::vector<int> vec_space;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            vec_space.push_back(i);
        }
    }
    int shift = vec_space.size() / threads;
    int i = 0;
    int j = shift;
    while (threads)
    {
        if (threads == 1)
        {
            std::future<int> f1 = std::async(sum_block, str, i, str.length() - 1);
            s += f1.get();
            threads--;
            break;
        }
        std::future<int> f1 = std::async(sum_block, str, i, vec_space[j] - i);
        i = vec_space[j];
        j = j + shift;

        s += f1.get();
        threads--;
    }
    return s;
}

//------------------------------------------------------------------------------------------------------

int block_size_length(const std::string &s, int threads)
{
    return s.length() / threads + (s.length() % threads ? 1 : 0);
}

int Find(const std::string &what, const std::string &s, int a, int b)
{
    std::string temp;
    int count = 0;
    if ((b - a + s.length() - 1) > what.length())
    {
        temp = what.substr(a);
    } else
    {
        temp = what.substr(a, b - a + s.length() - 1);
    }

    for (int i = 0; i < temp.length(); i++)
    {
        if (!temp.substr(i, s.length()).compare(s))
        {
            count++;
        }
    }
    return count;
}

int Find_thread(const std::string &what, const std::string &s, int threads, int first_index)
{
    int last_index = 0;
    if ((first_index + block_size_length(what, threads)) > what.length())
    {
        last_index = what.length() - 1;
    } else
    {
        last_index = first_index + block_size_length(what, threads);
    }
    return Find(what, s, first_index, last_index);
}

int MultiThreadFind(const std::string &what, const std::string &s, int threads)
{
    int count = 0;
    int bl_size = block_size_length(what, threads);
    int first_index = 0;
    while (first_index < what.length())
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

    std::cout << sum("1 2 3 4 5 6 7 8 9 10 11 12 13 14", 4) << std::endl;
    std::cout << sum("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", 4) << std::endl;
    std::cout << sum("100 1000 10000 1 2 3 4 5 6 7 8 9 10", 5) << std::endl;

    //---------------------------------------------

    std::cout << MultiThreadFind(std::string("aaaaaaaaaaaaaaa"), "a", 3) << std::endl;
    std::cout << MultiThreadFind(std::string("aaaaaaaaaaaaaa"), "a", 2) << std::endl;
    std::cout << MultiThreadFind("aaaa", "aa", 2) << std::endl;
    std::cout << MultiThreadFind("abaabababab", "aba", 2) << std::endl;

    return 0;
}
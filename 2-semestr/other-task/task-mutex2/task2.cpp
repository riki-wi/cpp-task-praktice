#include <vector>
#include <chrono>
#include <thread>
#include <random>
#include "struct.h"

Threadsafe_queue<int> q_safe;
bool work1_safe = true;
bool work2_safe = true;
std::vector<int> v1_safe;
std::vector<int> v2_safe;

std::mt19937 mt_safe;
std::uniform_int_distribution<int> r_safe(1, 100000);

void factory_safe()
{
    while (work1_safe)
    {
        if (!q_safe.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            int temp = r_safe(mt_safe);
            q_safe.push(temp);
            v1_safe.push_back(temp);
        }
    }
}

void consumer_safe()
{
    while (work2_safe)
    {
        if (q_safe.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            int temp;
            q_safe.wait_and_pop(temp);
            v2_safe.push_back(temp);
        }
    }
}

bool check_all_safe()
{
    std::thread t1(factory_safe);
    std::thread t2(factory_safe);
    std::thread t3(consumer_safe);
    std::thread t4(consumer_safe);
    std::thread t5(consumer_safe);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    work1_safe = false;
    work2_safe = false;

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    if(!q_safe.empty())
    {
        int temp;
        q_safe.wait_and_pop(temp);
        v2.push_back(temp);
    }


    if (v1_safe.size() != v2_safe.size())
    {
        return false;
    }

    for (int i = 0; i < v1_safe.size(); i++)
    {
        if (v1_safe[i] != v2_safe[i])
        {
            return false;
        }
    }
    return true;
}
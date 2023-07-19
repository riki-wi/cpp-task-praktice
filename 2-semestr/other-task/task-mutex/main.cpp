#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <mutex>

int object;
bool flag = false;
bool work1 = true;
bool work2 = true;
std::vector<int> v1;
std::vector<int> v2;

std::mt19937 mt;
std::uniform_int_distribution<int> r(1, 100000);
std::uniform_int_distribution<int> r_second(1, 5);

std::mutex m;

void factory()
{
    while(work1)
    {
        if(flag)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            object = r(mt);
            v1.push_back(object);
            flag = true;
        }
    }
}

void consumer()
{
    while(work2)
    {
        if(!flag)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            v2.push_back(object);
            flag = false;
        }
    }
}

bool check_all()
{
    std::thread t1(factory);
    std::thread t2(factory);
    std::thread t3(consumer);
    std::thread t4(consumer);
    std::thread t5(consumer);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    work1 = false;
    work2 = false;

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    if(v1.size() != v2.size())
    {
        return false;
    }

    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

void factory_m()
{
    while(work1)
    {
        m.lock();
        if(flag)
        {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            object = r(mt);
            v1.push_back(object);
            flag = true;
            m.unlock();
        }
    }
}

void consumer_m()
{
    while(work2)
    {
        m.lock();
        if(!flag)
        {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            v2.push_back(object);
            flag = false;
            m.unlock();
        }
    }
}

bool check_all_m()
{
    std::thread t1(factory_m);
    std::thread t2(factory_m);
    std::thread t3(consumer_m);
    std::thread t4(consumer_m);
    std::thread t5(consumer_m);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    work1 = false;
    work2 = false;

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for(int i = 0; i < 20; i++)
    {
        std::cout << check_all();
    }

    std::cout << std::endl;
    for(int i = 0; i < 20; i++)
    {
        std::cout << check_all_m();
    }

    return 0;
}
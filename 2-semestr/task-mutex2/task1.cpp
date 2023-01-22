#pragma one

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <mutex>
#include <queue>
#include <condition_variable>

std::queue<int> q;
bool work1 = true;
bool work2 = true;
std::vector<int> v1;
std::vector<int> v2;

std::mt19937 mt;
std::uniform_int_distribution<int> r(1, 100000);
std::uniform_int_distribution<int> r_second(1, 5);

std::mutex m;

std::condition_variable cv;

void factory()
{
    while (work1)
    {
        if (!q.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            q.push(r(mt));
            v1.push_back(q.front());
        }
    }
}

void consumer()
{
    while (work2)
    {
        if (q.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            v2.push_back(q.front());
            q.pop();
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

    if(!q.empty())
    {
        v2.push_back(q.front());
        q.pop();
    }

    if (v1.size() != v2.size())
    {
        return false;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

void factory_m()
{
    while (work1)
    {
        m.lock();
        if (!q.empty())
        {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            q.push(r(mt));
            v1.push_back(q.front());
            m.unlock();
        }
    }
}

void consumer_m()
{
    while (work2)
    {
        m.lock();
        if (q.empty())
        {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(r_second(mt)));
        } else
        {
            v2.push_back(q.front());
            q.pop();
            m.unlock();
        }

    }
}

bool check_all_m()
{
    work2 = true;
    work1 = true;
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

    if(!q.empty())
    {
        v2.push_back(q.front());
        q.pop();
    }

    if (v1.size() != v2.size())
    {
        return false;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

bool not_empty()
{
    return !q.empty();
}

bool empty()
{
    return q.empty();
}

void factory_v()
{
    while (work1)
    {

        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, empty);
        q.push(r(mt));
        v1.push_back(q.front());
        cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds (10));
    }
}

void consumer_v()
{
    while (work2)
    {

        std::unique_lock<std::mutex> l(m);
        cv.wait(l, not_empty);
        v2.push_back(q.front());
        q.pop();
        cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds (10));
    }
}

bool check_all_v()
{
    work2 = true;
    work1 = true;
    std::thread t1(factory_v);
    std::thread t2(factory_v);
    std::thread t3(consumer_v);
    std::thread t4(consumer_v);
    std::thread t5(consumer_v);

    std::this_thread::sleep_for(std::chrono::seconds (1));
    work1 = false;
    work2 = false;

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    if (v1.size() != v2.size())
    {
        return false;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

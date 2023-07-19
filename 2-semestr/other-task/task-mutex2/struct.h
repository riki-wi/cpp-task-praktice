#pragma one

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <stack>
#include <deque>

template<class T>
class Threadsafe_queue
{
private:
    std::queue<T> q;
    std::mutex m;
    std::condition_variable cv;

public:
    void push(T value)
    {
        std::lock_guard<std::mutex> l(m);
        q.push(value);
    }
    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> l(m);

        cv.wait(l, [this]
        { return !q.empty(); });
        value = q.front();
        q.pop();
        cv.notify_one();
    }
    bool empty()
    {
        std::lock_guard<std::mutex> l(m);
        return q.empty();
    }
};

template<class T>
class Threadsafe_stack
{
private:
    std::stack<T> s;
    std::mutex m;
    std::condition_variable cv;

public:
    void push(T value)
    {
        std::lock_guard<std::mutex> l(m);
        s.push(value);
    }
    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> l(m);

        cv.wait(l, [this]
        { return !s.empty(); });
        value = s.front();
        s.pop();
        cv.notify_one();
    }
    bool empty()
    {
        std::lock_guard<std::mutex> l(m);
        return s.empty();
    }
};

template<class T>
class Threadsafe_dequeue
{
private:
    std::deque<T> dq;
    std::mutex m;
    std::condition_variable cv_front;
    std::condition_variable cv_back;

public:
    void push_front(T value)
    {
        std::lock_guard<std::mutex> l(m);
        dq.push_front(value);
    }

    void push_back(T value)
    {
        std::lock_guard<std::mutex> l(m);
        dq.push_back(value);
    }

    void wait_and_pop_front(T &value)
    {
        std::unique_lock<std::mutex> l(m);

        cv_front.wait(l, [this]
        { return !dq.empty(); });
        value = dq.front();
        dq.pop_front();
        cv_front.notify_one();
    }

    void wait_and_pop_back(T &value)
    {
        std::unique_lock<std::mutex> l(m);

        cv_back.wait(l, [this]
        { return !dq.empty(); });
        value = dq.back();
        dq.pop_back();
        cv_back.notify_one();
    }

    bool empty()
    {
        std::lock_guard<std::mutex> l(m);
        return dq.empty();
    }
};

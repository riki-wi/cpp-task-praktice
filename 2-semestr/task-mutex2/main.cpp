#include "task1.cpp"
#include "task2.cpp"


int main()
{
    std::cout << check_all_safe();

    std::cout << std::endl;

    for(auto &i : v1_safe)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl << "----------------------------" << std::endl;

    for(auto &i : v2_safe)
    {
        std::cout << i << " ";
    }

    Threadsafe_dequeue<int> dq;
    Threadsafe_stack<int> s;

    std::cout << dq.empty();
    std::cout << s.empty();

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);

    std::cout << dq.empty();
    return 0;
}
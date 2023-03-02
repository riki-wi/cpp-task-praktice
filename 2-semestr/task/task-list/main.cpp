#include "src/Book.h"

int main()
{

    std::list<Book> list;
    list.emplace_back("Bjarne Stroustrup", "The C++ Programming Language", "Binom", 4, 2017, 1136);
    list.emplace_back("Scott Meyers", "Effective using of STL", "Piter", 1, 2002, 224);
    list.emplace_back("Robert Sedgewick", "Algorithms in C++", " Williams", 3, 2019, 1056);
    list.emplace_back("Scott Meyers", "Effective using of STL", "Piter", 1, 2002, 224);
    list.emplace_back("Bjarne Stroustrup", "The C++ Programming Language", "Binom", 4, 2017, 1136);
    list.emplace_back("Scott Meyers", "Effective using of STL", "Piter", 1, 2002, 224);

    printInfo(list);

    std::cout << "---------------------------------------------" << std::endl;

    printSortInfo(list);


    return 0;
}
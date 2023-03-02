#include <list>
#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

enum Data
{
    EDITION, YEAR, PAGES, SIZE_DATA
};

class Book
{
private:
    std::string author_;
    std::string title_;
    std::string publisher_;

    std::vector<size_t> data_;

public:
    Book(std::string author, std::string title,std::string publisher, size_t edition, size_t year, size_t pages);

    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    bool operator==(const Book& right) const;

    bool operator<(const Book& right) const;
};

std::map<Book, size_t> infoAboutCount(const std::list<Book> &list);

void printInfo(const std::list<Book> &list);

void printSortInfo(const std::list<Book> &list);

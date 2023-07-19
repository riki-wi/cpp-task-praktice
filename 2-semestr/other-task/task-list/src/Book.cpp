#include "Book.h"

Book::Book(std::string author, std::string title, std::string publisher, size_t edition,
           size_t year, size_t pages): author_(std::move(author)), title_(std::move(title)), publisher_(std::move(publisher))
{
    data_.resize(SIZE_DATA);
    data_[EDITION] = edition;
    data_[YEAR] = year;
    data_[PAGES] = pages;
}

std::ostream &operator<<(std::ostream &os, const Book &book)
{

    os << book.author_ << " " << book.title_ << " " << book.publisher_ << " " << book.data_[EDITION] << " " << book.data_[YEAR] << " " << book.data_[PAGES];
    return os;
}

bool Book::operator==(const Book &right) const
{
    return (this->author_ == right.author_ && this->title_ == right.title_ && this->publisher_ == right.publisher_
            && this->data_[EDITION]) == right.data_[EDITION] && this->data_[YEAR] == right.data_[YEAR] && this->data_[PAGES] == right.data_[PAGES];
}

bool Book::operator<(const Book &right) const
{
    return (this->author_.compare(right.author_) < 0);
}

std::map<Book, size_t> infoAboutCount(const std::list<Book> &list)
{

    std::map<Book, size_t> mapCount;

    for(const auto & iter : list)
    {

        auto book = mapCount.find(iter);
        if(book != mapCount.end())
        {
            book->second = book->second + 1;
        } else
        {
            mapCount.insert(std::pair<Book, size_t>(iter, 1));
        }
    }
    return mapCount;
}

void printInfo(const std::list<Book> &list)
{
    std::map<Book, size_t> map = infoAboutCount(list);
    for(const auto & iter : map)
    {
        std::cout << iter.first << " " << iter.second << std::endl;
    }
}

void printSortInfo(const std::list<Book> &list)
{

    std::map<Book, size_t> map = infoAboutCount(list);
    std::vector<std::pair<Book, size_t>> vectorCount;
    vectorCount.reserve(map.size());

    for(const auto & iter: map)
    {
        vectorCount.emplace_back(iter);
    }

    auto cmp = [](std::pair<Book, size_t> const &left, std::pair<Book, size_t> const &right)
    {
        return left.second < right.second;
    };

    std::sort(vectorCount.begin(), vectorCount.end(), cmp);

    for(const auto & iter : vectorCount)
    {
        std::cout << iter.first << " " << iter.second << std::endl;
    }
}
#include <iostream>
#include <algorithm>


template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
    std::string prefix_;
    prefix_[0] = prefix;

    RandomIt left_iter = std::lower_bound(range_begin, range_end, prefix_,
                                          [](const std::string &l, const std::string &r)
                                          {
                                              return l[0] < r[0];
                                          });

    RandomIt right_iter = std::upper_bound(range_begin, range_end, prefix_,
                                           [](const std::string &l, const std::string &r)
                                           {
                                               return l[0] < r[0];
                                           });

    return std::make_pair(left_iter, right_iter);
}

bool lower_comparator(const std::string &left, const std::string &right)
{

    if (right.size() > left.size())
    {
        return left < right;
    }

    const size_t size = std::min(right.size(), left.size());

    return left.substr(0, size) < right.substr(0, size);
}


bool upper_comparator(const std::string &left, const std::string &right)
{

    if (left.size() > right.size())
    {
        return left < right;
    }

    const size_t size = std::min(right.size(), left.size());

    return left.substr(0, size) < right.substr(0, size);
}

template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string &prefix)
{
    RandomIt left_iter = std::lower_bound(range_begin, range_end, prefix, lower_comparator);

    RandomIt right_iter = std::upper_bound(range_begin, range_end, prefix, upper_comparator);

    return std::make_pair(left_iter, right_iter);
}

int main()
{
    /*const std::vector<std::string> sorted_strings = {"moscow", "murmansk",
                                                     "vologda"};
    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    std::cout << (p_result.first - begin(sorted_strings)) << " " <<
              (p_result.second - begin(sorted_strings)) << std::endl;
    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    std::cout << (z_result.first - begin(sorted_strings)) << " " <<
              (z_result.second - begin(sorted_strings)) << std::endl;
    return 0;*/

    const std::vector<std::string> sorted_strings = {"moscow", "motovilikha",
                                                     "murmansk"};
    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
              (mt_result.second - begin(sorted_strings)) << std::endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    std::cout << (na_result.first - begin(sorted_strings)) << " " <<
              (na_result.second - begin(sorted_strings)) << std::endl;
    return 0;
}
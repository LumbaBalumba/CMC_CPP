#include <functional>
#include <iostream>
#include <vector>
#include <iterator>


template<class T, class F>
void
myapply(T begin, T end, F func)
{
    for (auto it = begin; it != end; ++it) {
        func(*it);
    }
}

template<class T, class F>
std::vector<std::reference_wrapper<typename std::iterator_traits<T>::value_type>>
myfilter2(T begin, T end, F func)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<T>::value_type>> res{};
    for (auto it = begin; it != end; ++it) {
        if (func(*it)) {
            res.push_back(std::reference_wrapper(*it));
        }
    }
    return res;
}


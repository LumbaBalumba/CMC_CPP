//
// Created by i3alumba on 27.03.23.
//
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

template<class T>
T
my_min(
        T begin,
        T end,
        std::function<bool(
                const typename std::iterator_traits<T>::value_type &,
                const typename std::iterator_traits<T>::value_type &)> func)
{
    T res = begin;
    for (auto it = begin; it != end; ++it) {
        if (func(*it, *res)) {
            res = it;
        }
    }
    return res;
}


template<class T>
void
selection_sort(
        T begin,
        T end,
        std::function<bool(
                const typename std::iterator_traits<T>::value_type &,
                const typename std::iterator_traits<T>::value_type &)> func)
{
    for (T it = begin; it != end; ++it) {
        T new_it = my_min(it, end, func);
        std::swap(*it, *new_it);
    }
}

template<class T>
T
my_min(T begin, T end)
{
    T res = begin;
    for (auto it = begin; it != end; ++it) {
        if (*it < *res) {
            res = it;
        }
    }
    return res;
}

template<class T>
void
selection_sort(T begin, T end)
{
    for (T it = begin; it != end; ++it) {
        T new_it = my_min(it, end);
        std::swap(*it, *new_it);
    }
}
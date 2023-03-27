//
// Created by i3alumba on 27.03.23.
//
#include <iostream>
#include <functional>

template<class T>
T
myfilter(const T &container, std::function<bool(typename T::value_type)> filter)
{
    T res{};
    for (auto &elem: container) {
        if (filter(elem)) {
            res.insert(res.end(), elem);
        }
    }
    return res;
}
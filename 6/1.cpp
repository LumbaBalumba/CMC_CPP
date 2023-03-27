//
// Created by i3alumba on 27.03.23.
//
#include <iostream>

template<class T>
T::value_type
process(const T &container)
{
    typename T::value_type res{};
    size_t index = 0;
    for (auto it = container.rbegin(); it != container.rend(); ++it, ++index) {
        if (index == 0 || index == 2 || index == 4) {
            res += *it;
        }
    }
    return res;
}
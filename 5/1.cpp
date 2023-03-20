//
// Created by i3alumba on 20.03.23.
//
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

unsigned
bits(unsigned num)
{
    unsigned res = 0;
    for (size_t i = 0; i < sizeof(num) * CHAR_BIT; ++i) {
        res += (num >> i) & 1;
    }
    return res;
}

int
main()
{
    std::vector<unsigned> v;
    unsigned a;
    while (std::cin >> a) {
        v.push_back(a);
    }
    std::stable_sort(v.begin(), v.end(), [](unsigned a, unsigned b) {
        return bits(a) < bits(b);
    });
    for (auto &elem: v) {
        std::cout << elem << std::endl;
    }
}
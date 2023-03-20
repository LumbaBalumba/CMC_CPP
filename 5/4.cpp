#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

constexpr unsigned long long mod = 4294967161;

int
main()
{
    std::map<std::pair<unsigned, unsigned>, unsigned long long> mp;
    unsigned i, j;
    unsigned long long val;
    while (std::cin >> i >> j >> val && (i || j || val != mod)) {
        mp[{ i, j }] = val;
    }
    while (std::cin >> i >> j >> val) {
        mp[{ i, j }] += val;
        mp[{ i, j }] %= mod;
    }
    for (auto &el: mp) {
        if (el.second) {
            std::cout << el.first.first << " " << el.first.second << " " << el.second << std::endl;
        }
    }
}
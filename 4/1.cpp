#include <vector>
#include <iostream>

void
process(const std::vector<unsigned long> &src, std::vector<unsigned long> &dest, long step)
{
    auto it1 = src.begin();
    for (auto it2 = dest.rbegin();
        it1 < src.end() && it2 < dest.rend(); it1 += step, it2++) {
        *it2 += *it1;
    }
}
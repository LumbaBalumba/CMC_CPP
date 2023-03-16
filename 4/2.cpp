#include <vector>

void
process(std::vector<long> &v, long value)
{
    long cnt = 0;
    for (auto elem: v) {
        if (elem >= value) {
            ++cnt;
        }
    }
    v.reserve(v.size() + cnt);
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        if (*it >= value) {
            v.push_back(*it);
        }
    }
}


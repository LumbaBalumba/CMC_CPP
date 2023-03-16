#include <vector>
#include <algorithm>

void
process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> tmp = v1;
    std::sort(tmp.begin(), tmp.end(), [](int a, int b) { return a > b; });
    auto tmp_it = std::unique(tmp.begin(), tmp.end());
    for (auto it = tmp.begin(); it < tmp_it; ++it) {
        if (v2.begin() + *it < v2.end() && *it >= 0) {
            v2.erase(v2.begin() + *it);
        }
    }
}
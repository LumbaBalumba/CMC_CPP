#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

constexpr uint64_t mod = 4294967161;

int
main()
{
    std::map<uint32_t, std::map<uint32_t, uint64_t>> fir;
    uint32_t i, j;
    uint64_t val;
    while (std::cin >> i >> j >> val) {
        if (!i && !j && val == mod) {
            break;
        }
        fir[i][j] = val;
    }
    std::map<uint32_t, std::map<uint32_t, uint64_t>> sec;
    while (std::cin >> i >> j >> val) {
        sec[j][i] = val;
    }

    std::map<uint32_t, std::map<uint32_t, uint64_t>> ans;
    for (auto &el: fir) {
        for (auto &se: sec) {
            uint64_t res = 0;
            for (auto &num: el.second) {
                res = (res + num.second * se.second[num.first] % mod) % mod;
            }
            if (res % mod) {
                ans[el.first][se.first] = res % mod;
            }
        }
    }
    for (auto &st: ans) {
        for (auto &num: st.second) {
            std::cout << st.first << " " << num.first << " " << num.second << std::endl;
        }
    }
}
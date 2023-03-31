#include <iostream>
#include <map>

constexpr uint64_t MOD = 4294967161;


int main() {
    std::map<uint32_t, std::map<uint32_t, uint64_t>> left, ans;
    uint32_t i, j;
    uint64_t value;
    while (std::cin >> i >> j >> value) {
        if (i == 0 && j == 0 && value == MOD) {
            break;
        }
        left[j][i] = value;
    }
    while (std::cin >> i >> j >> value) {
        for (auto& elem: left[i]) {
            ans[elem.first][j] += elem.second * value;
            ans[elem.first][j] %= MOD;
        }
    }
    for (auto& st: ans) {
        for (auto& num: st.second) {
            if (num.second != 0) {
                std::cout << st.first << " " << num.first << " " << num.second << std::endl;
            }
        }
    }
}
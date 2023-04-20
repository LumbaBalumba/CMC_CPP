#include <iostream>
#include <string>

std::string
str_mul(const std::string &str, size_t k)
{
    std::string res;
    for (size_t i = 0; i < k; ++i) {
        res += str;
    }
    return res;
}

int
main()
{
    std::string str;
    while (std::cin >> str) {
        std::string pattern;
        bool flag = false;
        bool works = true;
        size_t cnt0 = 0, cnt1 = 0;
        for (auto c: str) {
            if (c != '0' && c != '1') {
                //pattern = "1";
                works = false;
                break;
            }
            if (!flag) {
                if (c == '0') {
                    pattern += c;
                    cnt0++;
                } else {
                    flag = true;
                    pattern += c;
                    cnt1++;
                }
            } else {
                if (c == '1') {
                    pattern += c;
                    cnt1++;
                } else {
                    break;
                }
            }
        }
        if (!works || cnt1 == 0 || cnt0 == 0 || pattern.empty() || str.size() % pattern.size() ||
            str_mul(pattern, str.size() / pattern.size()) != str) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
}

#include <iostream>
#include <climits>

int
main()
{
    unsigned offset, value;
    bool flag = true;
    int cnt;
    while (flag && std::cin >> std::hex >> offset) {
        unsigned tmp;
        for (int i = 0; i < CHAR_BIT / 2; ++i) {
            cnt = 0;
            value = 0;
            for (; cnt < CHAR_BIT / 2 && std::cin >> std::hex >> tmp; ++cnt) {
                value <<= CHAR_BIT;
                value += tmp;
            }
            if (cnt != CHAR_BIT / 2) {
                flag = false;
                break;
            }
            std::cout << value << std::endl;
        }
    }
}
#include <iostream>

int
main()
{
    std::cin.tie(nullptr);
    bool flag = false, f1 = false;
    {
        char tmp;
        while (std::cin.get(tmp)) {
            if (tmp < '0' || tmp > '9') {
                if (flag) {
                    std::cout << '0';
                    flag = false;
                }
                f1 = false;
                std::cout << tmp;
            } else if (tmp != '0') {
                flag = false;
                std::cout << tmp;
                f1 = true;
            } else {
                if (f1) {
                    std::cout << tmp;
                } else {
                    flag = true;
                }
            }

        }
    }
    if (flag) {
        std::cout << '0';
    }
}
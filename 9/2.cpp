#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <string>

int
main()
{
    std::cin.tie(nullptr);
    int64_t pattern_cnt0, pattern_cnt1, cnt0, cnt1;
    char c;
    bool flag = false;
    while ((c = getchar()) != EOF) {
        if (c == '0') {
            pattern_cnt0 = 1;
            pattern_cnt1 = 0;
            flag = true;

            while ((c = getchar()) && c == '0') {
                pattern_cnt0++;
            }

            if (c == '1') {
                pattern_cnt1++;
            } else {
                flag = false;
            }
            if (flag) {
                while ((c = getchar()) && c == '1') {
                    pattern_cnt1++;
                }

                while (c == '0') {
                    cnt0 = pattern_cnt0 - 1;
                    cnt1 = pattern_cnt1;

                    while ((c = getchar()) && c == '0') {
                        cnt0--;
                    }

                    if (c != '1') {
                        flag = false;
                        break;
                    } else {
                        cnt1--;
                    }

                    while ((c = getchar()) && c == '1') {
                        cnt1--;
                    }

                    if (cnt0 || cnt1) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                if (c == ' ' || c == '\n' || c == EOF) {
                    std::cout << 1 << std::endl;
                } else {
                    std::cout << 0 << std::endl;
                    while (c != ' ' && c != '\n' && c != EOF) {
                        c = getchar();
                    }
                }
            } else {
                std::cout << 0 << std::endl;
                while (c != ' ' && c != '\n' && c != EOF) {
                    c = getchar();
                }
            }
        } else if (c != ' ' && c != '\n' && c != EOF) {
            std::cout << 0 << std::endl;
            while (c != ' ' && c != '\n' && c != EOF) {
                c = getchar();
            }
        }
    }
}

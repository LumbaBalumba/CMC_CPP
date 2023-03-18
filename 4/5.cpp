#include <list>
#include <iostream>

int
main()
{
    std::list<unsigned> l;
    unsigned a;
    std::cin >> a;
    while (a != 0) {
        l.push_back(a);
        std::cin >> a;
    }
    for (ssize_t cmd1, cmd2; std::cin >> cmd1;) {
        if (cmd1 < 0) {
            cmd1 *= -1;
            if ((size_t) cmd1 > l.size()) {
                continue;
            }
            auto it = l.begin();
            for (size_t i = 0; i < (size_t) cmd1 - 1; ++i, ++it) {}
            l.erase(it);
        } else {
            std::cin >> cmd2;
            if ((size_t) cmd1 <= l.size()) {
                auto it = l.begin();
                for (size_t i = 0; i < (size_t) cmd1 - 1; ++i, ++it) {}
                l.insert(it, cmd2);
            } else {
                l.push_back(cmd2);
            }
        }
    }
    for (auto elem: l) {
        std::cout << elem << std::endl;
    }
}

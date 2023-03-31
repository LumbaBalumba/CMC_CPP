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
    for (int cmd1; std::cin >> cmd1;) {
        if (cmd1 < 0) {
            cmd1 *= -1;
            if (cmd1 > (int) l.size()) {
                continue;
            }
            auto it = l.begin();
            for (int i = 0; i < cmd1 - 1; ++i, ++it);
            l.erase(it);
        } else {
            unsigned cmd2;
            std::cin >> cmd2;
            if (cmd1 <= (int) l.size()) {
                auto it = l.begin();
                for (int i = 0; i < cmd1 - 1; ++i, ++it);
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

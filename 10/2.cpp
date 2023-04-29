#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>

int
main()
{
    std::vector<std::pair<std::string, std::string>> vv;
    std::string left, right;
    while (std::cin >> left >> right) {
        vv.emplace_back(left, right);
    }
    std::set<char> v, new_v;
    v.insert('S');
    bool with_new = true;
    while (with_new) {
        new_v = v;
        with_new = false;
        for (auto x: vv) {
            if (v.find(x.first[0]) != v.end()) {
                for (const auto &c: x.second) {
                    if (isupper(c) && v.find(c) == v.end()) {
                        new_v.insert(c);
                        with_new = true;
                    }
                }
            }
        }
        v = new_v;
    }
    for (auto x: vv) {
        if (v.find(x.first[0]) != v.end()) {
            std::cout << x.first << " " << x.second << std::endl;
        }
    }
}
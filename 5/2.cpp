//
// Created by i3alumba on 20.03.23.
//

#include <iostream>
#include <map>
#include <string>

int
main()
{
    std::map<std::string, std::pair<double, unsigned>> m;
    std::string tmp_str;
    double mark;
    while (std::cin >> tmp_str) {
        std::cin >> mark;
        if (m.contains(tmp_str)) {
            m[tmp_str].first += mark;
            m[tmp_str].second++;
        } else {
            m[tmp_str] = { mark, 1 };
        }
    }
    for (auto &elem: m) {
        std::cout << elem.first << " " << elem.second.first / elem.second.second << std::endl;
    }
}
#include <iostream>
#include <chrono>


int
main()
{
    const char *fstr = "%Y-%m-%d";
    uint64_t res = 0;
    std::tm tm{};
    std::string date;
    std::cin >> date;
    strptime(date.c_str(), fstr, &tm);
    auto p1 = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    while (std::cin >> date) {
        strptime(date.c_str(), fstr, &tm);
        auto p2 = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        auto elapsed = std::chrono::duration_cast<std::chrono::hours>(p2 - p1);
        res += std::abs(elapsed.count()) / 24;
        p1 = p2;
    }
    std::cout << res << std::endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

//для for_each использован код https://en.cppreference.com/w/cpp/algorithm/for_each

struct Sum
{
    void
    operator()(double n)
    { sum += n; }

    double sum = 0;
};

void shrink(std::vector<double> &v){
    int count = v.size() / 10;
    v = std::vector<double>(v.begin() + count, v.end() - count);
}

int
main()
{
    std::vector<double> v;
    double tmp;
    while (std::cin >> tmp) {
        v.push_back(tmp);
    }
    shrink(v);
    std::sort(v.begin(), v.end());
    shrink(v);
    Sum s = std::for_each(v.cbegin(), v.cend(), Sum());
    std::cout << std::setprecision(10) << s.sum / v.size() << std::endl;
}

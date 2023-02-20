#include <iostream>

class A
{
    long long value;
    bool flag;

public:
    A()
    {
        std::cin >> value;
        flag = false;
    }

    A(const A &other)
    {
        std::cin >> value;
        value += other.value;
        flag = other.flag;
    }

    ~A()
    {
        if (flag) {
            std::cout << value << std::endl;
        }
    }
};
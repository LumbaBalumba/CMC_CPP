#include <iostream>
#include <string>

class Info
{
    std::string str;
public:
    explicit Info(const std::string &str) : str(str)
    {}

    ~Info()
    {
        std::cout << str << std::endl;
    }
};

void
f()
{
    std::string str;
    if (std::cin >> str) {
        Info info(str);
        f();
    } else {
        throw std::out_of_range("Bimbimbambam");
    }
}

int
main()
{
    try {
        f();
    } catch (const std::out_of_range &err) {

    }
}

#include <iostream>
#include <string>

bool
alpha(char c)
{
    return c == '3' || c == '4';
}

bool
beta(char c)
{
    return c == '1' || c == '2';
}

int
main()
{
    std::string str;
    while (std::cin >> str) {
        size_t index = 0;
        while (alpha(str[index])) {
            index++;
        }
        while (beta(str[index])) {
            index++;
        }
        if (index == str.size()) {
            std::cout << '1' << std::endl;
        } else {
            std::cout << '0' << std::endl;
        }
    }
}
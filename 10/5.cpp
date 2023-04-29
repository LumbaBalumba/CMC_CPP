#include <iostream>
#include <string>
#include <stack>

std::string
no_space(const std::string &str)
{
    std::string res;
    for (char elem: str) {
        if (elem != ' ') {
            res += elem;
        }
    }
    return res;
}

std::string
to_reg(const std::string &str)
{
    std::stack<std::string> stack;
    for (auto c: str) {
        if (c >= 'a' && c <= 'z') {
            stack.push({ c });
        } else {
            std::string op1 = stack.top();
            stack.pop();
            std::string op2 = stack.top();
            stack.pop();
            stack.push("(" + op2 + c + op1 + ")");
        }
    }
    return stack.top();
}

int
main()
{
    std::string str;
    std::getline(std::cin, str);
    str = no_space(str);
    std::cout << to_reg(str);
}

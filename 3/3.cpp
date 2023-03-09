#include <vector>
#include <iostream>

namespace numbers
{
    complex
    eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack stack;
        for (const auto &arg: args) {
            if (arg == "z") {
                stack = stack << z;
            } else if (arg == "+") {
                complex a = +stack;
                stack = ~stack;
                complex b = +stack;
                stack = ~stack;
                stack = stack << (a + b);
            } else if (arg == "-") {
                complex a = +stack;
                stack = ~stack;
                complex b = +stack;
                stack = ~stack;
                stack = stack << (b - a);
            } else if (arg == "*") {
                complex a = +stack;
                stack = ~stack;
                complex b = +stack;
                stack = ~stack;
                stack = stack << b * a;
            } else if (arg == "/") {
                complex a = +stack;
                stack = ~stack;
                complex b = +stack;
                stack = ~stack;
                stack = stack << (b / a);
            } else if (arg == "!") {
                stack = stack << +stack;
            } else if (arg == ";") {
                stack = ~stack;
            } else if (arg == "#") {
                complex a = - +stack;
                stack = ~stack;
                stack = stack << a;
            } else if (arg == "~") {
                complex a = ~+stack;
                stack = ~stack;
                stack = stack << a;
            } else {
                stack = stack << complex(arg);
            }
        }
        return +stack;
    }
}
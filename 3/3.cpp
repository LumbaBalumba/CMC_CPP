#include "1.cpp"
#include "2.cpp"
#include <vector>

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
                complex a = (~stack, +stack), b = (~stack, +stack);
                stack = stack << (a + b);
            } else if (arg == "-") {
                complex a = (~stack, +stack), b = (~stack, +stack);
                stack = stack << (b - a);
            } else if (arg == "*") {
                complex a = (~stack, +stack), b = (~stack, +stack);
                stack = stack << b * a;
            } else if (arg == "/") {
                complex a = (~stack, +stack), b = (~stack, +stack);
                stack = stack << (b / a);
            } else if (arg == "!") {
                stack = stack << +stack;
            } else if (arg == ";") {
                stack = ~stack;
            } else if (arg == "#") {
                stack = stack << (~stack, - +stack);
            } else if (arg == "~") {
                stack = stack << (~stack, ~+stack);
            } else {
                stack = stack << complex(arg);
            }
        }
        return +stack;
    }
}
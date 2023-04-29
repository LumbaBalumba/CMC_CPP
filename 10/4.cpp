#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Функция, которая проверяет, является ли символ оператором
bool
isOperator(char c)
{
    return c == '*' || c == '/' || c == '+' || c == '-' || c == '&' || c == '^' || c == '|';
}

// Функция, которая проверяет, является ли символ открывающей скобкой
bool
isOpeningBracket(char c)
{
    return c == '(';
}

// Функция, которая проверяет, является ли символ закрывающей скобкой
bool
isClosingBracket(char c)
{
    return c == ')';
}

// Функция, которая возвращает приоритет оператора
int
getPriority(char c)
{
    switch (c) {
        case '*':
        case '/':
            return 1;
        case '+':
        case '-':
            return 2;
        case '&':
            return 3;
        case '^':
            return 4;
        case '|':
            return 5;
        default:
            return -1;
    }
}

string
removeRedundantBrackets(const string &expr)
{
    stack<size_t> st;
    string result;

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (isOpeningBracket(c)) {
            st.push(i);
        } else if (isClosingBracket(c)) {
            if (!st.empty()) {
                size_t j = st.top();
                st.pop();

                if (j == 0 || i == expr.length() - 1) {
                    result += expr.substr(j, i - j + 1);
                } else {
                    char prev = expr[j - 1];
                    char next = expr[i + 1];

                    if (isOperator(prev) && isOperator(next)) {
                        if (getPriority(prev) >= getPriority(expr[j]) && getPriority(prev) >= getPriority(expr[i])) {
                            result += expr.substr(j + 1, i - j - 1);
                        } else {
                            result += expr.substr(j, i - j + 1);
                        }
                    } else {
                        result += expr.substr(j, i - j + 1);
                    }
                }
            } else {
                result += c;
            }
        } else {
            result += c;
        }
    }

    return result;
}

int
main()
{
    string expr = "((a+b)+(c+d))";
    string result = removeRedundantBrackets(expr);
    cout << result << endl;
    return 0;
}
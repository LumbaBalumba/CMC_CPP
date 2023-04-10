#include <string>
#include <algorithm>

using std::string;

class BinaryNumber
{
    string value;
public:
    BinaryNumber(const string &s);

    explicit operator string() const;

    const BinaryNumber &
    operator++();
};

BinaryNumber::BinaryNumber(const string &s)
{
    value = s;
    std::reverse(value.begin(), value.end());
}

BinaryNumber::operator string() const
{
    string res = value;
    std::reverse(res.begin(), res.end());
    return res;
}

const BinaryNumber &
BinaryNumber::operator++()
{
    bool flag = true;
    for (char &i: value) {
        int tmp = i - '0' + flag;
        flag = tmp > 1;
        i = (char) (tmp % 2 + '0');
    }
    if (flag) {
        value += '1';
    }
    return *this;
}

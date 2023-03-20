#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>

class Date
{
private:
    int day, month, year;
public:
    explicit Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y)
    {}

    auto
    operator<=>(const Date &other) const
    {
        if (year != other.year) {
            return year <=> other.year;
        } else if (month != other.month) {
            return month <=> other.month;
        }
        return day <=> other.day;
    }

    bool
    operator==(const Date &other) const
    {
        return day == other.day && month == other.month && year == other.year;
    }

    friend std::istream &
    operator>>(std::istream &is, Date &date)
    {
        char _c;
        is >> date.year >> _c >> date.month >> _c >> date.day;
        return is;
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Date &date)
    {
        char _c = '/';
        os << std::setfill('0') << std::setw(4) << date.year << _c << std::setw(2) << date.month << _c << std::setw(2)
           << date.day;
        return os;
    }
};

int
main()
{
    std::map<std::string, std::map<Date, unsigned>> m;
    std::string name;
    unsigned mark;
    Date date;
    std::set<Date> st;
    while (std::cin >> name >> date >> mark) {
        m[name][date] = mark;
        st.emplace(date);
    }
    std::cout << ". ";
    for (auto &i: st) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for (auto &i: m) {
        std::cout << i.first << " ";
        for (auto &j: st) {
            if (i.second.count(j)) {
                std::cout << i.second[j] << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}
#include <iostream>
#include <iomanip>

const double eps = 0.0001;

class Point
{
public:
    double x, y;

    Point() = default;

    Point(double x, double y) : x(x), y(y)
    {}

    friend std::istream &
    operator>>(std::istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const Point &p)
    {
        out << p.x << " " << p.y;
        return out;
    }
};

class Line
{
    double a, b, c;

public:
    bool
    operator==(const Line &other) const
    {
        return std::abs(a * other.b - b * other.a) < eps && std::abs(a * other.c - c * other.a) < eps &&
               std::abs(b * other.c - c * other.b) < eps;
    }

    [[nodiscard]] bool
    intersect(const Line &other) const
    {
        return std::abs(a * other.b - b * other.a) > eps;
    }

    [[nodiscard]] Point
    intersection(const Line &other) const
    {
        double zn = a * other.b - b * other.a;
        return { -(c * other.b - b * other.c) / zn, -(a * other.c - c * other.a) / zn };
    }

    friend std::istream &
    operator>>(std::istream &in, Line &l)
    {
        Point p1 = {}, p2 = {};
        in >> p1 >> p2;
        l.a = p1.y - p2.y;
        l.b = p2.x - p1.x;
        l.c = p1.x * p2.y - p1.y * p2.x;
        return in;
    }
};

int
main()
{
    Line l1 = {}, l2 = {};
    std::cin >> l1 >> l2;
    if (l1 == l2) {
        std::cout << 2 << std::endl;
    } else if (!l1.intersect(l2)) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << " " << std::fixed << std::setprecision(5) << l1.intersection(l2) << std::endl;
    }
}
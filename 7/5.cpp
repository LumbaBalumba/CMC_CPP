#include <cassert>

class Figure
{
public:
    [[nodiscard]] virtual bool
    equals(const Figure *other) const
    { return false; }

    virtual ~Figure() = default;
};

class Rectangle : public Figure
{
    int a, b;
public:
    Rectangle(int a = 0, int b = 0) : a(a), b(b)
    {}

    bool
    operator==(const Rectangle &other) const
    {
        return a == other.a && b == other.b;
    }

    [[nodiscard]] bool
    equals(const Figure *other) const override
    {
        auto *r = dynamic_cast<const Rectangle *>(other);
        if (!r) {
            return false;
        }
        return *r == *this;
    }
};

class Triangle : public Figure
{
    int a, b, c;
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c)
    {}

    bool
    operator==(const Triangle &other) const
    {
        return a == other.a && b == other.b && c == other.c;
    }

    [[nodiscard]] bool
    equals(const Figure *other) const override
    {
        auto *r = dynamic_cast<const Triangle *>(other);
        if (!r) {
            return false;
        }
        return *r == *this;
    }
};
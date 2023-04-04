#include <string>
#include <sstream>

class Rectangle : public Figure
{
    double a, b;
public:
    explicit Rectangle(double a = 0, double b = 0) : a(a), b(b)
    {}

    static Rectangle *
    make(const std::string &str)
    {
        std::stringstream ss(str);
        double a1, b1;
        ss >> a1 >> b1;
        return new Rectangle(a1, b1);
    }

    [[nodiscard]] double
    get_square() const override
    {
        return a * b;
    }
};

class Square : public Figure
{
    double a;
public:
    explicit Square(double a = 0) : a(a)
    {}

    static Square *
    make(const std::string &str)
    {
        std::stringstream ss(str);
        double a1;
        ss >> a1;
        return new Square(a1);
    }

    [[nodiscard]] double
    get_square() const override
    {
        return a * a;
    }
};

class Circle : public Figure
{
    double r;
public:
    explicit Circle(double a = 0) : r(a)
    {}

    static Circle *
    make(const std::string &str)
    {
        std::stringstream ss(str);
        double a1;
        ss >> a1;
        return new Circle(a1);
    }

    [[nodiscard]] double
    get_square() const override
    {
        return r * r * std::numbers::pi;
    }
};
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

namespace numbers
{
    class complex
    {
        double _re, _im;
    public:
        complex(double re = 0, double im = 0) : _re(re), _im(im)
        {}

        explicit complex(const std::string &other)
        {
            _re = _im = 0;
            const char *str = other.c_str();
            sscanf(str, "(%lf,%lf)", &_re, &_im);
        }

        [[nodiscard]] double
        re() const
        {
            return _re;
        }

        [[nodiscard]] double
        im() const
        {
            return _im;
        }

        [[nodiscard]] double
        abs2() const
        {
            return _im * _im + _re * _re;
        }

        [[nodiscard]] double
        abs() const
        {
            return sqrt(_im * _im + _re * _re);
        }

        [[nodiscard]] std::string
        to_string() const
        {
            std::stringstream tmp;
            tmp << std::setprecision(10) << "(" << _re << "," << _im << ")";
            return tmp.str();
        }

        complex &
        operator+=(const complex &other)
        {
            return *this = *this + other;
        }

        complex &
        operator-=(const complex &other)
        {
            return *this = *this - other;
        }

        complex &
        operator*=(const complex &other)
        {
            return *this = *this * other;
        }

        complex &
        operator/=(const complex &other)
        {
            return *this = *this / other;
        }

        friend complex
        operator+(const complex &left, const complex &right)
        {
            return { left._re + right._re, left._im + right._im };
        }

        friend complex
        operator-(const complex &left, const complex &right)
        {
            return { left._re - right._re, left._im - right._im };
        }

        friend complex
        operator*(const complex &left, const complex &right)
        {
            return { left._re * right._re - left._im * right._im, left._im * right._re + left._re * right._im };
        }

        complex
        operator~() const
        {
            return { _re, -_im };
        }

        friend complex
        operator/(const complex &left, double right)
        {
            return { left._re / right, left._im / right };
        }

        friend complex
        operator/(const complex &left, const complex &right)
        {
            return left * ~right / right.abs2();
        }

        complex
        operator-() const
        {
            return { -_re, -_im };
        }
    };
}
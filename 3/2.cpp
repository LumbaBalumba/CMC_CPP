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

    class complex_stack
    {
        complex *_arr;
        size_t _cap, _size;

    public:
        complex_stack() : _arr((complex *) calloc(1, sizeof(complex))), _cap(0), _size(1)
        {}

        complex_stack(size_t size) : _arr((complex *) calloc(size, sizeof(complex))), _cap(size), _size(size)
        {}

        complex_stack(const complex_stack &other) : _arr((complex *) calloc(other._size, sizeof(complex))),
                                                    _cap(other._cap), _size(other._size)
        {}

        complex_stack(complex_stack &&other) : _arr(other._arr), _cap(other._cap), _size(other._size)
        {
            other._arr = nullptr;
        }

        [[nodiscard]] size_t
        size() const
        {
            return _size;
        }

        [[nodiscard]] size_t
        cap() const
        {
            return _cap;
        }

        ~complex_stack()
        {
            free(_arr);
        }

        complex
        operator[](ssize_t index) const
        {
            return _arr[index];
        }

        friend complex_stack
        operator<<(const complex_stack &left, const complex &value)
        {
            complex_stack stack = left;
            if (stack._size == stack._cap) {
                stack._arr = (complex *) realloc(stack._arr, sizeof(complex) * (stack._cap *= 2));
            }
            stack._arr[stack._size++] = value;
            return stack;
        }

        complex
        operator+() const
        {
            return _arr[_size - 1];
        }

        complex_stack
        operator~() const
        {
            complex_stack res = *this;
            res._size--;
            res._cap = res._size;
            res._arr = (complex *) realloc(res._arr, res._cap);
            return res;
        }
    };
}
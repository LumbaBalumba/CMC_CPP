#include <cmath>

namespace numbers
{
    class complex_stack
    {
        complex *_arr;
        size_t _cap, _size;

    public:
        complex_stack() : _arr((complex *) calloc(1, sizeof(complex))), _cap(1), _size(0)
        {}

        explicit complex_stack(size_t size) : _arr((complex *) calloc(size, sizeof(complex))), _cap(size), _size(size)
        {}

        complex_stack(const complex_stack &other) : _arr((complex *) calloc(other._cap, sizeof(complex))),
                                                    _cap(other._cap), _size(other._size)
        {
            for (size_t i = 0; i < _size; ++i) {
                _arr[i] = other._arr[i];
            }
        }

        complex_stack(complex_stack &&other) noexcept: _cap(other._cap), _size(other._size)
        {
            free(_arr);
            _arr = other._arr;
            other._arr = nullptr;
        }

        complex_stack &
        operator=(const complex_stack &other)
        {
            if (this == &other) {
                return *this;
            }
            free(_arr);
            _arr = (complex *) calloc(other._cap, sizeof(complex));
            _cap = other._cap;
            _size = other._size;
            for (size_t i = 0; i < _size; ++i) {
                _arr[i] = other._arr[i];
            }
            return *this;
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
        operator<<(complex_stack stack, const complex &value)
        {
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
            return res;
        }
    };
}
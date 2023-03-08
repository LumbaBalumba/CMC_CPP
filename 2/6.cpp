#include <iostream>
#include <string>

class StringView
{
    char *value;
    size_t _size;

public:
    StringView() = default;

    StringView(const std::string &s, size_t begin = 0, size_t count = std::string::npos)
    {
        value = (char *) s.c_str() + begin;
        _size = count;
    }

    char &
    operator[](size_t index) const
    {
        return value[index];
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
    {
        value = sv.value + begin;
        _size = count;
    }

    [[nodiscard]] size_t
    size() const
    {
        return _size;
    }

    [[nodiscard]] size_t
    length() const
    {
        return _size;
    }

    [[nodiscard]] std::string
    str(size_t begin = 0, size_t count = std::string::npos) const
    {
        std::string res{};
        for (size_t i = 0; i < count; ++i) {
            res += value[begin + i];
        }
        return res;
    }

    friend auto
    operator<=>(const StringView &left, const StringView &right)
    {
        return std::string(left.value) <=> std::string(right.value);
    }

    friend auto
    operator==(const StringView &left, const StringView &right)
    {
        return std::string(left.value) == std::string(right.value);
    }

    class const_iterator;

    class reverse_iterator;

    class const_reverse_iterator;

    class iterator
    {
        char *iter;
    public:
        iterator(char *ptr)
        {
            iter = ptr;
        }

        iterator(const iterator &other)
        {
            iter = other.iter;
        }

        char &
        operator*()
        {
            return *iter;
        }

        iterator &
        operator++()
        {
            ++iter;
            return *this;
        }

        iterator
        operator++(int)
        {
            return { iter++ };
        }

        iterator &
        operator--()
        {
            --iter;
            return *this;
        }

        iterator
        operator--(int)
        {
            return { iter-- };
        }

        iterator
        operator+(ssize_t index) const
        {
            return { iter + index };
        }

        iterator
        operator-(ssize_t index) const
        {
            return { iter - index };
        }

        friend const_reverse_iterator
        operator+(ssize_t index, const iterator &i)
        {
            return i + index;
        }

        iterator &
        operator+=(ssize_t index)
        {
            return *this = *this + index;
        }

        iterator &
        operator-=(ssize_t index)
        {
            return *this = *this - index;
        }

        auto
        operator<=>(const iterator &other) const = default;

        bool
        operator==(const iterator &other) const
        {
            return iter == other.iter;
        }

        friend std::ostream &
        operator<<(std::ostream &out, const iterator &i)
        {
            return out << *i.iter;
        }

        friend class const_iterator;

        friend class reverse_iterator;

        friend class const_reverse_iterator;
    };

    class const_iterator
    {
        char *iter;
    public:
        const_iterator(char *ptr)
        {
            iter = ptr;
        }

        const_iterator(const const_iterator &other)
        {
            iter = other.iter;
        }

        const_iterator(const iterator &other)
        {
            iter = other.iter;
        }

        char &
        operator*()
        {
            return *iter;
        }

        const_iterator &
        operator++()
        {
            ++iter;
            return *this;
        }

        const_iterator
        operator++(int)
        {
            return { iter++ };
        }

        const_iterator &
        operator--()
        {
            --iter;
            return *this;
        }

        const_iterator
        operator--(int)
        {
            return { iter-- };
        }


        const_iterator
        operator+(ssize_t index) const
        {
            return { iter + index };
        }

        const_iterator
        operator-(ssize_t index) const
        {
            return { iter - index };
        }

        friend const_iterator
        operator+(ssize_t index, const const_iterator &i)
        {
            return i + index;
        }

        const_iterator &
        operator+=(ssize_t index)
        {
            return *this = *this + index;
        }

        const_iterator &
        operator-=(ssize_t index)
        {
            return *this = *this - index;
        }

        auto
        operator<=>(const const_iterator &other) const = default;

        bool
        operator==(const const_iterator &other) const
        {
            return iter == other.iter;
        }

        friend std::ostream &
        operator<<(std::ostream &out, const const_iterator &i)
        {
            return out << *i.iter;
        }

        friend class const_reverse_iterator;
    };

    class reverse_iterator
    {
        char *iter;
    public:
        reverse_iterator(char *ptr)
        {
            iter = ptr;
        }

        reverse_iterator(const reverse_iterator &other)
        {
            iter = other.iter;
        }

        reverse_iterator(const iterator &other)
        {
            iter = other.iter;
        }

        char &
        operator*()
        {
            return *iter;
        }

        reverse_iterator &
        operator++()
        {
            --iter;
            return *this;
        }

        reverse_iterator
        operator++(int)
        {
            return { iter-- };
        }

        reverse_iterator &
        operator--()
        {
            ++iter;
            return *this;
        }

        reverse_iterator
        operator--(int)
        {
            return { iter++ };
        }

        reverse_iterator
        operator+(ssize_t index) const
        {
            return { iter + index };
        }

        reverse_iterator
        operator-(ssize_t index) const
        {
            return { iter - index };
        }

        friend reverse_iterator
        operator+(ssize_t index, const reverse_iterator &i)
        {
            return i + index;
        }

        reverse_iterator &
        operator+=(ssize_t index)
        {
            return *this = *this + index;
        }

        reverse_iterator &
        operator-=(ssize_t index)
        {
            return *this = *this - index;
        }

        auto
        operator<=>(const reverse_iterator &other) const = default;

        bool
        operator==(const reverse_iterator &other) const
        {
            return iter == other.iter;
        }

        friend std::ostream &
        operator<<(std::ostream &out, const reverse_iterator &i)
        {
            return out << *i.iter;
        }

        friend class const_reverse_iterator;
    };

    class const_reverse_iterator
    {

        char *iter;
    public:
        const_reverse_iterator(char *ptr)
        {
            iter = ptr;
        }

        const_reverse_iterator(const const_reverse_iterator &other)
        {
            iter = other.iter;
        }

        const_reverse_iterator(const reverse_iterator &other)
        {
            iter = other.iter;
        }

        const_reverse_iterator(const iterator &other)
        {
            iter = other.iter;
        }

        const_reverse_iterator(const const_iterator &other)
        {
            iter = other.iter;
        }

        char &
        operator*()
        {
            return *iter;
        }

        const_reverse_iterator &
        operator++()
        {
            --iter;
            return *this;
        }

        const_reverse_iterator
        operator++(int)
        {
            return { iter-- };
        }

        const_reverse_iterator &
        operator--()
        {
            ++iter;
            return *this;
        }

        const_reverse_iterator
        operator--(int)
        {
            return { iter++ };
        }

        const_reverse_iterator
        operator+(ssize_t index) const
        {
            return { iter + index };
        }

        friend const_reverse_iterator
        operator+(ssize_t index, const const_reverse_iterator &i)
        {
            return i + index;
        }

        const_reverse_iterator
        operator-(ssize_t index) const
        {
            return { iter - index };
        }

        const_reverse_iterator &
        operator+=(ssize_t index)
        {
            return *this = *this + index;
        }

        const_reverse_iterator &
        operator-=(ssize_t index)
        {
            return *this = *this - index;
        }

        auto
        operator<=>(const const_reverse_iterator &other) const = default;

        bool
        operator==(const const_reverse_iterator &other) const
        {
            return iter == other.iter;
        }

        friend std::ostream &
        operator<<(std::ostream &out, const const_reverse_iterator &i)
        {
            return out << *i.iter;
        }
    };

    [[nodiscard]] iterator
    begin() const
    {
        return { value };
    }

    [[nodiscard]] iterator
    end() const
    {
        return { value + _size };
    }

    [[nodiscard]] char &
    at(size_t index) const
    {
        if (index <= _size) {
            return *(value + index);
        } else {
            return *value;
        }
    }

    [[nodiscard]] const_iterator
    cbegin() const
    {
        return { value };
    }

    [[nodiscard]] iterator
    cend() const
    {
        return { value + _size };
    }

    [[nodiscard]] reverse_iterator
    rbegin() const
    {
        return { value + _size - 1 };
    }

    [[nodiscard]] reverse_iterator
    rend() const
    {
        return { value };
    }

    [[nodiscard]] reverse_iterator
    crbegin() const
    {
        return { value + _size - 1 };
    }

    [[nodiscard]] reverse_iterator
    crend() const
    {
        return { value };
    }
};

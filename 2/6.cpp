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
        _size = s.size();
    }

    StringView &
    operator=(const StringView &other) = delete;

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

    class iterator
    {
    protected:
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

        virtual iterator &
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

        virtual iterator &
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

        virtual iterator &
        operator+=(ssize_t index)
        {
            return *this = *this + index;
        }

        virtual iterator &
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
    };

    class const_iterator : protected iterator
    {
    public:
        const_iterator(char *ptr) : iterator(ptr)
        {}

        const_iterator(const const_iterator &other) = default;

        char
        operator*()
        {
            return *iterator::iter;
        }

        using iterator::operator++;
        using iterator::operator--;
        using iterator::operator+;
        using iterator::operator-;
        using iterator::operator+=;
        using iterator::operator-=;
        using iterator::operator<=>;
        using iterator::operator==;
    };

    class reverse_iterator : protected iterator
    {
    public:
        reverse_iterator(char *ptr) : iterator(ptr)
        {}

        reverse_iterator(const reverse_iterator &other) = default;

        using iterator::operator*;
        using iterator::operator==;
        using iterator::operator<=>;

        reverse_iterator &
        operator++() override
        {
            --iterator::iter;
            return *this;
        }

        reverse_iterator &
        operator--() override
        {
            ++iterator::iter;
            return *this;
        }

        reverse_iterator
        operator++(int)
        {
            return { iterator::iter-- };
        }

        reverse_iterator
        operator--(int)
        {
            return { iterator::iter++ };
        }

        reverse_iterator
        operator+(ssize_t other) const
        {
            return { iterator::iter - other };
        }

        reverse_iterator
        operator-(ssize_t other) const
        {
            return { iterator::iter + other };
        }

        reverse_iterator &
        operator+=(ssize_t other) override
        {
            return *this = *this - other;
        }

        reverse_iterator &
        operator-=(ssize_t other) override
        {
            return *this = *this + other;
        }
    };

    class const_reverse_iterator : protected reverse_iterator, protected const_iterator
    {
    public:
        const_reverse_iterator(char *iter) : reverse_iterator(iter), const_iterator(iter)
        {}

        const_reverse_iterator(const const_reverse_iterator &other) = default;

        using const_iterator::operator*;
        using reverse_iterator::operator+;
        using reverse_iterator::operator-;
        using reverse_iterator::operator++;
        using reverse_iterator::operator--;
        using reverse_iterator::operator+=;
        using reverse_iterator::operator-=;
        using const_iterator::operator<=>;
        using const_iterator::operator==;
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

    [[nodiscard]] const_iterator
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

    [[nodiscard]] const_reverse_iterator
    crbegin() const
    {
        return { value + _size - 1 };
    }

    [[nodiscard]] const_reverse_iterator
    crend() const
    {
        return { value };
    }
};
#include <string>
#include <iterator>

class StringView
{
    std::string *value;
    size_t _begin, _size;

public:
    StringView(std::string &str, size_t begin = 0, size_t count = std::string::npos)
    {
        value = &str;
        _begin = (begin < str.size()) ? begin : str.length();
        _size = (count != std::string::npos) ? ((_begin + count < str.length()) ? count : str.length() - _begin) :
                str.length() - _begin;
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
    {
        value = sv.value;
        if (begin < sv._size) {
            _begin = sv._begin + begin;
            _size = sv._size - begin;
        } else {
            _size = 0;
            _begin = sv._begin + sv._size;
        }

        if (count != std::string::npos) {
            _size = (_size > count) ? count : _size;
        }
    }

    StringView &
    operator=(const StringView &) = delete;

    [[nodiscard]] std::string
    str(size_t begin = 0, size_t count = std::string::npos) const
    {
        size_t new_begin = _begin;
        size_t new_size = _size;
        if (begin <= _size) {
            new_begin = _begin + begin;
            new_size = _size - begin;
        } else {
            new_size = 0;
        }
        if (count != std::string::npos) {
            new_size = (new_size > count) ? count : new_size;
        }
        return value->substr(new_begin, new_size);
    }

    [[nodiscard]] size_t
    length() const
    {
        return _size;
    }

    [[nodiscard]] size_t
    size() const
    {
        return _size;
    }

    char &
    operator[](size_t index)
    {
        if (index < _size) {
            return value->at(_begin + index);
        } else {
            throw std::out_of_range("Index error");
        }
    }

    [[nodiscard]] char
    operator[](size_t index) const
    {
        if (index < _size) {
            return value->at(_begin + index);
        } else {
            throw std::out_of_range("Index error");
        }
    }

    char &
    at(size_t index)
    {
        if (index < _size) {
            return value->at(_begin + index);
        } else {
            throw std::out_of_range("Index error");
        }
    }

    [[nodiscard]] const char &
    at(size_t index) const
    {
        if (index < _size) {
            return value->at(_begin + index);
        } else {
            throw std::out_of_range("Index error");
        }
    }

    bool
    operator==(const StringView &other) const
    {
        return this->str() == other.str();
    }

    auto
    operator<=>(const StringView &other) const
    {
        return this->str() <=> other.str();
    }

    using iterator = std::string::iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_iterator = std::string::const_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;

    iterator
    begin()
    {
        return value->begin() + (long) _begin;
    }

    iterator
    end()
    {
        return begin() + (long) _size;
    }

    const_iterator
    cbegin()
    {
        return value->cbegin() + (long) _begin;
    }

    const_iterator
    cend()
    {
        return cbegin() + (long) _size;
    }

    reverse_iterator
    rbegin()
    {
        return rend() - (long) _size;
    }

    reverse_iterator
    rend()
    {
        return value->rend() - (long) _begin;
    }


    const_reverse_iterator
    crbegin()
    {
        return crend() - (long) _size;
    }

    const_reverse_iterator
    crend()
    {
        return value->crend() - (long) _begin;
    }
};


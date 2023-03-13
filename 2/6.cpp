#include <string>
#include <algorithm>

class StringView
{
    char *value;
    size_t _size;

public:
    StringView() = default;

    StringView(const std::string &s, size_t begin = 0, size_t count = std::string::npos)
    {
        if (begin >= s.size()) {
            _size = 0;
            value = nullptr;
        } else {
            value = (char *) s.c_str() + begin;
            _size = std::min(s.size() - begin, count);
        }
    }

    StringView &
    operator=(const StringView &other) = delete;

    char &
    operator[](size_t index)
    {
        return value[index];
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
    {
        if (begin >= sv.size()) {
            _size = 0;
            value = nullptr;
        } else {
            value = sv.value + begin;
            _size = std::min(count, sv._size - begin);
        }
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
        if (begin >= size()) {
            return "";
        } else {
            std::string res{ value + begin, std::min(count, _size) };
            /*for (size_t i = 0; i < std::min(count, _size); ++i) {
                res += value[begin + i];
            }*/
            return res;
        }
    }

    friend auto
    operator<=>(const StringView &left, const StringView &right)
    {
        return left.str() <=> right.str();
    }

    friend auto
    operator==(const StringView &left, const StringView &right)
    {
        return left.str() == right.str();
    }
};


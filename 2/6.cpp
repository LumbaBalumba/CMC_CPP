#include <iostream>
#include <string>

class StringView
{
    std::string *value;

public:
    StringView() = default;

    explicit StringView(std::string &other)
    {
        value = &other;
    }

    StringView(const StringView &other)
    {
        value = other.value;
    }

    StringView(std::string &s, size_t begin = 0, size_t count = std::string::npos)
    {
        *value = {};
        for (size_t i = 0; i < count; ++i) {
            *value += s[i + begin];
        }
    }

    char &
    operator[](size_t index) const
    {
        return (*value)[index];
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
    {
        *value = {};
        for (size_t i = 0; i < count; ++i) {
            *value += sv[i + begin];
        }
    }

    size_t
    size()
    {
        return value->size();
    }

    size_t
    length()
    {
        return value->size();
    }

    [[nodiscard]] std::string
    str(size_t begin = 0, size_t count = std::string::npos) const
    {
        std::string res{};
        for (size_t i = 0; i < count; ++i) {
            res += (*value)[begin + i];
        }
        return res;
    }

    auto
    operator<=>(const StringView &other)
    {
        return *value <=> *(other.value);
    }

    auto
    begin()
    {
        return value->begin();
    }

    auto
    end()
    {
        return value->end();
    }
};
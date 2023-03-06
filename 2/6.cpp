#include <iostream>
#include <string>

class StringView {
    std::string *value;
    size_t start, _size;

public:
    StringView() = default;

    StringView(std::string &s, size_t begin = 0, size_t count = std::string::npos) {
        value = &s;
        start = begin;
        this->_size = count;
    }

    char &
    operator[](size_t index) const {
        return (*value)[start + index];
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos) {
        value = sv.value;
        start = begin + sv.start;
        this->_size = count;
    }

    [[nodiscard]] size_t
    size() const {
        return _size;
    }

    [[nodiscard]] size_t
    length() const {
        return _size;
    }

    [[nodiscard]] std::string
    str(size_t begin = 0, size_t count = std::string::npos) const {
        std::string res{};
        for (size_t i = 0; i < count; ++i) {
            res += (*value)[begin + i];
        }
        return res;
    }

    friend auto
    operator<=>(const StringView &left, const StringView &right) {
        return std::string(left.value->c_str() + left.start) <=> std::string(right.value->c_str() + right.start);
    }

    friend auto
    operator==(const StringView &left, const StringView &right) {
        return std::string(left.value->c_str() + left.start) == std::string(right.value->c_str() + right.start);
    }

    [[nodiscard]] auto
    begin() const {
        return value->begin();
    }

    [[nodiscard]] auto
    end() const {
        return value->end();
    }

    [[nodiscard]] char &
    at(size_t index) const {
        return value->at(index);
    }
};

#include <iostream>
#include <map>
#include <cinttypes>

constexpr uint64_t MOD = 4294967161;

template<uint64_t Mod>
class Congruence
{
    uint64_t value;
public:
    Congruence() = default;

    Congruence(uint64_t value) : value(value % Mod)
    {}

    Congruence(const Congruence &other) = default;

    Congruence(Congruence &&other) = default;

    Congruence &
    operator=(const Congruence &other) = default;

    friend Congruence
    operator+(const Congruence &left, const Congruence &right)
    {
        return { left.value + right.value };
    }

    Congruence &
    operator+=(const Congruence &other)
    {
        return *this = *this + other;
    }

    friend Congruence
    operator*(const Congruence &left, const Congruence &right)
    {
        return { left.value * right.value };
    }

    Congruence &
    operator*=(const Congruence &other)
    {
        return *this = *this * other;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const Congruence &c)
    {
        return out << c.value;
    }

    bool
    operator==(const Congruence &other) const = default;

    auto
    operator<=>(const Congruence &other) const = default;
};

std::map<std::pair<uint32_t, uint32_t>, Congruence<MOD>>
matrix_mul(
        const std::map<std::pair<uint32_t, uint32_t>, Congruence<MOD>> &left,
        const std::map<std::pair<uint32_t, uint32_t>, Congruence<MOD>> &right)
{
    std::map<std::pair<uint32_t, uint32_t>, Congruence<MOD>> res;
    //  Magic matrices operations
    return res;
}

int
main()
{
    std::map<std::pair<uint32_t, uint32_t>, Congruence<MOD>> matrix1, matrix2, res;
    uint32_t row, col, value;
    while (std::cin >> row >> col >> value) {
        if (row == 0 && col == 0 && value == MOD) {
            break;
        }
        matrix1[{ row, col }] = { value };
    }
    res = matrix_mul(matrix1, matrix2);
    while (std::cin >> row >> col >> value) {
        matrix2[{ row, col }] = { value };
    }

    for (auto &elem: res) {
        if (elem.second != 0) {
            std::cout << elem.first.first << " " << elem.first.second << " " << elem.second << std::endl;
        }
    }
}
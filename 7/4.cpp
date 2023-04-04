#include <cmath>
#include <iostream>

namespace Game
{
    template<typename T>
    struct Coord
    {
        using value_type = T;
        T row, col;

        Coord() = default;

        explicit Coord(const T &value) : row(value), col(value)
        {}

        Coord(const T &row, const T &col) : row(row), col(col)
        {};
    };

    template<typename T>
    struct AxialCoord
    {
        using value_type = T;
        T q, r;

        explicit AxialCoord(const T &q = 0, const T &r = 0) : q(q), r(r)
        {};

        explicit AxialCoord(const Coord<T> &other) : q(other.col), r(other.row - (other.col + other.col % 2) / 2)
        {}

        AxialCoord(const AxialCoord &other) = default;
    };

    template<typename T>
    T
    axial_distance(const AxialCoord<T> &point1, const AxialCoord<T> &point2)
    {
        AxialCoord vec(point2.q - point1.q, point2.r - point1.r);
        return (std::abs(vec.q) + std::abs(vec.q + vec.r) + std::abs(vec.r)) / 2;
    }

    template<typename T>
    T
    dist(const Coord<T> &size, const Coord<T> &point1, const Coord<T> &point2)
    {
        return axial_distance(AxialCoord<T>(point1), AxialCoord<T>(point2));
    }
}
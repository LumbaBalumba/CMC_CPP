#include <iostream>
#include <iterator>
#include <vector>

using std::cout;

class Matrix
{
    std::vector<double[3]> arr;

public:
    Matrix()
    {
        arr = std::vector<double[3]>(3);
    }

    double &
    operator[](ssize_t i, ssize_t j)
    {
        return arr[i][j];
    }

    auto
    begin()
    {
        return arr.begin();
    }

    auto
    end()
    {
        return arr.end();
    }
};

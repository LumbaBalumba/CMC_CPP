#include <iostream>

namespace N
{
    std::ostream &
    func1(int a, int b)
    {
        std::cout << (a + b);
        return std::cout;
    }
}

class A
{
public:
    A(
            int a,
            int b = 10,
            int c = 20
    )
    {
        N::func1(a, b) << c << std::endl;
    }
};

int
main()
{
    A(30, 40);
}
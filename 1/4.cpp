#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    double E = 0, D = 0;
    unsigned k = 0;
    for (double tmp; std::cin >> tmp; ++k) {
        E += tmp;
        D += tmp * tmp;
    }
    E /= k;
    D /= k;
    D -= E * E;
    std::cout << std::setprecision(10) << E << " " << sqrt(D) << std::endl;
}
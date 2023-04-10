#include <complex>
#include <array>
#include <vector>
#include <cmath>


namespace Equations
{

    template<class T>
    std::pair<bool, std::vector<std::complex<T>>>
    quadratic(std::array<std::complex<T>, 3> coefs)
    {
        const double EPS = 32 * std::numeric_limits<T>::epsilon();
        std::complex<T> c = coefs[0], b = coefs[1], a = coefs[2];
        if (std::norm(a) >= EPS) {
            std::complex<T> D = std::sqrt(b * b - T(4) * c * a);
            return { true, { (-b + D) / (a * T(2)), (-b - D) / (a * T(2)) }};
        } else if (std::norm(b) >= EPS) {
            return { true, { -c / b }};
        } else if (std::norm(c) >= EPS) {
            return { true, {}};
        } else {
            return { false, {}};
        }
    }
}

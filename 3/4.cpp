#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

int
main(int argc, char **argv)
{
    const numbers::complex C(argv[1]);
    const double R = fabs(strtod(argv[2], nullptr));
    const int N = (int) strtol(argv[3], nullptr, 10);
    std::vector<std::string> func = {};
    for (int i = 4; i < argc; ++i) {
        func.emplace_back(argv[i]);
    }
    numbers::complex sum = 0;
    const double alpha = 2 * std::numbers::pi / N;
    for (int i = 0; i < N; ++i) {
        numbers::complex z = C + R * numbers::complex(cos(alpha * i), sin(alpha * i));
        sum += numbers::eval(func, z) * R * alpha;
    }
    std::cout << sum.to_string() << std::endl;
}

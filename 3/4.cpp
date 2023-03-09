#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
#include <cmath>
#include <vector>
#include <string>

int
main(int argc, char **argv)
{
    numbers::complex C(argv[1]);
    double R = strtod(argv[2], nullptr);
    int N = (int) strtol(argv[3], nullptr, 10);
    std::vector<std::string> func = {};
    for (int i = 4; i < argc; ++i) {
        func.emplace_back(argv[i]);
    }
    numbers::complex sum = 0;
    for (int i = 0; i < N; ++i) {
        double alpha = 2 * std::numbers::pi / N;
        numbers::complex z = C + R * numbers::complex(cos(alpha * i + alpha / 2), sin(alpha * i + alpha / 2));
        sum += numbers::eval(func, z) * fabs(R * alpha);
    }
    std::cout << sum.to_string() << std::endl;
}

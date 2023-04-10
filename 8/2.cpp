#include <iostream>

int64_t
func(int64_t a, int64_t b, int64_t k)
{
    if (!k) {
        throw a + b;
    } else if (b == 1) {
        throw a;
    } else {
        int tmp;
        try {
            tmp = func(a, b - 1, k);
        } catch (int64_t value) {
            tmp = value;
        }
        throw func(a, tmp, k - 1);
    }
}

int
main()
{
    int64_t a, b, k;
    while (std::cin >> a >> b >> k) {
        int64_t res;
        try {
            res = func(a, b, k);
        } catch (int64_t value) {
            res = value;
        }
        std::cout << res << std::endl;
    }
}

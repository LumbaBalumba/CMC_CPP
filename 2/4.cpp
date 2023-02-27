#include <iostream>

using std::cin, std::cout, std::hex;

int
main()
{
    constexpr char spec_symb = '#';
    char symbol = 0, tmp = '\0';
    int count = 0;
    while (cin.get(symbol)) {
        if (symbol == tmp) {
            ++count;
        } else {
            if (count > 4 || tmp == spec_symb) {
                cout << spec_symb << tmp << hex << count << spec_symb;
            } else {
                for (ssize_t i = 0; i < count; ++i) {
                    cout << tmp;
                }
            }
            tmp = symbol;
            count = 1;
        }
    }
    if (count > 4 || symbol == spec_symb) {
        cout << spec_symb << tmp << hex << count << spec_symb;
    } else {
        for (ssize_t i = 0; i < count; ++i) {
            cout << symbol;
        }
    }
}
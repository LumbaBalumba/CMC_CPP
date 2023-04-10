#include <iostream>

using namespace std;

class S
{
    int value{};
    bool valid;

public:
    S()
    {
        if (cin >> value) {
            valid = true;
        } else {
            valid = false;
        }
    }

    S(S &&other) noexcept
    {
        int v;
        cin >> v;
        value = other.value + v;
        valid = true;
        other.valid = false;
    }

    explicit operator bool() const
    {
        return bool(cin);
    }

    ~S()
    {
        if (valid) {
            cout << value << endl;
        }
    }
};


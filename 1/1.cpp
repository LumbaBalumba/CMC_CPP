class Sum
{
    long long value;

public:
    Sum() = default;

    Sum(long long a, long long b)
    {
        value = a + b;
    }

    Sum(long long a, Sum b)
    {
        value = a + b.value;
    }

    Sum(Sum a, long long b)
    {
        value = a.value + b;
    }

    [[nodiscard]] long long
    get() const
    {
        return value;
    }
};
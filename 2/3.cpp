class C
{
    double d;
public:

    C() = default;

    C(double value) : d(value)
    {}

    C(const C &obj1, const C &obj2) : d(obj1.d + obj2.d)
    {

    }

    C
    operator+(int n) const
    {
        return { d + n };
    }

    C &
    operator++()
    {
        d += 1;
        return *this;
    }

    int
    operator~() const
    {
        return (int) d;
    }

    friend C
    operator+(int a, const C &b)
    {
        return { a + b.d };
    }

    friend int
    operator*(C a, C b[2])
    {
        return (int) a.d + b[0].d;
    }

    C
    operator&() const
    {
        return *this;
    }
};
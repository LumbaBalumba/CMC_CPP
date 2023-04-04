class Figure
{
public:
    virtual ~Figure() = default;

    virtual double
    get_square() const
    {
        return 0;
    }
};
class Figure
{
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual double
    get_square() const
    {
        return 0;
    }
};
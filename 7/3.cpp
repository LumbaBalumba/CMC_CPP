#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <algorithm>
#include <cmath>

class Factory
{
    std::map<char, std::function<std::unique_ptr<Figure>(std::string)>> figures{
            { 'R', [](std::string s) {
                return std::unique_ptr<Figure>(Rectangle::make(s));
            }
            },
            { 'S', [](std::string s) {
                return std::unique_ptr<Figure>(Square::make(s));
            }
            },
            { 'C', [](std::string s) {
                return std::unique_ptr<Figure>(Circle::make(s));
            }
            }
    };

    Factory() = default;

public:
    static Factory
    factory_instance()
    {
        static Factory obj;
        return obj;
    }

    std::unique_ptr<Figure>
    make_fig(std::string s)
    {
        std::stringstream ss(s);
        char type;
        ss >> type;
        std::getline(ss, s);
        return figures[type](s);
    }
};

int
main()
{
    Factory fact = Factory::factory_instance();
    std::vector<std::unique_ptr<Figure>> figures;
    std::string s;
    while (!getline(std::cin, s).eof()) {
        figures.push_back(fact.make_fig(s));
    }
    std::stable_sort(figures.begin(), figures.end(),
                     [](const std::unique_ptr<Figure> &f1, const std::unique_ptr<Figure> &f2) {
                         return f1->get_square() < f2->get_square();
                     });
    for (auto &f: figures) {
        std::cout << f->to_string() << std::endl;
    }
    return 0;
}
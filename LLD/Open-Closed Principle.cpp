/*It states that the system should be open to extension (ex by inheritence) and closed to modification.*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product *> by_color(vector<Product *> items, Color color)
    {
        vector<Product *> result;
        for (auto &i : items)
        {
            if (i->color == color)
                result.push_back(i);
        }

        return result;
    }

    /*What if now we want to filter by size or filter by size and color?
    We have to modify the existing structure which is already tested to add new feature
    which is not recommended.
    Below is the filters for size and color which is not recommended.*/

    vector<Product *> by_size(vector<Product *> items, Size size)
    {
        vector<Product *> result;
        for (auto &i : items)
        {
            if (i->size == size)
                result.push_back(i);
        }

        return result;
    }

    vector<Product *> by_color_and_size(vector<Product *> items, Color color, Size size)
    {
        vector<Product *> result;
        for (auto &i : items)
        {
            if (i->color == color && i->size == size)
                result.push_back(i);
        }

        return result;
    }
};

/*Below is the implementation of inheritence of template class instead of keep modifying existing class.
It defines templates for specification and filter which can be used for colorspecification or
size specification as required without changing any existing classes.*/

template <typename T>
struct Specification
{
    virtual bool is_satisfied(T *item) = 0;

    // Alternate implementation of AndSpecification.
    // AndSpecification<T> operator&&(Specification<T> &&other)
    // {
    //     return AndSpecification<T>(*this, other);
    // }
};
template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec)
        override
    {

        vector<Product *> result;

        for (auto &item : items)
            if (spec.is_satisfied(item))
                result.push_back(item);

        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    ColorSpecification(Color color) : color(color) {};

    bool is_satisfied(Product *item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    SizeSpecification(Size size) : size(size) {};

    bool is_satisfied(Product *item) override
    {
        return item->size == size;
    }
};

struct ColorAndSizeSpecification : Specification<Product>
{
    Size size;
    Color color;

    ColorAndSizeSpecification(Size size, Color color) : size(size), color(color) {};

    bool is_satisfied(Product *item) override
    {
        return item->size == size && item->color == color;
    }
};

// Alternate approach by combining specification

template <typename T>
struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {};

    bool is_satisfied(T *item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main()
{

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};
    // Not best practice.
    //  ProductFilter pf;

    // auto green_things = pf.by_color(items, Color::green);

    // for (auto &item : green_things)
    //     cout << item->name << " is green\n";

    // Best practice of open close principle.
    BetterFilter bf;
    ColorSpecification green(Color::green);

    for (auto &item : bf.filter(items, green))
        cout << item->name << " is green\n";

    SizeSpecification large(Size::large);

    for (auto &item : bf.filter(items, large))
        cout << item->name << " is large\n";

    ColorAndSizeSpecification green_large(Size::large, Color::green);

    for (auto &item : bf.filter(items, green_large))
        cout << item->name << " is green and large\n";

    // Alternate approach by combining specification

    AndSpecification<Product> green_and_large(green, large);

    for (auto &item : bf.filter(items, green_and_large))
        cout << item->name << " is green and large\n";

    // Other Alternate approach of combination

    // auto spec = ColorSpecification(Color::green) && SizeSpecification(Size::small);

    // for (auto &item : bf.filter(items, spec))
    //     cout << item->name << " is green and small\n";

    getchar();
    return 0;
}
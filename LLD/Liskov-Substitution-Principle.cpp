// Subtypes should be immediately substitutible for their base types

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

// Here Rectangle is base type
class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const
    {
        return width;
    }

    virtual void setWidth(int width)
    {
        this->width = width;
    }

    int getHeight() const
    {
        return height;
    }

    virtual void setHeight(int height)
    {
        this->height = height;
    }

    int area() const { return width * height; }
};

void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout << "Expected area = " << (w * 10)
         << ", got " << r.area() << endl;
}

// Here Square is a subtype of rectangle
class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}

    // Here setWidth and setHeight method are modified which leads to unexpected result when substituting
    // in place of base class
    void setWidth(int width) override
    {
        this->width = this->height = width;
    }

    void setHeight(int height) override
    {
        this->height = this->width = height;
    }
};

int main()
{
    Rectangle r{3, 4};
    // this process is correct.
    process(r);
    Square sq{5};
    // this process is incorrect since subclass square was modified which breaks Liskov substitution principle.
    process(sq);
    getchar();
}
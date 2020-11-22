#include "Rectangle.h"

Rectangle::Rectangle(const double a, const double b) : a(a), b(b) {}

const double Rectangle::circumference() const
{
    return 2 * (a + b);
}

const double Rectangle::area() const
{
    return a * b;
}


const double Rectangle::getA() const { return a; }
const double Rectangle::getB() const { return b; }
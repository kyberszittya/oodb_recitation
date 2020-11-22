#pragma once

#include <iostream>

class Rectangle
{
private:
    const double a; // Az oldalak példányosítást követõen nem változtahatók meg
    const double b;
public:
    Rectangle(const double a, const double b); // Konstans adattagok esetén adunk értéket az attribútumoknak

    // Kerület számítása
    const double circumference() const;

    // Terület számítása
    const double area() const;

    // Setter függvényeknek esetünkben (a két konstans attribútumra) nincs lehetõsége

    // Getter függvények
    const double getA() const;
    const double getB() const;
};
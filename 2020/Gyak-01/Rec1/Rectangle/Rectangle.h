#pragma once

#include <iostream>

class Rectangle
{
private:
    const double a; // Az oldalak p�ld�nyos�t�st k�vet�en nem v�ltoztahat�k meg
    const double b;
public:
    Rectangle(const double a, const double b); // Konstans adattagok eset�n adunk �rt�ket az attrib�tumoknak

    // Ker�let sz�m�t�sa
    const double circumference() const;

    // Ter�let sz�m�t�sa
    const double area() const;

    // Setter f�ggv�nyeknek eset�nkben (a k�t konstans attrib�tumra) nincs lehet�s�ge

    // Getter f�ggv�nyek
    const double getA() const;
    const double getB() const;
};
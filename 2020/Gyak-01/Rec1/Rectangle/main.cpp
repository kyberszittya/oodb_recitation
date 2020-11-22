// Rectangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Rectangle.h"

int main(int argc, char** argv)
{
    // Értékek bekérése
    double a, b;
    std::cout << "Adjon meg egy téglalapot" << std::endl;
    std::cout << "A oldal: ";
    std::cin >> a;
    std::cout << "B oldal: ";
    std::cin >> b;
    // Téglalap példányosítása
    Rectangle rect(a, b);
    // Téglalap kiírása
    std::cout << "Téglalap: " << std::endl;
    std::cout << "A: " << rect.getA() << " B: " << rect.getB() << std::endl;
    // Kerület/terület kiírása
    std::cout << "Kerület: " << rect.circumference() << std::endl;
    std::cout << "Terület: " << rect.area() << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

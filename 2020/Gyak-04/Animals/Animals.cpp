// Animals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Animal.h"
// Ez kell a memóriaszemét ellenőrzéséhez (Visual Studio)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	// Memóriaszemét ellenőrzése (Visual Studio)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Animal* a1 = new Dog("Bator", 12.0, 15);
	Animal* a2 = new Dackel("Tacsi", 10, 14);
	Animal* a3 = new Cat("Cirmi", 5.0, 10);
	// Tömb az állatoknak
	std::vector<Animal*> animals;
	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(a3);
	for (const auto& a : animals)
	{
		std::cout << *a << std::endl;
	}
	// Move cat
	std::cout << "Move cat" << std::endl;
	a3->move();
	std::cout << "Move dog" << std::endl;
	a1->move();
	// Animals speaking
	std::cout << "Dog speaks: " << std::endl;
	a1->speak();
	std::cout << "Cat speaks: " << std::endl;	
	a2->speak();
	std::cout << "Dog chases cat" << std::endl;
	Dog* dog = dynamic_cast<Dog*>(a1);
	Cat* cat = dynamic_cast<Cat*>(a3);
	if (dog != nullptr && cat != nullptr)
	{
		dog->chase(cat);
	}
	// Delete all items
	for (auto v : animals)
	{
		delete v;
	}
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

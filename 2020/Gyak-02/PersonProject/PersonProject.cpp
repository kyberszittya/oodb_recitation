// PersonProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <iostream>

#include "Person.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | 
		_CRTDBG_LEAK_CHECK_DF);
	// Stack-en foglalunk le személyt
	Person p("Kis", "János", 23);
    std::cout << p.getFirstName() << 
		" " << p.getLastName() 
		<< " " << p.getAge() << std::endl; 
	// Heap-en foglalunk le személyt
	Person *p0 = new Person(
		"Kovács", "István", 45
	);
	std::cout <<
		p0->getFirstName() << " " <<
		p0->getLastName() << " " <<
		p0->getAge() << std::endl;
	delete p0;
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

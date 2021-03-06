// TemplateBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Person.h"
#include "PizzaRendeles.h"
#include "LinkedList.h"

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main()
{
#ifdef WIN32
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	Person janos("Janos", "Kovacs", 1970, Gender::MALE);
	Person miklos("Miklos", "Kis", 1983, Gender::MALE);
	std::cout << "STD OUTPUT " << janos << std::endl;
	PizzaRendeles capricciosa(&janos, "capricciosa");
	PizzaRendeles calzone(&miklos, "calzone");
	//capricciosa.print();
	//calzone.print();
	capricciosa = calzone;
	//capricciosa.print();
	PizzaRendeles calzone2(calzone);
	//calzone2.print();

	LinkedList<Person> list;
	list.addNext(&janos);
	list.addNext(&miklos);
	list.print();
	LinkedList<PizzaRendeles> list_pizzarendeles;
	list_pizzarendeles.addNext(&capricciosa);
	list_pizzarendeles.addNext(&calzone);
	list_pizzarendeles.print();
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

// SoldierWeapon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Soldier.h"

int main()
{
	Soldier s0("Kis Pista", 40);
	Weapon szuperfegyver("szuperfegyver",40);
	Soldier s1("Hulk", 50);
	s0.print(); 
	s0.addWeapon(&szuperfegyver);
	s1.print();
	s0.hit(s1);
	s0.hit(s1);
	s1.print();
	s0.heal(s1);
	s1.print();
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

#pragma once

#include "Person.h"

#include <iostream>

class PizzaRendeles
{
private:
	Person* person;
	std::string pizza_nev;
public:
	
	PizzaRendeles(Person* person, const std::string pizza_nev):
		person(person), pizza_nev(pizza_nev)
	{

	}

	PizzaRendeles(const PizzaRendeles& other)
	{
		person = other.person;
		pizza_nev = other.pizza_nev;
	}

	PizzaRendeles& operator=(const PizzaRendeles& other)
	{
		person = other.person;
		pizza_nev = other.pizza_nev;
		return *this;
	}

	void print()
	{
		std::cout << person->getFirstName() << " " <<
			person->getLastName() << ": " << pizza_nev << std::endl;
	}

	friend std::ostream& operator<<(std::ostream&, PizzaRendeles);
};

std::ostream& operator<<(std::ostream& lhs, PizzaRendeles pr)
{
	lhs << pr.person->getFirstName() << " " << pr.pizza_nev;
	return lhs;
}
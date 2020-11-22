#include "Person.h"

#include <iostream>

Person::Person(const std::string first_name,
	const std::string last_name,
	unsigned int age) :
	first_name(first_name),
	last_name(last_name),
	age(age)
{
	std::cout << "CTOR Person " << first_name << std::endl;
}

Person::~Person()
{
	std::cout << "DTOR Person " << first_name << std::endl;
}

void Person::oregit(unsigned int age)
{
	this->age += age;
}

std::string Person::getFirstName()
{
	return first_name;
}

std::string Person::getLastName()
{
	return last_name;
}

unsigned int Person::getAge()
{
	return age;
}
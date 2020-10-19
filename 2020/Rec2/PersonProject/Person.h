#pragma once

#include <string>

class Person
{
private:
	const std::string first_name;
	const std::string last_name;
	unsigned int age;
public:
	Person(const std::string first_name, const std::string last_name,
		unsigned int age);

	~Person();

	void oregit(unsigned int age);
	
	std::string getFirstName();
	std::string getLastName();
	unsigned int getAge();
};
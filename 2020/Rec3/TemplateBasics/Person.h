#pragma once

#include <string>

enum class Gender
{
	MALE, FEMALE
};

class Person
{
private:
	const std::string first_name;
	const std::string last_name;
	const unsigned int birth_year;
	const Gender gender;
public:
	Person(const std::string first_name,
		const std::string last_name,
		const unsigned int birth_year,
		const Gender gender): 
		first_name(first_name), last_name(last_name),
		birth_year(birth_year), gender(gender)
	{

	}

	Person(const Person& person) = delete;
	Person& operator=(const Person& person) = delete;

	const std::string getFirstName() const
	{
		return first_name;
	}

	const std::string getLastName() const
	{
		return last_name;
	}

	const unsigned int getBirthYear() const
	{
		return birth_year;
	}

	const Gender getGender() const {
		return gender;
	}

	friend std::ostream& operator<< (std::ostream& lhs, Person& p);
	
};

std::ostream& operator<< (std::ostream& lhs, Person& p)
{
	lhs << p.first_name << " " << 
		p.last_name << " " << p.birth_year;
	return lhs;
}
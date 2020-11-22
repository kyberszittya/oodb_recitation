#pragma once

#include <iostream>
#include <string>

class Animal
{
private:
	double weight;
	double height;
	const std::string name;
public:
	Animal(const std::string name, double weight, double height) :
		name(name), weight(weight), height(height){}
	virtual ~Animal() {}
	virtual void speak() = 0;
	virtual void move() { std::cout << "JUMP" << std::endl; }
	void print() { std::cout << name << ", W:" << weight << " "	<< "H:" << height << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, const Animal& o);
};

std::ostream& operator<<(std::ostream& os, const Animal& o)
{
	os << o.name << " " << o.height << " " << o.weight;
	return os;
}

class Cat: public Animal
{
public:
	Cat(const std::string name, double weight, double height) : 
		Animal(name, weight, height) {}
	virtual void move() override { std::cout << "FALL" << std::endl; }
	virtual void speak() override {	std::cout << "MEOW" << std::endl;}
	void roll()	{	std::cout << "ROLLIN'" << std::endl;}
};

class Dog : public Animal
{
public:
	Dog(const std::string name, double weight, double height) : 
		Animal(name, weight, height) {}
	virtual void speak() override final {	
		std::cout << "BARK" << std::endl;	}
	void chase(Cat* cat){	cat->speak();	}
};

class Dackel : public Dog
{
public:
	Dackel(const std::string name, double weight, double height) :
		Dog(name, weight, height) {}
};
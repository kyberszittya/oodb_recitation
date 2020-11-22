#pragma once

#include <string>

class Weapon
{
private:
	const std::string name;
	unsigned int damage;
	unsigned int ammo;
public:
	Weapon(
		const std::string name,
		unsigned int damage=30,
		unsigned int ammo=7);
	void shoot();

	std::string getName() const;

	unsigned int getDamage();
};
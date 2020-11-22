#include "Weapon.h"

Weapon::Weapon(
	const std::string name,
	unsigned int damage,
	unsigned int ammo) :
	name(name),
	damage(damage), ammo(ammo)
{}

void Weapon::shoot()
{
	ammo--;
}

unsigned int Weapon::getDamage()
{
	return damage;
}

std::string Weapon::getName() const
{
	return name;
}
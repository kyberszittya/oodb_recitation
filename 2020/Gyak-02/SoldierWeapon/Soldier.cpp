#include "Soldier.h"

#include <iostream>

Soldier::Soldier(
	const std::string name,
	unsigned int hp):
	name(name), hp(hp), max_hp(hp)
{
	std::cout << "CTOR Soldier " << 
		name << std::endl;
}

Soldier::~Soldier()
{
	std::cout << "DTOR Soldier " << 
		name << std::endl;
}

std::string Soldier::getName()
{
	return name;
}

unsigned int Soldier::getHp()
{
	return hp;
}

void Soldier::addHp(unsigned int hp){
	if (this->hp > 0){
		this->hp += hp;
		if (this->hp > max_hp){
			hp = max_hp;
		}
	}
	else{
		std::cout << "Meghaltam, nem támadhatok fel" << std::endl;
	}
}

void Soldier::hit(Soldier& other)
{
	std::cout << "MEGSEBZEM: " << other.getName() << std::endl;
	if (this->weapon!=nullptr){
		other.removeHp(weapon->getDamage());
	}
}
void Soldier::removeHp(unsigned int diff_hp)
{
	if (this->hp <= diff_hp){
		this->hp = 0;
	}
	else{
		this->hp -= diff_hp;
	}
}

void Soldier::addWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}
void Soldier::heal(Soldier& other)
{
	std::cout << "MEGGYOGYITOM: " << other.getName() << std::endl;
	other.addHp(HEAL_DIFF);
	
}

void Soldier::print()
{
	std::cout << "Nevem: " << 
		name << std::endl;
	std::cout << "HP:" << hp << std::endl;
	if (weapon != nullptr)
	{
		std::cout << "Fegyverem neve: " << weapon->getName() << std::endl;
	}
}
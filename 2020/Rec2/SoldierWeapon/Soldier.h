#pragma once

#include <string>

#include "Weapon.h"

constexpr unsigned int HEAL_DIFF = 20;

class Soldier
{
private:
	const std::string name;
	unsigned int hp;
	const unsigned int max_hp;
	mutable Weapon* weapon;
public:
	Soldier(const std::string name, 
		unsigned int hp);
	~Soldier();
	std::string getName();
	unsigned int getHp();
	// Use it to heal soldier
	void addHp(unsigned int hp);
	// Sebzéshez
	void removeHp(unsigned int hp);
	// Hozzáadjuk egy fegyvernek a mutatóját
	void addWeapon(Weapon* weapon);
	// Katona lesebzése egy fegyverrel
	void hit(Soldier& other);
	// Katona gyógyítása
	void heal(Soldier& other);
	// Katona tulajdonságainak kiírása
	void print();
};
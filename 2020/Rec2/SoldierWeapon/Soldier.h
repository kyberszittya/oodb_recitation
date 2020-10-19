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
	// Sebz�shez
	void removeHp(unsigned int hp);
	// Hozz�adjuk egy fegyvernek a mutat�j�t
	void addWeapon(Weapon* weapon);
	// Katona lesebz�se egy fegyverrel
	void hit(Soldier& other);
	// Katona gy�gy�t�sa
	void heal(Soldier& other);
	// Katona tulajdons�gainak ki�r�sa
	void print();
};
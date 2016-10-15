#include "Weapon.h"

#include <time.h>
#include <iostream>

Weapon::Weapon(const std::string& name, float value, int size, int upperDamageRange, int lowerDamageName, float critProb) :
	Item(name, value, size), m_upperDamageRange(upperDamageRange), m_lowerDamageRange(lowerDamageName), m_critProb(critProb)
{
	srand(time(NULL));
	m_type = Type::kWeapon;
}

void Weapon::Use(int& health)
{
	// Damage to deal
	int damage = rand() % m_upperDamageRange + m_lowerDamageRange;
	damage = rand() % 1 + 100 <= m_critProb * 100 ? damage : damage * CRIT_X;

	health -= damage;
	std::cout << damage << " damage was done!" << std::endl;
}

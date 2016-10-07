#include "Weapon.h"

#include <time.h>

Weapon::Weapon(const std::string& name, float value, int size, int upperDamageRange, int lowerDamageName, float critProb) :
	Item(name, value, size), m_upperDamageRange(upperDamageRange), m_lowerDamageRange(lowerDamageName), m_critProb(critProb)
{
	srand(time(NULL));
}

void Weapon::Use(int& health)
{
	health -= rand() % m_upperDamageRange + m_lowerDamageRange;
}

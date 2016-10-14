#include "Weapon.h"

#include <time.h>

Weapon::Weapon(const std::string& name, float value, int size, int upperDamageRange, int lowerDamageName, float critProb) :
	Item(name, value, size), m_upperDamageRange(upperDamageRange), m_lowerDamageRange(lowerDamageName), m_critProb(critProb)
{
	srand(time(NULL));
	m_type = Type::kWeapon;
}

void Weapon::Use(int& health)
{
	int damage = rand() % m_upperDamageRange + m_lowerDamageRange;
	health -= rand() % 1 + 100 <= m_critProb * 100 ? damage : damage * CRIT_X;
}

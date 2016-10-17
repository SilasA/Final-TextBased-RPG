#include "Weapon.h"
#include "Utilities\Logger.h"

#include <time.h>
#include <iostream>
#include <iomanip>

Weapon::Weapon(const std::string& name, int value, int size, int upperDamageRange, int lowerDamageName, float critProb) :
	Item(name, value, size), m_upperDamageRange(upperDamageRange), m_lowerDamageRange(lowerDamageName), m_critProb(critProb)
{
	srand(time(NULL));
	m_type = Type::kWeapon;
	m_effect = std::to_string(m_lowerDamageRange) + "/" +
		std::to_string(m_upperDamageRange) + "/" +
		std::to_string(int(m_critProb * 100));
}

void Weapon::Use(int& health)
{
	// Damage to deal
	int damage = (rand() % (m_upperDamageRange - m_lowerDamageRange) + m_lowerDamageRange);
	int damageC = (rand() % 100 + 1) >= m_critProb * 100 ? damage : damage * CRIT_X;

	health -= damageC;
	std::cout << damageC << " damage was done!" << std::endl;
	
	Logger::WriteLog(Name(), Name() + " did " + std::to_string(damageC) + " damage" + (damageC != damage ? "(CRIT)" : ""), "log");
}
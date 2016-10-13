#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

#include <string>

#define CRIT_X 2

// Represents a weapon
class Weapon : public Item
{
private:
	int m_upperDamageRange, 
		m_lowerDamageRange, 
		m_critProb;

public:
	Weapon(const std::string& name, float value, int size, int upperDamageRange, int lowerDamageName, float critProb);

	virtual void Use(int& health) override;
};

#endif // WEAPON_H

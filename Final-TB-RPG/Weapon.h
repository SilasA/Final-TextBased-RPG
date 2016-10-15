#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

#include <string>

#define CRIT_X 2

// Represents a weapon
class Weapon : public Item
{
private:
	int m_upperDamageRange,	// Maximum damage the weapon can do
		m_lowerDamageRange; // Minimum damage the weapon can do
	float m_critProb;		// Probability to inflict critical damage

public:
	// Construct max damage, min damage, and crit probability
	// See Item()
	Weapon(const std::string& name, float value, int size, int upperDamageRange, int lowerDamageName, float critProb);

	// Inflicts damage to health based on weapon properties
	virtual void Use(int& health) override;
};

#endif // WEAPON_H

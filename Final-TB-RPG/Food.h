#ifndef FOOD_H
#define FOOD_H

#include "Item.h"

#include <string>

// Represents a food item
class Food : public Item
{
private:
	// How much health the food adds
	int m_nutritionValue;

public:
	// Constructs nutrition value
	// See Item()
	Food(const std::string& name, int value, int size, int nutritionValue);

	// Adds nutrition value to health
	virtual void Use(int& health) override;
};

#endif // FOOD_H

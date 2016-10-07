#ifndef FOOD_H
#define FOOD_H

#include "Item.h"

#include <string>

// Represents a food item
class Food : public Item
{
private:
	int m_nutritionValue;

public:
	Food(const std::string& name, float value, int size, int nutritionValue);

	virtual void Use(int& health) override;
};


#endif // FOOD_H

#include "Food.h"

Food::Food(const std::string& name, float value, int size, int nutritionValue) :
	Item(name, value, size), m_nutritionValue(nutritionValue)
{
}

void Food::Use(int& health)
{
	health += m_nutritionValue;
}

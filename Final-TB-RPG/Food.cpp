#include "Food.h"

#include <iostream>

Food::Food(const std::string& name, float value, int size, int nutritionValue) :
	Item(name, value, size), m_nutritionValue(nutritionValue)
{
	m_type = Type::kFood;
}

void Food::Use(int& health)
{
	health += m_nutritionValue;
	std::cout << m_nutritionValue << " hps were restored." << std::endl;
}

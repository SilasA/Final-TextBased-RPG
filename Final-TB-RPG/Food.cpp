#include "Food.h"
#include "Utilities\Logger.h"

#include <iostream>

Food::Food(const std::string& name, int value, int size, int nutritionValue) :
	Item(name, value, size), m_nutritionValue(nutritionValue)
{
	m_type = Type::kFood;
	m_effect = std::to_string(m_nutritionValue);
}

void Food::Use(int& health)
{
	if (m_used) return;
	health += m_nutritionValue;
	std::cout << m_nutritionValue << " hp was restored." << std::endl;
	Logger::WriteLog(Name(), Name() + " healed " + std::to_string(m_nutritionValue) + " hp", "log");
	m_used = true;
}

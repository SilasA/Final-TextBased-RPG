#ifndef ITEM_H
#define ITEM_H

#include <string>

// Represents the base buyable item in the game
class Item
{
private:
	std::string m_name;
	float m_value;

	int m_unitSize;

public:
	Item(const std::string& name, float value, int unitSize) :
		m_name(name), m_value(value), m_unitSize(unitSize)
	{

	}

	virtual void Use(int& health)
	{
	}

	virtual void Buy(float& monis)
	{
		monis -= m_value;
	}

	inline std::string Name() { return m_name; }
	inline float Value() { return m_value; }
	inline int UnitSize() { return m_unitSize; }
};

#endif // ITEM_H
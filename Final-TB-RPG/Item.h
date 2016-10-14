#ifndef ITEM_H
#define ITEM_H

#include <string>

// Represents the base buyable item in the game
class Item
{
public:
	enum class Type
	{
		kWeapon,
		kFood,
		kItem
	};

private:

	std::string m_name;
	float m_value;

	int m_unitSize;

protected:
	Type m_type;

public:
	Item(const std::string& name, float value, int unitSize) :
		m_name(name), m_value(value), m_unitSize(unitSize)
	{
		m_type = Type::kItem;
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
	inline bool IsWeapon() { return m_type == Type::kWeapon; }
	inline bool IsFood() { return m_type == Type::kFood; }
};

#endif // ITEM_H
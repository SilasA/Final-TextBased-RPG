#ifndef ITEM_H
#define ITEM_H

#include <string>

// Represents the base buyable item in the game
class Item
{
public:
	// Type of item
	enum class Type
	{
		kWeapon,
		kFood,
		kItem
	};

private:
	// Name of item
	std::string m_name;
	// Value in currency
	int m_value;

	// Space item takes up in inventory
	int m_unitSize;

protected:
	// Item type
	Type m_type;

	std::string m_effect;

	bool m_used = false;

public:
	// Constructs the name, currency, and space of the item
	Item(const std::string& name, int value, int unitSize) :
		m_name(name), m_value(value), m_unitSize(unitSize)
	{
		m_type = Type::kItem;
	}

	// Using the item modifies health
	virtual void Use(int& health)
	{
		
	}

	// Buying the item takes its currency value away from monis
	void Buy(int& monis)
	{
		monis -= m_value;
	}

	// Accessors
	inline std::string Name() { return m_name; }
	inline int Value() { return m_value; }
	inline int UnitSize() { return m_unitSize; }
	inline bool IsWeapon() { return m_type == Type::kWeapon; }
	inline bool IsFood() { return m_type == Type::kFood; }
	inline std::string Effect() { return m_effect; }
	inline bool IsUsed() { return m_used; }

	// Operator
	inline bool operator==(const Item& item) { return this->m_name == item.m_name; }
};

#endif // ITEM_H
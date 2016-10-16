#ifndef INVENTORY_H
#define INVENTORY_H

#include "SubSystem.h"
#include "Weapon.h"
#include "Food.h"

#include <vector>
#include <string>

// Inventory of a player
class Inventory
{
private:
	// List of Items serving as an 'inventory'
	std::vector<Weapon> m_weapons;
	std::vector<Food> m_foods;
	int m_capacity;					// Max inventory size
	int m_currentSize;				// Current size of inventory; not m_inventory.size()

	// Checks if the inventory is full
	inline bool is_full() { return m_currentSize >= m_capacity; }
	// Checks how many spaces are available in the players inventory
	inline int space_available() { return m_currentSize - m_capacity - 1; }

	// Updates m_currentSize
	void calc_current_size();
	int calc_current_size(std::vector<Item>& container);

public:
	// Creates an empty inventory with specified capacity
	Inventory(int capacity);
	// Creates an inventory with specified inventory
	// Assumes capacity is calculated size of inventory
	Inventory(std::vector<Weapon>& weapons, std::vector<Food>& foods);

	// Add an item
	void Add(Weapon* item);
	void Add(Food* item);
	void Add(Inventory& inv);

	void Remove(Item* item);

	// Changes the capacity of the inventory
	// Will not change capacity if the new capacity is smaller than the current size
	bool ChangeCapacity(int capacity);

	// Gets a list of pointers to the respective Items
	inline std::vector<Weapon>& GetWeapons() { return m_weapons; }
	inline std::vector<Food>& GetFoods() { return m_foods; }

	// Returns the Item with the specified name or nullptr if it does not exist
	Item* FindItem(std::string& name);

	typedef std::vector<Weapon>::iterator WIt; // Shorthand iterator
	typedef std::vector<Food>::iterator FIt; // Shorthand iterator
};

#endif // INVENTORY_H
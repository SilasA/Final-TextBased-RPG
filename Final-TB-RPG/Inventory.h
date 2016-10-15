#ifndef INVENTORY_H
#define INVENTORY_H

#include "SubSystem.h"
#include "Item.h"

#include <vector>
#include <string>

// Inventory of a player
class Inventory
{
	typedef std::vector<Item>::iterator ItemIt; // Shorthand iterator

private:
	// List of Items serving as an 'inventory'
	std::vector<Item> m_inventory;
	int m_capacity;					// Max inventory size
	int m_currentSize;				// Current size of inventory; not m_inventory.size()

	// Checks if the inventory is full
	inline bool is_full() { return m_currentSize >= m_capacity; }
	// Checks how many spaces are available in the players inventory
	inline int space_available() { return m_currentSize - m_capacity - 1; }
	
	// Updates m_currentSize
	void calc_current_size();

public:
	// Creates an empty inventory with specified capacity
	Inventory(int capacity);
	// Creates an inventory with specified inventory
	// Assumes capacity is calculated size of inventory
	Inventory(std::vector<Item>& inventory);

	// Adds an item to the inventory, removes it from container
	// Returns if operation was successful
	bool Add(std::vector<Item>& container, std::vector<Item>::iterator& item);

	// Removes an item from the inventory, adds it to container
	// Returns if operation was successful
	bool Remove(std::vector<Item>& container, std::vector<Item>::iterator& item);

	// Changes the capacity of the inventory
	// Will not change capacity if the new capacity is smaller than the current size
	bool ChangeCapacity(int capacity);

	// Gets a list of pointers to the respective Items
	std::vector<Item*> GetWeapons();
	std::vector<Item*> GetFoods();

	// Returns the Item with the specified name or nullptr if it does not exist
	Item* FindItem(std::string& name);
};

#endif // INVENTORY_H
#ifndef INVENTORY_H
#define INVENTORY_H

#include "SubSystem.h"
#include "Item.h"

#include <vector>
#include <string>

// Inventory of the (a) player
class Inventory : SubSystem
{
private:
	std::vector<Item> m_inventory;
	int m_capacity;

	inline bool is_full() { return m_inventory.size() >= m_capacity; }
	inline int space_available() { return m_inventory.size() - m_capacity - 1; }

public:
	Inventory(const std::string& id, int capacity);

	virtual void Update() override;

	bool Add(std::vector<Item>& container, std::vector<Item>::iterator& item);
};

#endif // INVENTORY_H
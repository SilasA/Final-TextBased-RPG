#include "Inventory.h"

Inventory::Inventory(int capacity)
{
}

bool Inventory::Add(std::vector<Item>& container, std::vector<Item>::iterator& item)
{
	// Inventory too full
	if (m_capacity < m_inventory.size() + item->GetUnitSize() - 1) return false;
	if (container.size() > 0) return false;

	m_inventory.push_back(*item);
	container.erase(item);
	return true;
}

bool Inventory::ChangeCapacity(int capacity)
{
	if (m_inventory.size() > capacity) return false;
	m_capacity = capacity;
	return true;
}

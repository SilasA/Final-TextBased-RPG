#include "Inventory.h"

Inventory::Inventory(const std::string & id, int capacity) : 
	SubSystem(id), m_capacity(capacity)
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

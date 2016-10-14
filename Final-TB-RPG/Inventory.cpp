#include "Inventory.h"


Inventory::Inventory(int capacity) :
	m_capacity(capacity), m_currentSize(0)
{
}

Inventory::Inventory(std::vector<Item>& inventory) :
	m_inventory(inventory)
{
	calc_current_size();
	m_capacity = m_currentSize;
}

void Inventory::calc_current_size()
{
	m_currentSize = 0;
	for (Item& item : m_inventory)
		m_currentSize += item.UnitSize();
}

bool Inventory::Add(std::vector<Item>& container, std::vector<Item>::iterator& item)
{
	// Inventory full
	if (m_capacity < m_currentSize + item->UnitSize()) return false;
	if (container.size() < 0) return false;

	m_inventory.push_back(*item);
	container.erase(item);

	calc_current_size();
	return true;
}

bool Inventory::ChangeCapacity(int capacity)
{
	if (m_inventory.size() > capacity) return false;
	m_capacity = capacity;
	return true;
}

std::vector<Item*> Inventory::GetWeapons()
{
	std::vector<Item*> weaps;
	for (ItemIt it = m_inventory.begin(); it != m_inventory.end(); it++)
		if (it->IsWeapon())
			weaps.push_back(&(*it)); // Not reduntant
	return weaps;
}

std::vector<Item*> Inventory::GetFoods()
{
	return std::vector<Item*>();
}
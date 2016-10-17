#include "Inventory.h"


Inventory::Inventory(int capacity) :
	m_capacity(capacity), m_currentSize(0)
{
}

Inventory::Inventory(std::vector<Weapon>& weapons, std::vector<Food>& foods)
{
	m_weapons = weapons;
	m_foods = foods;
	calc_current_size();
	m_capacity = m_currentSize;
}

void Inventory::calc_current_size()
{
	m_currentSize = 0;
	for (Item& item : m_weapons)
		m_currentSize += item.UnitSize();
	for (Item& item : m_foods)
		m_currentSize += item.UnitSize();
}

int Inventory::calc_current_size(std::vector<Item>& container)
{
	int size = 0;
	for (Item& item : container)
		size += item.UnitSize();
	return size;
}

bool Inventory::Add(Weapon* item)
{
	if (m_currentSize + item->UnitSize() > m_capacity) return false;
	m_weapons.push_back(*item);
	calc_current_size();
	return true;
}

bool Inventory::Add(Food* item)
{
	if (m_currentSize + item->UnitSize() > m_capacity) return false;
	m_foods.push_back(*item);
	calc_current_size();
	return true;
}

bool Inventory::Add(Inventory& inv)
{
	if (m_currentSize + inv.m_currentSize > m_capacity) return false;
	m_foods.insert(m_foods.end(), inv.m_foods.begin(), inv.m_foods.end());
	m_weapons.insert(m_weapons.end(), inv.m_weapons.begin(), inv.m_weapons.end());
	calc_current_size();
	return true;
}

void Inventory::Remove(Item* item)
{
	if (item->IsFood()) m_foods.erase(std::find(m_foods.begin(), m_foods.end(), *item));
	else if (item->IsWeapon()) m_weapons.erase(std::find(m_weapons.begin(), m_weapons.end(), *item));
}


bool Inventory::ChangeCapacity(int capacity)
{
	if (m_currentSize > capacity) return false;
	m_capacity = capacity;
	return true;
}

Item* Inventory::FindItem(std::string& name)
{
	for (WIt it = m_weapons.begin(); it != m_weapons.end(); it++)
		if (it->Name() == name) return &(*it);
	for (FIt it = m_foods.begin(); it != m_foods.end(); it++)
		if (it->Name() == name) return &(*it);
	return nullptr;
}
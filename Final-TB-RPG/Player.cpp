#include "Player.h"

Player::Player(const std::string& id, int invCap, const std::string& name, double monis, int health) :
	SubSystem(id), m_inventory(invCap), m_name(name), m_monis(monis), m_health(health)
{
}

Player::Player(const std::string& id, std::vector<Item>& inventory, const std::string& name, double monis, int health) :
	SubSystem(id), m_inventory(inventory), m_name(name), m_monis(monis), m_health(health)
{
}

bool Player::AddItem(std::vector<Item>& container, std::vector<Item>::iterator& item)
{
	return m_inventory.Add(container, item);
}

bool Player::RemoveItem(std::vector<Item>& container, std::vector<Item>::iterator & item)
{
	return m_inventory.Remove(container, item);
}

bool Player::ChangeItemCapacity(int capacity)
{
	return m_inventory.ChangeCapacity(capacity);
}

int Player::Run()
{

	return 0;
}

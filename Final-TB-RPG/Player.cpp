#include "Player.h"

Player::Player(const std::string& id, int invCap, std::string& name, double monis) :
	SubSystem(id), m_inventory(invCap), m_name(name), m_monis(monis)
{
}

bool Player::AddItem(std::vector<Item>& container, std::vector<Item>::iterator& item)
{
	return m_inventory.Add(container, item);
}

bool Player::ChangeItemCapacity(int capacity)
{
	return m_inventory.ChangeCapacity(capacity);
}

int Player::Update()
{
	return 0;
}
